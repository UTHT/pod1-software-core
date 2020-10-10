import { Component, OnInit, ViewChild } from '@angular/core';
import { NgxChartsModule } from '@swimlane/ngx-charts';

var single = [
  {
    "name": "Germany",
    "value": 8940000
  },
  {
    "name": "USA",
    "value": 5000000
  },
  {
    "name": "France",
    "value": 7200000
  }
];

@Component({
  selector: 'app-bar-chart-2',
  templateUrl: './bar-chart.component.html',
  //styleUrls: ['./bar-chart.component.scss']
})
export class BarChartComponent2 implements OnInit {
  single: any[] = single;

  view: any[] = [700, 400];

  // options
  showXAxis = true;
  showYAxis = true;
  gradient = false;
  showLegend = true;
  showXAxisLabel = true;
  xAxisLabel = 'Country';
  showYAxisLabel = true;
  yAxisLabel = 'Population';

  colorScheme = {
    domain: ['#5AA454', '#A10A28', '#C7B42C', '#AAAAAA']
  };

  ngOnInit() {
    console.log(this.single)
  }

  onSelect(event) {
    console.log(event);
  }

  public pushOne(): void {
    console.log(this.single)
    this.single[0].value = Math.round(Math.random() * 10);
    this.single[1].value = Math.round(Math.random() * 10);
    this.single[2].value = Math.round(Math.random() * 10);
    this.single = [...this.single];
    setTimeout(() => { this.pushOne(); }, 2000);
  }
}