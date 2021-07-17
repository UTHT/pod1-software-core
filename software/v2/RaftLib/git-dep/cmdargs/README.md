Command Args
=====================
Super simple command arguments parser for C++.
Yeah, there are quite a few already in existence, but I made this for a 
particular purpose, ended up using it quite a 
bit so it's worth it at this point to put it
up on GitHub so I can download it from multiple
points.

#Build Status
[![Build Status](https://travis-ci.org/RaftLib/cmdargs.svg?branch=master)](https://travis-ci.org/RaftLib/cmdargs)

#Notes
There are a few bugs here and there, notably 
there are a few instances where there are
null arguments that I'd like to pass but
it's easy enough to get around by adding
an explicit boolean.  

#Compiling is super simple:

```bash
mkdir build
cd build
cmake ../cmdargs
make
sudo make install
```


which installs all the
library code and header files in the appropriate
/usr/local prefix. I've used on both OS X and Linux,
I'll check to see if it works on Windows when I get a chance.

##Simple Example
```cpp
CmdArgs  cmd( argv[ 0 ],
              std::cout,
              std::cerr );

bool help( false );

cmd.addOption( new Option< bool >( help,
                                    "-h",
                                    "Print this message",
                                    false,
                                    true ) );
bool printHeader( false );
cmd.addOption( new Option< bool >( printHeader,
                                    "-header",
                                    "Print the header and exit" ) );


cmd.addOption( new Option< std::string >( filename,
                                          "-f",
                                          "Set the output file name",
                                          true /** make this arg mandatory **/ ) );

cmd.addOption( new Option< int64_t >( length, 
                                      "-l",
                                      "Length of run" ) );
cmd.addOption( new Option< int64_t >( buff_size,
                                      "-b",
                                      "Buffer size" ) );

cmd.addOption( new Option< int64_t >( repeat,
                                      "-r",
                                      "Number of times to repeat simulation" ) );

cmd.processArgs( argc, argv );

/** give object command line **/
cmd.processArgs( argc, argv );

/** handle the user needing help **/
if( help )
{
   cmd.printArgs();
   exit( EXIT_SUCCESS );
}
/** 
 * to check and see if all mandatory args are set, add this code
 * which will print all mandatory args that are missing.
 */
if( cmd.allMandatorySet() )
{ 
   //exit since well, mandatory args missing
   exit( EXIT_FAILURE );
}
```

Enjoy, feel free to update, copy or fix as you feel the need to.
