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
  // @Output() updatePressure = new EventEmitter<number>();
  // currBrakePressure = 1;
  // brakePressureArray = [[0,0]];
  // count = 0;

  constructor(private wsService: WebsocketService) { }

  ngOnInit(): void {
    // this.count += 1
    //this.updateBrakePressure();
    this.randomize();
  }

  randomize() {
    // Gauge updates every 50ms
    // Graph updates every 5s
    // this.currBrakePressure += 0.01 * (Math.round(Math.random()) * 4 - 1) * (Math.random() < 0.5 ? -1 : 1);
    // this.count += 50;
    // if (this.count % 5000 == 0){
    //   this.brakePressureArray.push([this.count/1000,Math.round(this.currBrakePressure * 10) / 10]);
    //   if (this.brakePressureArray.length > 10){
    //     this.brakePressureArray.shift();
    //   }
    // }

    this.wsService.history.subscribe(historyArray => {
      if (historyArray && historyArray.length > 0){
        //console.log(historyArray);
        this.currBrakePressure = historyArray[historyArray.length-1].obj.BRAKE[this.idNum]._value;
        this.count += 50;
        // if (this.count % 5000 == 0){
          this.brakePressureArray.push([this.count/1000,Math.floor(this.currBrakePressure)])
          if (this.brakePressureArray.length > 10){
            this.brakePressureArray.shift();
          }
        // }
      }
    })

    setTimeout(() => { this.randomize(); }, 50);
  }
  

  //ngOnChanges(): void {
    //TODO: the array seems to be not able to be updated this way
    // this.count += 50;
    // console.log(this.count)
    // this.brakePressureArray = [...this.brakePressureArray, [this.count, this.pressure]]
    // console.log(this.brakePressureArray)


    // if (this.brakePressureArray.length > 10){
    //   this.brakePressureArray.shift();
    // }
  //   if (this.pressureArray.length > 0){
  //     const dataMap = this.pressureArray.map(({brakeValues, time}) => { 
  //       const value = brakeValues.filter((brake)=> brake._name === this.label)[0]._value
  //       return {x: time, y:value}
  //     })
  //     this.pressureDataPoints = dataMap
  //   }
  // }

  // updateBrakePressure() {
  //   // Gauge updates every 50ms
  //   // Graph updates every 5s
  //   this.currBrakePressure += 0.01 * (Math.round(Math.random()) * 4 - 1) * (Math.random() < 0.5 ? -1 : 1);
  //   this.count += 50;
  //   if (this.count % 5000 == 0){
  //     this.brakePressureArray.push([this.count/1000,Math.round(this.currBrakePressure * 10) / 10]);
  //     if (this.brakePressureArray.length > 10){
  //       this.brakePressureArray.shift();
  //     }
  //   }
  //   setTimeout(() => { this.updateBrakePressure(); }, 50);
  //}
}
