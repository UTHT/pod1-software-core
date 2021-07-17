/**
 * command_option_base.hpp - 
 * @author: Jonathan Beard
 * @version: Tue May 21 13:56:51 2013
 */
#ifndef _COMMAND_OPTION_BASE_HPP_
#define _COMMAND_OPTION_BASE_HPP_  1

#include <string>
#include <type_traits>
#include <cstring>
#include <cassert>

class OptionBase{
public:
   OptionBase( const std::string flag,
               const std::string description,
               bool  isMandatory = false,
               bool  isBool = false );

   virtual ~OptionBase() = default;


   virtual bool setValue( const char *value ) = 0;
   virtual std::string toString() = 0;
   virtual std::string getValue() = 0;
   /** 
    * Returns true if the value has been set, useful for mandatory
    * arguments
    * @return bool
    */
   bool is_set();
   
   bool is_mandatory();
   
   /** needed to see if a follow-on char is actually required **/
   bool is_bool();

   std::string& get_flag();
   std::string& get_description();

protected:

   template < class T, 
              typename std::enable_if< std::is_same< T, std::string >::value >::type* = nullptr > bool setValueHelper( T &realV, const char *value )
   {
        assert( value != nullptr );
        realV = std::string( value );
        return( true );
   }
   
   template < class T, 
              typename std::enable_if< std::is_same< T, bool >::value >::type* = nullptr > bool setValueHelper( T &realV, const char *value )
   {
       if( value == nullptr || std::strcmp( value,  "true" ) == 0 )
       {
          realV = true;
       }
       else if( std::strcmp( value, "false" ) == 0 )
       {
          realV = false;
       }
       return( true );
   }

   template < class T,
              typename std::enable_if< std::is_signed< T >::value &&
                                       ! std::is_same< T, bool >::value &&
                                       ! std::is_floating_point< T >::value >::type* = nullptr>
   bool setValueHelper( T &realV, const char *value )
   {
       assert( value != nullptr );
       errno = 0;
       realV = static_cast< T >( strtoll( value, nullptr, 10 ) );
       if( errno != EXIT_SUCCESS )
       {
           return( false );
       }
       return( true );
   }
   
   template < class T,
              typename std::enable_if< std::is_unsigned< T >::value &&
                                       ! std::is_same< T, bool >::value >::type* = nullptr>
   bool setValueHelper( T &realV, const char *value )
   {
       assert( value != nullptr );
       errno = 0;
       realV = static_cast< T >( strtoull( value, nullptr, 10 ) );
       if( errno != EXIT_SUCCESS )
       {
           return( false );
       }
       return( true );
   }

   template < class T,
              typename std::enable_if< std::is_same< T, double >::value >::type* = nullptr >
   bool setValueHelper( T &realV, const char *value )
   {
        assert( value != nullptr );
        errno = 0;
        realV = static_cast< T >( strtod( value, nullptr ) );
        if( errno != EXIT_SUCCESS )
        {
            return( false );
        }
        return( true );
   }
   
   template < class T,
              typename std::enable_if< std::is_same< T, float >::value >::type* = nullptr >
   bool setValueHelper( T &realV, const char *value )
   {
        assert( value != nullptr );
        errno = 0;
        realV = static_cast< T >( strtof( value, nullptr ) );
        if( errno != EXIT_SUCCESS )
        {
            return( false );
        }
        return( true );
   }

   std::string toString( const std::string defaultValue );
   bool        set;
   
   /** add conversion templates here **/
private:
   std::string flag;
   std::string description;
   bool        isbool;
   bool        mandatory;
};
#endif /* END _COMMAND_OPTION_BASE_HPP_ */
