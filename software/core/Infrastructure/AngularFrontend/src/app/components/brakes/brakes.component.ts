import { Component, OnInit } from '@angular/core';
import { WebsocketService } from '../../services/websocket.service'

@Component({
  selector: 'app-brakes',
  templateUrl: './brakes.component.html',
  styleUrls: ['./brakes.component.css']
})
export class BrakesComponent implements OnInit {
  brakesData: any[] = [
    {_name: "brakes_left", _value: 0},
    {_name: "brakes_right", _value: 0},
  ]
  constructor(private wsService: WebsocketService) { }

  ngOnInit(): void {
    this.wsService.serverMessage.subscribe(message => {
      if (message.obj){
        const{BRAKE: brake} = message.obj
        this.brakesData = brake
      }
    })
  }
}
