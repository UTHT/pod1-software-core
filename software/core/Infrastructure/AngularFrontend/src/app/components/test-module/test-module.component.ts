import { Component, OnInit } from '@angular/core';
import { w3cwebsocket as W3CWebSocket } from "websocket";
const client = new W3CWebSocket('ws://127.0.0.1:8080/');

@Component({
  selector: 'app-test-module',
  templateUrl: './test-module.component.html',
  styleUrls: ['./test-module.component.css']
})
export class TestModuleComponent implements OnInit {

  speed: number = 0;
  temp1: number = 0;
  temp2: number = 0;
  brake: boolean = false;
  testOn: boolean = false;
  intervals;
  //location: [];

  constructor() { 
    this.testOn = false;
  }

  ngOnInit(): void {
  }

  getSpeed(): number{
    return Math.floor((Math.random() * 190) + 1);
  }

  getTemp(): number{
    return Math.floor((Math.random() * 60) + 1);
  }

  getBrake(): boolean{
    return false;
  }

  onSend():void{
    var objClient = {
      speed: this.getSpeed(),
      temp1: this.getTemp(),
      temp2: this.getTemp(),
      brake: this.getBrake()
    }

      client.send(
        JSON.stringify(
          {
            client: objClient
          }
          )
        )
    }

  startStopTest():void{
    if (!this.testOn)
    {
      let startStopButton = document.getElementById('testButton') as HTMLInputElement;
      startStopButton.innerHTML = "Stop Test";

      let statusTag = document.getElementById('status') as HTMLInputElement;
      statusTag.innerHTML= "Test has started ... "

      this.testOn = true;
      this.intervals = setInterval(
                    this.onSend.bind(this), 
                    1000
                    );
    }
    else
    {
      let startStopButton = document.getElementById('testButton') as HTMLInputElement;
      startStopButton.innerHTML = "Start Test";

      let statusTag = document.getElementById('status') as HTMLInputElement;
      statusTag.innerHTML= "Test has Stopped. "

      this.testOn = false;
      clearInterval(this.intervals)
    }
    
  }

}
