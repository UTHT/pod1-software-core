/**
 * command_option_multiple.hpp - 
 * @author: Jonathan Beard
 * @version: Tue May 21 15:12:50 2013
 */
#ifndef _COMMAND_OPTION_MULTIPLE_HPP_
#define _COMMAND_OPTION_MULTIPLE_HPP_  1

#include <cassert>
#include <array>
#include <functional>
#include <typeinfo>
#include <cstdint>
#include <cstdlib>
#include "command_option_base.hpp"
#include <cassert>

template <class T, int N> class OptionMultiple : public OptionBase {
public:
      /**
       * Option - An option constructor for an option that
       * sets multiple values.  It takes a std::array object
       * of the values to be set as ptrs (Items), a flag (Flag), 
       * a description of what the user is expected to be setting 
       * (Description), another std::array which takes a special
       * type conversion function for each value that you want to
       * set in the array Items (must match the same index), a print
       * behavior function which will allow the user to print each 
       * default value within the array Items.  A nullptr is allowed
       * for the PrintBehavior function if you want to let the std
       * library take a shot at printing
       * @param   Items - std::array< T, N>
       * @param   Flag - std::string
       * @param   Description - std::string
       * @param   Functions - required functions which map the input
       *          given from the command line to each value that the 
       *          should be set in Items, each function must correspond
       *          to the appropriate index in Items.  The first param
       *          to the function is the cmd line string, the second
       *          should be set by the function to true on success and
       *          false on failure
       * @param   PrintBehavior - takes in the current value T& and prints
       *          it with whatever pretty behavior you desire, also optional
       *          but recommended for all but very basic types
       */
   OptionMultiple( std::array<std::reference_wrapper< T >, N > Items,
                   std::string        Flag,
                   std::string        Description,
               std::array< std::function< T (const char* , bool&) >,N > Functions,
               std::function< std::string ( T& ) > PrintBehavior  = nullptr )
                     : OptionBase( Flag, Description, false ),
                       items( Items ),
                       F( Functions ),
                       PrettyPrint( PrintBehavior )
   {
      /* nothing really to do */
   }

   virtual std::string 
   toString()
   {
      return( OptionBase::toString( format_item( items.front() ) ) );
   }

   virtual bool  
   setValue( const char* value )
   {  
      assert( value != nullptr );
      assert( F.size() == items.size() );
      auto it_function( F.begin() );
      auto it_item( items.begin() );
      for( ; it_function != F.end(); ++it_function, ++it_item )
      {
         bool success( true );
         (*it_item) = (*it_function)( value , success );
         if( ! success ){
            return( false );
         }
      }
      return( true );
   }
   
   std::string
   getValue()
   {
      assert( false );
      return( "no implemented yet" );
   }


private:
   std::string format_item( T &x ){
      if( PrettyPrint != nullptr )
      {
         return( PrettyPrint( x ) );
      }
      else if( typeid(x) == typeid(bool) )
      {
         if( *((bool*)(&x))  == true){
            return("true");
         }else{
            return("false");
         }
      }
      else if( typeid(x) == typeid(double) )
      {
         char buffer[100];
         memset(buffer, '\0', sizeof(char) * 100);
         snprintf(buffer, 100, "%0.3f", *((double*)(&x)));
         std::stringstream ss;
         ss << buffer;
         return( ss.str() );
      }
      else
      {
         std::stringstream out;
         out << x;
         return( out.str() );
      }
   }

   std::array<std::reference_wrapper< T >, N> items;
   std::array< std::function< T ( const char* , bool&) >, N > F;
   std::function< std::string ( T& ) > PrettyPrint;
};

#endif /* END _COMMAND_OPTION_MULTIPLE_HPP_ */
