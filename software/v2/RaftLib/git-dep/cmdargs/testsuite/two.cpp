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
   std::int64_t num( 200 );
   cmd.addOption( new Option< bool >( help,
                                      "-h",
                                      "This is help, print menu" ) );
   cmd.addOption( new Option< std::int64_t >( num,
                                      "-num",
                                      "This is help, print menu" ) );
   cmd.processArgs( argc, argv );

   if( help )
   {
      cmd.printArgs();
   }

   return( EXIT_SUCCESS );
}
