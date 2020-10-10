import { Component, OnInit } from '@angular/core';

@Component({
  selector: 'app-ebar',
  templateUrl: './ebar.component.html',
  styleUrls: ['./ebar.component.css']
})
export class EbarComponent implements OnInit {
  options: any
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
        type: 'bar',
        barWidth: '60%',
        data: [10, 52, 200, 334, 390, 330, 220]
      }],
    };
  }

}
