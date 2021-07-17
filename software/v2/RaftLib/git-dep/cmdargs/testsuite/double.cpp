#include <iostream>
#include <cstdlib>
#include <cstdint>
#include <cstdio>
#include <cmd>
#include <iomanip>

int
main( int argc, char **argv )
{
   CmdArgs cmd( argv[ 0 ],
                std::cout,
                std::cerr );

   bool help( false );
   cmd.addOption( new Option< bool >( help,
                                      "-h",
                                      "This is help, print menu" ) );
   
   double test( 0.0 );
   cmd.addOption( new Option< double >( test, 
                              "-t",
                              "this is a test for double" ) );

   float test2( 0.0 );
   cmd.addOption( new Option< float >( test2, 
                              "-f",
                              "this is a test for float" ) );

                                 
   
   cmd.processArgs( argc, argv );

   if( help )
   {
      cmd.printArgs();
   }

   std::cout << test << "\n";
   std::cout << test2 << "\n";
   return( EXIT_SUCCESS );
}
