# Building the Arduino 

## Description 

The communications system for the pod is built using ZCM. Below are the instructions to build and run our sensor code. Sensors are connected to Arduino Dues and the values are read and published using ZCM. For more information on ZCM, see https://github.com/ZeroCM/zcm. 

## Dependencies
* On linux ensure that you run 
  * `sudo apt update; sudo apt upgrade` 
* Gnu: g++/gcc 
* Arduino IDE 
* C++ Boost Library 
  * Command to download boost on Linux (ubuntu) 
      * `sudo apt-get install libboost-all-dev`

## Building

* Clone the Software Repository - 
  * `git clone https://github.com/UTHT/pod1-software-core.git`
* Checkout the stable communications dev branch - 
  * `git checkout communications/dev-latest`
* Go into software/communications then run: 
  * `git submodule update --init --recursive`
* Then cd into communications/odroid/reading_from_zcm_channels
* Run `make` in terminal
* Once the program has been built, run `./reading_from_zcm_channels` [1] 
* You may need to pass the USB serial port to the program based on what port the Arduino is connected to.

## Using the Arduinos
* Setting up the arduino using the wiring diagrams given by electronics: https://drive.google.com/drive/u/2/folders/1rWFOF1FVi4OxP67ZrXyXkZxlD6pzlSzw 
* Add arduino due to the IDE, by 
  1. Open arduino IDE then open up the .ino file with the desired sensor  
  2. Then go to tools -> Boards Manager, then type due and install it 
  3. Then go to tools -> port -> programming port (ensure that is it connected to that port on the actual arduino) 
* Verify and upload the code 
* The serial port should have data coming in, and the correct data should be on the terminal where the run `./reading_from_zcm_channels` was called refer to [1] 



