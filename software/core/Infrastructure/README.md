# Infrastructure 

### Table of Contents
1. [Architecture](#Overview)
2. [Module Breakdown](#application-breakdown)
3. [Installation Guide](#installation-guide)

<hr>

## Architecture 
The Infrastructure carries out data transmission from the Odroid (master computer in the pod) to the central system (backend) in the laptop. The central system is an intricate and comprehensive data parsing, validating, encapsulating, and storing mechanism that acts as the backbone of the entire subsystem. The validated data is sent to the widgets (frontend) to be analyzed by the user to detect any errors which are further relayed to other subsystems (for example energy, electronics, propulsion etc.). Beginning from the user’s first interaction with pod data, the widgets depict various graphs and charts that display sensor readings. A Birds-eye view module is integrated to easily locate sensors with abnormal readings whose unique ID can be relayed to the appropriate subteam to initiate debugging. The above explanation is concisely depicted in the Software Architecture Diagram 

![design](readme/Architecture.png)

## Module Breakdown
_Details coming soon_


## Installation Guide
Angular resides inside Electron as a framework for displaying data. Electron (build on NodeJs) is the main driving engine behind this software. You can get started with Electron and Angular Development as follows:


```sh
cd UTHT/
npm i #install all the npm dependecies
npm build --base-href="./"  # build Angular frontend framework which electron can utilize

npm run electron-start #start the electron framework
```

Other commans include
```sh
npm start # only initializes the Angular fromewoork
```

Now you can open multiple instances in the application at `localhost:4200/` and each instance will be connected to the WebSocket.

#### Compiling C++ socket
We can succesfully connect to Nodejs Websocket with C++ websocket. You can compile and run C++ as follows:

```sh
make
./socket
```

The script can be run with the following parameters:

```sh
./socket <IP_Address> <Port> # ./socket 127.0.0.1 8080
```

<b style="color:red"> NOTE: make sure you have nodejs running before running ./a.out</b>

#### Creating Component for Angular
If you want to create an independent component in Angular, make sure you create it inside components folder. You can use the following command:

`ng generate component components/<nameOfPackage>`


## Installation Guide (LEGACY)

There are two parts for installation. You have to install npm libraries independently for frontend and backend. 

For backend:

``` sh
cd backend
npm i           #install npm modules
npm start       #start nodejs server
```

For frontend:
```sh
cd AngularFrontend
npm i           #install npm modules
npm start       #start react server at port 4200
```

Now you can open multiple instances in the browser at `localhost:4200/` and each instance will be connected to the WebSocket.

## Installation Guide (LEGACY 2)
There are two parts for installation. You have to install npm libraries independently for Angular and Electron.

For Angular:

```sh
cd UTHT/main/view/AngularFrontend
npm install                         #install npm module
ng build --base-href "/"            # set base reference for angular
```

For electron
```sh
cd UTHT
npm i
npm start
```

Now you can open multiple instances in the application at `localhost:4200/` and each instance will be connected to the WebSocket.


#### 

<!-- #### Test for websocket connection:
Test for websocket should be divided into  -->


<!-- ## Infrastructure - Sprint 1

As of right now, the nodejs is being used as the backend, and React is used for the front-end (for fast deployment purpose). For future development, We will be shifting to Angular.

This skeleton code can be used to complete ticket _" Implementing types in Web socket for data routes"_. -->