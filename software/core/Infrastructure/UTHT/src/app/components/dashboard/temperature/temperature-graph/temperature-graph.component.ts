import { Component, Input, OnInit, ViewChild } from '@angular/core';
import { ChartDataSets, ChartOptions, ChartType } from 'chart.js';
import { Color, BaseChartDirective, Label } from 'ng2-charts';
import * as pluginAnnotations from 'chartjs-plugin-annotation';

@Component({
  selector: 'temperature-graph',
  templateUrl: './temperature-graph.component.html',
  //styleUrls: ['./line-chart.component.scss']
})
export class TemperatureGraphComponent implements OnInit {
  @Input()
  dataList: Object;

  public lineChartData: ChartDataSets[] = [{ data: [] }];
  public lineChartLabels: Label[] = [];
  public lineChartOptions: (ChartOptions & { annotation: any }) = {
    responsive: true,
    scales: {
      xAxes: [{}],
      yAxes: [
        {
          id: 'y-axis-0',
          position: 'left',
        }
      ]
    },
    annotation: {
      annotations: [
        {
          type: 'line',
          mode: 'vertical',
          scaleID: 'x-axis-0',
          value: 'March',
          borderColor: 'orange',
          borderWidth: 2,
          label: {
            enabled: true,
            fontColor: 'orange',
            content: 'LineAnno'
          }
        },
      ],
    },
  };
  public lineChartColors: Color[] = [
    {
      backgroundColor: 'rgba(0, 255, 0, 0.3)',
      borderColor: 'green',
      pointBackgroundColor: 'rgba(148,159,177,1)',
      pointBorderColor: '#fff',
      pointHoverBackgroundColor: '#fff',
      pointHoverBorderColor: 'rgba(148,159,177,0.8)'
    }
  ];
  public lineChartLegend = false;
  public lineChartType: ChartType = 'line';
  public lineChartPlugins = [pluginAnnotations];

  @ViewChild(BaseChartDirective, { static: true }) chart: BaseChartDirective;

  constructor() { }

  ngOnInit(): void {
    this.getTemperatureArray();
  }

  processLineChartData(dataList) {
    var a = [], b = [];
    dataList.forEach(function (point) {
      a.push(point[1].toString());
      b.push(point[0]);
    });
    this.lineChartData[0].data = a;
    this.lineChartLabels = b;
  }

  getTemperatureArray() {
    this.processLineChartData(this.dataList);
    setTimeout(() => { this.getTemperatureArray(); }, 50);
  }
}