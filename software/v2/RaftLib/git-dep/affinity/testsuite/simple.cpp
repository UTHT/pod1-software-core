#include <cstdlib>
#include <thread>
#include <iostream>
#include <cstring>
#include <cassert> 
#ifndef _GNU_SOURCE
#define _GNU_SOURCE 1
#endif
#include <sched.h>

#include <sys/sysinfo.h>

#include "affinity.hpp"

#ifdef INJECT_AFFINITY_NAMESPACE
#define INJECTION AFFINITY_NAMESPACE::
#else
#define INJECTION 
#endif

void producer( const int avail_cores )
{
    cpu_set_t   cpuset;
    std::memset( &cpuset, 0x0, sizeof( cpu_set_t ) );
    for( auto i = 0; i < avail_cores; i++ )
    {
        INJECTION affinity::set( i );

        if( sched_getaffinity( 0 /** self **/,
                               sizeof( cpu_set_t ), 
                               &cpuset ) == -1 /** error per man **/ )
        {
            perror( "failed to get affinty, test case failed" );
            exit( EXIT_FAILURE );
        }
        if( CPU_ISSET_S( i /** desired core **/, sizeof( cpu_set_t ),  &cpuset ) == 0 /** error code per man page **/ )
        {
            std::cerr << "Failed to set affinity, exiting\n";
            exit( EXIT_FAILURE );
        }
        std::memset( &cpuset, 0x0, sizeof( cpu_set_t ) );
        if( sched_getcpu() != i )
        {
            std::cerr << "running on the wrong CPU\n";
            exit( EXIT_FAILURE );
        }
    }
    return;
}

void consumer( const int avail_cores )
{
    cpu_set_t   cpuset;
    std::memset( &cpuset, 0x0, sizeof( cpu_set_t ) );
    for( auto i = 0; i < avail_cores; i++ )
    {
        INJECTION affinity::set( i );

        if( sched_getaffinity( 0 /** self **/,
                               sizeof( cpu_set_t ), 
                               &cpuset ) == -1 /** error per man **/ )
        {
            perror( "failed to get affinty, test case failed" );
            exit( EXIT_FAILURE );
        }
        if( CPU_ISSET_S( i /** desired core **/, sizeof( cpu_set_t ),  &cpuset ) == 0 /** error code per man page **/ )
        {
            std::cerr << "Failed to set affinity, exiting\n";
            exit( EXIT_FAILURE );
        }
        std::memset( &cpuset, 0x0, sizeof( cpu_set_t ) );
        if( sched_getcpu() != i )
        {
            std::cerr << "running on the wrong CPU\n";
            exit( EXIT_FAILURE );
        }
    }
    return;
}

#undef INJECTION

int main()
{
    const auto avail_cores = get_nprocs();
    assert( avail_cores > 0 );

    std::thread p( producer, avail_cores );
    std::thread c( consumer, avail_cores );

    //threads will do some stuff...we wait; 

    p.join();
    c.join();
    return( EXIT_SUCCESS );
}
