## Infrastructure - Sprint 1

As of right now, the nodejs is being used as the backend, and React is used for the front-end (for fast deployment purpose). For future development, We will be shifting to Angular.

This skeleton code can be used to complete ticket _" Implementing types in Web socket for data routes"_.

#### Installation Guide:
There are two parts for installation. You have to install npm libraries independently for frontend and backend. For backend:
``` sh
cd backend
npm i           #install npm modules
npm start    #start nodejs server
```

For frontend:
```sh
cd AngularFrontend
npm i           #install npm modules
npm start       #start react server at port 3000
```

Now you can open multiple instances in the browser at `localhost:3000/` and each instance will be connected to the WebSocket.

#### Test for websocket connection:
Every instance at `localhost:4200/` will have a unique temp server name (which is just the current date :p ). When the button is clicked, the message is sent across all the instances if the WebSocket is working properly.