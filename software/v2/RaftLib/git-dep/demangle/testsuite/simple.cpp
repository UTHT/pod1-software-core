/**
 * simple.hpp - 
 * @author: Jonathan Beard
 * @version: Sun 20 May  19:54:33 2020
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
#include <cstdlib>
#include "demangle.hpp"
#include <typeinfo>
#include <iostream>

struct 
//try to ensure no name collision with injected namespace
_foobar_123456 
{
    /** random stuff for fun **/
    int a;
    int b = 12;
};


int main()
{  
    /**
     * looks a bit funny, but injects the namespace where and when 
     * needed. 
     */
    _foobar_123456 f;
    std::string output = 
#ifdef INJECT_DEMANGLE_NAMESPACE
    DEMANGLE_NAMESPACE::
#endif
    demangle( typeid( f ).name() );
    if( output.compare( "_foobar_123456" ) != 0 /** if they're not equal **/ )
    {
        std::cout << output << "\n";
        return( EXIT_FAILURE );
    }
    return( EXIT_SUCCESS );
}
