import { Component, Input, OnInit, OnChanges } from '@angular/core';

@Component({
  selector: 'app-gauge-graph',
  templateUrl: './gauge-graph.component.html',
  styleUrls: ['./gauge-graph.component.css']
})
export class GaugeGraphComponent implements OnInit, OnChanges {
  @Input() label: string = "";
  @Input() value: number = 0;
  @Input() type: string = "";
  @Input() inputDataArray: any[] = [];
  dataList: any[];
  settings: any = {};

  constructor() { }

  ngOnInit(): void {
    // switch(this.type){
    //   // case "SPEED":
    //   //   this.settings = {
    //   //     unit: 'm/s',
    //   //     gaugeType: 'arch',
    //   //     gaugeSize: '200',
    //   //     graphWidth: 400,
    //   //     graphHeight: 100,
    //   //     max: 500,
    //   //   };
    //   //   return
    //   case "BRAKE":
    //     this.settings = {
    //       unit: 'bar',
    //       gaugeType: 'arch',
    //       gaugeSize: '125',
    //       graphWidth: 200,
    //       graphHeight: 100,
    //       max: 3,
    //     };
    //     return
    //   case "TEMPERATURE":
    //     this.settings = {
    //       unit: '°C',
    //       gaugeType: 'semi',
    //       gaugeSize: '100',
    //       graphWidth: 200,
    //       graphHeight: 100,
    //       max: 100,
    //     };
    //     return
    //   default:
    //     return
    // }
  }

  ngOnChanges(): void {
  //   if (this.inputDataArray.length > 0){
  //     const dataMap = this.inputDataArray.map(({items, time}) => { 
  //       const value = items.filter((item)=> item._name === this.label)[0]._value
  //       return {x: time, y:value}
  //     })
  //     this.dataList = dataMap
  //   }
  }
}
