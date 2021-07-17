#include <thread>
#include <cmath>
#include <cstdint>
#include <cstddef>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <cstdio>
#ifdef __linux
#include <unistd.h>
#include <sys/sysinfo.h>
#include <sys/types.h>
#endif
#include <errno.h>
#include <cassert>

#include "affinity.hpp"
#ifdef __linux

/** for get cpu **/
#if (__GLIBC_MINOR__ < 14 ) && (__GLIBC__ <= 2 )

#ifndef _GNU_SOURCE
#define _GNU_SOURCE 1
#endif

#else

#ifndef _BSD_SOURCE
#define _BSD_SOURCE 1
#endif

#ifndef _SVID_SOURCE
#define _SVID_SOURCE 1
#endif

#endif /** end glibc check **/

#include <sched.h>
#endif /** end if linux **/

#ifdef INJECT_AFFINITY_NAMESPACE
#define INJECTION AFFINITY_NAMESPACE::
#else
#define INJECTION 
#endif

void 
INJECTION affinity::set( const std::size_t desired_core )
{
#ifdef __linux
    /**
     * pin the current thread 
     */
    cpu_set_t   *cpuset( nullptr );
    
    /**
     * FIXME, there's several ways to do this
     * we should probably check which is actually
     * avail on the calling system. 
     */
    const auto n_cores_avail(
        sysconf( _SC_NPROCESSORS_ONLN )
    );
    assert( n_cores_avail > 0 );
    /**
     * get num bytes to alloc
     */
    const auto set_size_bytes( 
        CPU_ALLOC_SIZE( n_cores_avail )
    );
    
    cpuset = CPU_ALLOC( n_cores_avail );

    assert( cpuset != nullptr );

    CPU_ZERO_S( set_size_bytes /** man pages says to use this val **/, cpuset );
    
    CPU_SET_S(  desired_core,
                set_size_bytes,
                cpuset );
    errno = 0;
    /**
     * FIXME: we should iterate over ret value given the 
     * CPUSET of the cpu could be greater than cpu_set_size
     * in some cases, check return for EINVAL.
     */
    if( sched_setaffinity( 0 /* calling thread */,
                           set_size_bytes,
                           cpuset ) != 0 )
    {
        const static auto buff_length( 1000 );
        char buffer[ buff_length ];
        std::memset( buffer, '\0', buff_length );
        const char *str( strerror_r( errno, buffer, buff_length ) );
        std::cerr << "failed to set affinity, desired core( " << desired_core << " )";
        std::cerr << " exited with error ( " << str << " ).\n";
        exit( EXIT_FAILURE );
    }
    
    CPU_FREE( cpuset );
    
    /** wait till we know we're on the right processor **/
    if( sched_yield() != 0 )
    {
        perror( "Failed to yield to wait for core change!\n" );
    }
#else /** not linux **/
#if defined __APPLE__
#warning "No thread pinning for this platform, your results may vary!"
#elif defined _WIN64 || defined _WIN32
#pragma message ( "No thread pinning for this platform, your results may vary!" )
#endif
#endif
    return;
} //end function here, just in case you lost curly brace
#undef INJECTION
