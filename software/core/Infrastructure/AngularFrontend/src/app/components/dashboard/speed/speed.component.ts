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
  engaged = false;

  constructor() { }

  ngOnInit(): void {
    this.updateSpeed();
  }
  updateSpeed() {
    // Gauge updates every 50ms
    // Graph updates every 5s

    var speedDiff = 0.1 * (Math.round(Math.random()) * 4 - 1)

    // demo code
    if (speedDiff < 0){
      this.engaged = true;
    }else{
      this.engaged = false;
    }

    this.currSpeed += speedDiff;
    this.count += 50;
    if (this.count % 5000 == 0){
      this.speedArray.push([this.count/1000,Math.floor(this.currSpeed)])
      if (this.speedArray.length > 10){
        this.speedArray.shift();
      }
    }
    setTimeout(() => { this.updateSpeed(); }, 50);
  }
}