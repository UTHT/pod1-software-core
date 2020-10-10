import { Component, OnInit, ViewChild } from '@angular/core';
import { NgxChartsModule } from '@swimlane/ngx-charts';

var mult = [
  {
    "name": "1",
    "series": [
      {
        "name": "1",
        "value": 2
      },
      {
        "name": "2",
        "value": 4
      },
      {
        "name": "3",
        "value": 1
      }
    ]
  },

  {
    "name": "2",
    "series": [
      {
        "name": "1",
        "value": 5
      },
      {
        "name": "2",
        "value": 3
      },
      {
        "name": "3",
        "value": 7
      }
    ]
  }
];

@Component({
  selector: 'app-line-chart-2',
  templateUrl: './line-chart.component.html',
  //styleUrls: ['./line-chart.component.scss']
})
export class LineChartComponent2 implements OnInit {
  multi: any[] = mult;
  view: any[] = [700, 300];

  // options
  legend: boolean = true;
  showLabels: boolean = true;
  animations: boolean = true;
  xAxis: boolean = true;
  yAxis: boolean = true;
  showYAxisLabel: boolean = true;
  showXAxisLabel: boolean = true;
  xAxisLabel: string = 'X';
  yAxisLabel: string = 'Y';
  timeline: boolean = true;

  colorScheme = {
    domain: ['#5AA454', '#E44D25', '#CFC0BB', '#7aa3e5', '#a8385d', '#aae3f5']
  };

  ngOnInit() {
    console.log(this.multi)
  }

  onSelect(data): void {
    console.log('Item clicked', JSON.parse(JSON.stringify(data)));
  }

  onActivate(data): void {
    console.log('Activate', JSON.parse(JSON.stringify(data)));
  }

  onDeactivate(data): void {
    console.log('Deactivate', JSON.parse(JSON.stringify(data)));
  }

  public pushOne(): void {
    console.log(this.multi)
    this.multi[0].series.push({name : String(this.multi[0].series.length+1), value: Math.round(Math.random() * 10)});
    this.multi[1].series.push({name : String(this.multi[1].series.length+1), value: Math.round(Math.random() * 10)});
    this.multi = [...this.multi];
    setTimeout(() => { this.pushOne(); }, 1000);
  }
}