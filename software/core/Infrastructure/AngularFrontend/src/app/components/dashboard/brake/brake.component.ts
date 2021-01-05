import { Component, Input, OnInit } from '@angular/core';

@Component({
  selector: 'brake-component',
  templateUrl: './brake.component.html',
  //   styleUrls: ['./brake.component.css']
})
export class BrakeComponent implements OnInit {
  @Input() label: string;
  currBrakePressure = 1;
  brakePressureArray = [[0,0]];
  count = 0;

  constructor() { }

  ngOnInit(): void {
    this.randomize();
  }
  randomize() {
    // Gauge updates every 50ms
    // Graph updates every 5s
    this.currBrakePressure += 0.01 * (Math.round(Math.random()) * 4 - 1) * (Math.random() < 0.5 ? -1 : 1);
    this.count += 50;
    if (this.count % 5000 == 0){
      this.brakePressureArray.push([this.count/1000,Math.round(this.currBrakePressure * 10) / 10]);
      if (this.brakePressureArray.length > 10){
        this.brakePressureArray.shift();
      }
    }
    setTimeout(() => { this.randomize(); }, 50);
  }
}
