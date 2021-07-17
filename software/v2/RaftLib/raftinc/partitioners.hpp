/**
 * partitioners.hpp - 
 * @author: Jonathan Beard
 * @version: Tue May  3 12:24:44 2016
 * 
 * Copyright 2016 Jonathan Beard
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
#ifndef RAFTPARTITIONERS_HPP
#define RAFTPARTITIONERS_HPP  1

/** 
 * simply a list of the current partitioners...plus
 * some of the necessary bits to conditionally compile
 */
#include "partition_basic.hpp"
#if USE_PARTITION
#include "partition_scotch.hpp"
#endif
#include "partition_dummy.hpp"

#endif /* END RAFTPARTITIONERS_HPP */
