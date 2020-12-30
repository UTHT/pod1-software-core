import { Component, OnInit } from '@angular/core';

@Component({
  selector: 'speed-component',
  templateUrl: './speed.component.html',
  //   styleUrls: ['./speed.component.css']
})
export class SpeedComponent implements OnInit {
  currSpeed = 0;
  speedArray = [[0,0]];
  count = 0;

  constructor() { }

  ngOnInit(): void {
    this.randomize();
  }
  randomize() {
    // Gauge updates every 50ms
    // Graph updates every 5s
    this.currSpeed += 0.1 * (Math.round(Math.random()) * 4 - 1);
    this.count += 50;
    if (this.count % 5000 == 0){
      this.speedArray.push([this.count/1000,Math.floor(this.currSpeed)])
      if (this.speedArray.length > 10){
        this.speedArray.shift();
      }
    }
    setTimeout(() => { this.randomize(); }, 50);
  }
}
