import { Component, Input, OnInit, ViewChild } from '@angular/core';
import { ChartDataSets, ChartOptions, ChartType } from 'chart.js';
import { Color, BaseChartDirective, Label } from 'ng2-charts';
import * as pluginDataLabels from 'chartjs-plugin-datalabels';


@Component({
  selector: 'app-graph',
  templateUrl: './graph.component.html',
  styleUrls: ['./graph.component.css']
})
export class GraphComponent implements OnInit {
  @Input() dataList: any[];
  @Input() settings: any;

  public lineChartData: ChartDataSets[] = [{ data: [], fill:false, pointStyle:'line'}];
  public lineChartLabels: Label[] = [];
  public lineChartOptions: (ChartOptions) = {
    responsive: true,
    scales: {
      xAxes: [
        {
          type: 'time',
          distribution: 'linear',
          time: {
            unit: "second",
            displayFormats: {
              second: 'h:mm:ss'
          }
          },
          ticks:{
            autoSkipPadding: 20,
          }
        }
      ],
      yAxes: [
        {
          position: 'left',
          ticks:{
            autoSkipPadding: 20,
            min: 0,
            max: 3,
          }
        }
      ]
    },
    maintainAspectRatio: false,
    elements:{
      line:{
        tension:0
      }
    },
    legend: {
      display: false
    },
    animation:{
      duration: 0
    },
    plugins: {
      datalabels: {
        display: false,
      }
    }
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
  public lineChartPlugins = [pluginDataLabels];

  @ViewChild(BaseChartDirective, { static: true }) chart: BaseChartDirective;

  constructor() { }

  ngOnInit(): void {
    this.lineChartData[0].data = this.dataList
    this.lineChartOptions.scales.yAxes[0].ticks.max = this.settings.max
  }
}
