import { Component, OnInit } from '@angular/core';
import {WebsocketService} from '../../services/websocket.service';

@Component({
  selector: 'app-batteries',
  templateUrl: './batteries.component.html',
  styleUrls: ['./batteries.component.css']
})
export class BatteriesComponent implements OnInit {
  batteryData: any[] = [
    {_name: "battery_1", _value: '100'},
    {_name: "battery_2", _value: '100'},
  ];
  constructor(private wsService: WebsocketService) { }

  ngOnInit(): void {
    // this.wsService.serverMessage.subscribe(message => {
    //   if (message.obj){
    //     const{BATTERY: battery} = message.obj
    //     this.batteryData = battery
    //   }
    // })
  }
}
