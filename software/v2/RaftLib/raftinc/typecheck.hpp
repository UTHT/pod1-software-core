/**
 * typecheck.hpp - 
 * @author: Jonathan Beard
 * @version: Mon Nov 24 19:44:18 2014
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
#ifndef RAFTTYPECHECK_HPP
#define RAFTTYPECHECK_HPP  1
#include <cstddef>

class typecheck {
public:
   
   virtual bool 
   is_compatible( const typecheck &other ) = 0;
   
   virtual std::size_t 
   type_size() = 0;

};
#endif /* END RAFTTYPECHECK_HPP */
