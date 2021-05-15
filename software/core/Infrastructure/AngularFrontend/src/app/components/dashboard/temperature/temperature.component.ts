import { Component, Input, OnInit } from '@angular/core';
import {WebsocketService} from '../../../services/websocket.service';


@Component({
  selector: 'temperature-component',
  templateUrl: './temperature.component.html',
  //   styleUrls: ['./temperature.component.css']
})
export class TemperatureComponent implements OnInit {
  @Input() label: string;
  @Input() temp: number;
  @Input() idNum: string;
  currTemperature = 0;
  temperatureArray = [[0,0]];
  count = 0;

  constructor(private wsService: WebsocketService) { }

  ngOnInit(): void {
    this.updateTemperature();
  }
  updateTemperature() {
    this.wsService.history.subscribe(historyArray => {
      if (historyArray && historyArray.length > 0){
        console.log(historyArray);
        this.currTemperature = historyArray[historyArray.length-1].obj.TEMPERATURE[this.idNum]._value;
        this.count += 50;
        // if (this.count % 5000 == 0){
          this.temperatureArray.push([this.count/1000,Math.floor(this.currTemperature)])
          if (this.temperatureArray.length > 10){
            this.temperatureArray.shift();
          }
        // }
      }
    })

  }
}
