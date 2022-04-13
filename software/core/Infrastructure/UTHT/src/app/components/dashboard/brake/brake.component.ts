import { Component, Input, Output, OnInit, OnChanges, EventEmitter } from '@angular/core';
import {WebsocketService} from '../../../services/websocket.service';



@Component({
  selector: 'brake-component',
  templateUrl: './brake.component.html',
  //   styleUrls: ['./brake.component.css']
})
export class BrakeComponent implements OnInit {
  @Input() label: string;
  @Input() idNum: string;
  @Input() pressure: number;
  @Input() pressureArray: any[];
  pressureDataPoints: any[];
  currBrakePressure = 1;
  brakePressureArray = [[0,0]];
  count = 0;

  constructor(private wsService: WebsocketService) { }

  ngOnInit(): void {
    this.randomize();
  }

  randomize() {
    this.wsService.history.subscribe(historyArray => {
      if (historyArray && historyArray.length > 0){
        //console.log(historyArray);
        this.currBrakePressure = historyArray[historyArray.length-1].obj.PRESSURE[this.idNum]._value;
        this.count += 50;
        // if (this.count % 5000 == 0){
          this.brakePressureArray.push([this.count/1000,Math.floor(this.currBrakePressure)])
          if (this.brakePressureArray.length > 10){
            this.brakePressureArray.shift();
          }
        // }
      }
    })

    // setTimeout(() => { this.randomize(); }, 50);
  }
  
}
