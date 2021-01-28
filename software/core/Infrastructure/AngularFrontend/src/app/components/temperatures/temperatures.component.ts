import { Component, OnInit } from '@angular/core';
import {WebsocketService} from '../../services/websocket.service';
@Component({
  selector: 'app-temperatures',
  templateUrl: './temperatures.component.html',
  styleUrls: ['./temperatures.component.css']
})
export class TemperaturesComponent implements OnInit {
  temperaturesData: any[] = [{_name: '', value: 0}]
  constructor(private wsService: WebsocketService) { 
  }

  ngOnInit(): void {
    this.wsService.serverMessage.subscribe(message => {
      if (message.obj){
        const{TEMPERATURE: temperature} = message.obj
        this.temperaturesData = temperature
      }
    })
  }

}
