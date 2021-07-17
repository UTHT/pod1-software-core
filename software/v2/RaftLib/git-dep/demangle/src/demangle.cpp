/**
 * demangle.cpp - 
 * @author: Jonathan Beard
 * @version: Fri Sep 12 10:28:33 2014
 * 
 * Copyright 2014 Jonathan Beard
 * 
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at:
 *
 *   http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include "demangle.hpp"

#if defined( __clang__ ) && defined( __has_include )
# if __has_include(<cxxabi.h>)
# include <cxxabi.h>
# endif
#elif defined( __GLIBCXX__ ) || defined( __GLIBCPP__ )
# include <cxxabi.h>
#endif

#ifdef INJECT_DEMANGLE_NAMESPACE
#define INJECTION DEMANGLE_NAMESPACE::
#else
#define INJECTION   
#endif


#if defined( _CXXABI_H ) || defined( __CXXABI_H )
std::string 
INJECTION demangle(const char *name) {
  int status = -4;
  char *res = abi::__cxa_demangle(name, NULL, NULL, &status);
  const char *const demangled_name = (status == 0) ? res : name;
  const std::string val( demangled_name );
  std::free( res );
  return( val );
}
#else /** no CXX ABI header not much we can do **/
std::string 
INJECTION demangle(const char *name) { return std::string(name); }
#endif

#undef INJECTION
