import { Component, OnInit } from '@angular/core';

@Component({
  selector: 'app-eline',
  templateUrl: './eline.component.html',
  styleUrls: ['./eline.component.css']
})
export class ElineComponent implements OnInit {
  options: any;


  constructor() { }

  ngOnInit(): void {
    this.options = {
      legend: {
        data: ['demo'],
        align: 'left',
      },
      xAxis: [
        {
          type: 'category',
          data: ['Mon', 'Tue', 'Wed', 'Thu', 'Fri', 'Sat', 'Sun'],
          axisTick: {
            alignWithLabel: true
          }
        }
      ],
      yAxis: [{
        type: 'value'
      }],
      series: [{
        name: 'demo',
        type: 'line',
        barWidth: '60%',
        data: [10, 52, 200, 334, 390, 330, 220]
      }],
    };
  
  }

}
