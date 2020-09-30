import { Component, OnInit } from '@angular/core';
import { w3cwebsocket as W3CWebSocket } from "websocket";
const client = new W3CWebSocket('ws://127.0.0.1:8080/');


@Component({
  selector: 'app-websocket',
  templateUrl: './websocket.component.html',
  styleUrls: ['./websocket.component.css']
})
export class WebsocketComponent implements OnInit {
  serverName: string = '';
  msgData: string = '';
  recvServerName: string = '';

  constructor() { 
    var d = new Date();
    var n = d.getTime().toString();
    this.serverName = n.toString();

  }

  ngOnInit(): void {
    client.onopen = () => {
      console.log('Websocket Client Connected');
  };

  client.onmessage = (message) => {
      let recvData = JSON.parse(message.data);
      console.log(recvData)
                this.msgData =recvData.msg;
                this.recvServerName =recvData.name;
      }
      
      client.onclose = e => {
          console.log('closed');
          
      };
  }

  onSend():void{
    client.send(
      JSON.stringify(
        {
          msg:"Message from Server", 
          name:this.serverName
        }
        )
      )
  }
}
