import { Component, OnInit } from '@angular/core';
import { DataStreamService } from '../../../services/data-stream.service';

@Component({
  selector: 'app-live-eline',
  templateUrl: './live-eline.component.html',
  styleUrls: ['./live-eline.component.css']
})
export class LiveElineComponent implements OnInit {
  options: any;
  updateOptions: any;

  constructor(private dsService: DataStreamService) { }

  ngOnInit(): void {
    this.options = {
      legend: {
        data: ['Mock live data'],
        align: 'left',
      },
      xAxis: [
        {
          type: 'category',
          data: [],
          axisTick: {
            alignWithLabel: true
          }
        }
      ],
      yAxis: [{
        type: 'value'
      }],
      series: [{
        name: 'Mock live data',
        type: 'line',
        barWidth: '60%',
        data: []
      }],
    };
    
    this.dsService.currentData.subscribe((newData) => {
      const x = newData.labels
      const y = newData.datasets[0].data
      this.updateOptions = {
        xAxis: [
          {
            data: x
          }
        ],
        series: [{
          data: y
        }]
      }
    })

  }

  

}
