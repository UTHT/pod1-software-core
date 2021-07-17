/**
 * CmdArgs - A very simple command line arguments src file, can be included
 * in C++ and C files using the appropriate function calls.  In order to 
 * use this to process your arguments simply do the following:
 * //create a CmdArgs object
 * CmdArgs *args = new CmdArgs(std::string(argv[0])); //sets program name for object
 * //define static variables for options
 * static bool myFirstOption = false; //assigning var gives default value
 * //add options to CmdArgs
 * cmd->addOption(new Option<bool>(&myFirstOption,"-mFO","An option"));
 * //general form of
 * cmd->addOption(new Option<type>(var mem location, text flag, text description));
 * //give cmd line args to CmdArgs
 * cmd->processArgs(argc,argv)
 * .....now you can use the variables as you see fit
 *
 * @author Jonathan Beard
 * @version Last modified 27 May 2012
 * @contact jbeard@wustl.edu
 */ 


#ifndef __CMDARGS_H__
#define __CMDARGS_H__

#include <cstdlib>
#include <cinttypes>
#include <cstdint>
#include <functional>
#include <typeinfo>
#include <cstring>
#include <sstream>
#include <vector>
#include <iostream>



#include "command_option_base.hpp"

/**
 * CmdArgs - actual cmd args class
 */
class CmdArgs{
   public:
      /**
       * Default Constructor - 
       * @param   name - std::string, name of program using CmdArgs
       * @param   user - std::ostream&, stream for user output
       * @param   err  - std::ostream&, stream for error output
       */
      CmdArgs(const std::string name,
              std::ostream &user,
              std::ostream &err );
      ~CmdArgs();
      /**
       * printArgs - print all the options
       */
      void printArgs();
      /**
       * printSettings - useful for benchmark codes 
       */
      void printSettings();
      
      /**
       * addOption - each of these takes a ptr to an options
       * object, there is a method for int64_t, bool, std::string,
       * and double.  
       */
      void addOption( OptionBase *option );
      /**
       * processArgs - to be called when all the options
       * are registered and you're ready to set the variables
       * @param   argc - int, with number of strings in _argv
       * @param   argv - char**, with list of strings from the
       * command line 
       */
      void processArgs(int argc, char **argv);
   
      char** getOriginalArguments();
      int    getOriginalArgumentCount();

      bool  allMandatorySet();
   private:
      /** generateStars - 
       * print cheesy star framed list to buffer of length bsize - 1
       */
      void generateStars( char *buffer, const std::size_t bsize );
      std::vector< OptionBase * > options;
      std::string                 name;
      std::ostream                &userstream;
      std::ostream                &errorstream;

      char                        **argv;
      int                         argc;
};

 #endif /* END __CMDARGS_H__ */
