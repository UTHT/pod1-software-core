import { Component, OnInit } from '@angular/core';
import {WebsocketService} from '../../../services/websocket.service';

@Component({
  selector: 'speed-component',
  templateUrl: './speed.component.html',
  //   styleUrls: ['./speed.component.css']
})
export class SpeedComponent implements OnInit {
  currSpeed = 0;
  speedArray = [[0,0]];
  count = 0;

  constructor(private wsService: WebsocketService) { }

  ngOnInit(): void {
    this.randomize();
  }
  randomize() {
    // Gauge updates every 50ms
    // Graph updates every 5s

    this.wsService.history.subscribe(historyArray => {
      if (historyArray && historyArray.length > 0){
        console.log(historyArray);
        this.currSpeed = historyArray[historyArray.length-1].obj.SPEED[0]._value;
        this.count += 50;
        // if (this.count % 5000 == 0){
          this.speedArray.push([this.count/1000,Math.floor(this.currSpeed)])
          if (this.speedArray.length > 10){
            this.speedArray.shift();
          }
        // }
      }
    })

    //this.currSpeed += 0.1 * (Math.round(Math.random()) * 4 - 1);
    
    // setTimeout(() => { this.randomize(); }, 50);
  }
}