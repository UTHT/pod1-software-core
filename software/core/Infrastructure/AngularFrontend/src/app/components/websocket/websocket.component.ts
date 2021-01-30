import { Component, OnInit } from '@angular/core';
import { w3cwebsocket as W3CWebSocket } from "websocket";
const client = new W3CWebSocket('ws://127.0.0.1:8080/');
import { DataStreamService } from '../../services/data-stream.service';

@Component({
  selector: 'app-websocket',
  templateUrl: './websocket.component.html',
  styleUrls: ['./websocket.component.css']
})
export class WebsocketComponent implements OnInit {
  serverName: string = '';
  msgData: string = '';
  recvServerName: string = '';
  serverType: string = '';

  //call this.dsService.updateData(<Object>) to update the state
  //call this.dsService.currentData.subscribe((data) => {}) to watch for change and update state accordingly
  constructor(private dsService: DataStreamService) {
    var d = new Date();
    var n = d.getTime().toString();
    this.serverName = n.toString();
    // this.serverType = "";
  }

  ngOnInit(): void {
    client.onopen = () => {
      console.log('Websocket Client Connected');
      console.log()

      client.send(
        JSON.stringify(
          {
            msg: "Message from Server " + 'A',
            name: this.serverName,
            serverType: 'dashboard',
            isNew: true
    
          }
        )
      )
    

    };

    client.onmessage = (message) => {
      console.log("message from websocket: ", message);
      let recvData = JSON.parse(message.data);
      console.log("recvData: ", recvData)
      this.msgData = recvData.toString();
      this.recvServerName = recvData;
    }

    client.onclose = e => {
      console.log('closed');

    };
  }

  serverSelect(): void {
    // const selServer = document.getElementById('serverType');
    // selServer.addEventListener('change', (e) => {
    //   this.serverType = (e.target as HTMLSelectElement).value;
    // });
    // console.log(this.serverType);

    // const selServer = document.querySelector('.serverType');
    // selServer.addEventListener('change', (e) => {
    //   this.serverType = (<HTMLInputElement>e.target).value;
    // });
    // console.log(this.serverType);

    // var selServer = (document.getElementById('serverType')) as HTMLSelectElement;
    // var serverValue = selServer.options[selServer.selectedIndex].value;
    // this.serverType = serverValue;
    // console.log(this.serverType);


    // var selServer = document.getElementById('serverType').querySelector("option");

    var selServer = (<HTMLSelectElement>document.getElementById("serverType")).value;
    console.log(selServer);
    if (selServer == "serverA") {
      this.serverType = "A";
      // console.log("Message sent from server A");
    }
    else {
      this.serverType = "B";
      // console.log("Message sent from server B");
    }


}

onSend(): void {
  this.serverSelect();

  client.send(

    JSON.stringify(
      {
        msg: "Message from Server " + this.serverType,
        name: this.serverName,
        serverType: this.serverType,
        isNew: false

      }
    )
  )
};
}
