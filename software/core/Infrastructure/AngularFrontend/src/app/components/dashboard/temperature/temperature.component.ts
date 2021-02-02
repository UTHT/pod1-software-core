import { Component, Input, OnInit } from '@angular/core';

@Component({
  selector: 'temperature-component',
  templateUrl: './temperature.component.html',
  //   styleUrls: ['./temperature.component.css']
})
export class TemperatureComponent implements OnInit {
  @Input() label: string;
  @Input() temp: number;
  currTemperature = 40;
  temperatureArray = [[0,0]];
  count = 0;

  constructor() { }

  ngOnInit(): void {
    // this.updateTemperature();
  }
  // updateTemperature() {
  //   // Gauge updates every 50ms
  //   // Graph updates every 5s
  //   this.currTemperature += 0.1 * (Math.round(Math.random()) * 4 - 1) * (Math.random() < 0.5 ? -1 : 1);
  //   this.count += 50;
  //   if (this.count % 5000 == 0){
  //     this.temperatureArray.push([this.count/1000,Math.floor(this.currTemperature)]);
  //     if (this.temperatureArray.length > 10){
  //       this.temperatureArray.shift();
  //     }
  //   }
  //   setTimeout(() => { this.updateTemperature(); }, 50);
  // }
}
