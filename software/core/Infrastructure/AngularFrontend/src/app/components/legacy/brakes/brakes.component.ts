import { Component, OnInit } from '@angular/core';
import { WebsocketService } from '../../../services/websocket.service'

@Component({
  selector: 'app-brakes',
  templateUrl: './brakes.component.html',
  styleUrls: ['./brakes.component.css']
})
export class BrakesComponent implements OnInit {
  brakesDataArray: any[] = []

  brakesData: any[] = [
    {_name: "brakes_left", _value: 0},
    {_name: "brakes_right", _value: 0},
  ]
  constructor(private wsService: WebsocketService) { }

  ngOnInit(): void {
    this.wsService.history.subscribe(historyArray => {
      const brakesMap = historyArray.map(({obj, time}) => { 
        if (obj){
          const {BRAKE: items} = obj;  
          return {items, time}
        }
      })
      this.brakesDataArray = brakesMap;

      if (historyArray.length > 0) {
        const currentObject = historyArray[historyArray.length - 1];
        const {BRAKE: brakes} = currentObject.obj;
        this.brakesData = brakes
      }
    })
  }
}
