#include <iostream>
#include <cstdlib>
#include <cstdint>
#include <cstdio>
#include <cmd>

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
   cmd.processArgs( argc, argv );

   if( help )
   {
      cmd.printArgs();
   }

   return( EXIT_SUCCESS );
}
