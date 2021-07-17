/**
 * demangle.hpp - 
 * @author: Jonathan Beard, BoB R (2noodle)
 * @version: Sat, March 28 2020
 * 
 * Copyright 2020 RaftLib
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

#ifndef _AFFINITY_HPP_
#define _AFFINITY_HPP_  1

#include <cstddef>


#ifdef INJECT_AFFINITY_NAMESPACE
namespace AFFINITY_NAMESPACE {
#endif

struct affinity
{
   static void set( const std::size_t desired_core );
};


#ifdef INJECT_AFFINITY_NAMESPACE
} /** end namespace **/
#endif /** end inject namespace **/


#endif /* END _AFFINITY_HPP_ */
