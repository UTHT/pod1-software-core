import { Component, OnInit } from '@angular/core';

@Component({
  selector: 'app-eradar',
  templateUrl: './eradar.component.html',
  styleUrls: ['./eradar.component.css']
})
export class EradarComponent implements OnInit {
  options: any;
  constructor() { }

  ngOnInit(): void {
    this.options = {
      legend: {
        data: ['Budget', 'Spending'],
        align: 'left',
      },
      radar: {
        name: {
            textStyle: {
                color: '#fff',
                backgroundColor: '#999',
                borderRadius: 3,
                padding: [3, 5]
            }
        },
        indicator: [
            { name: 'Sales', max: 6500},
            { name: 'Admin', max: 16000},
            { name: 'It', max: 30000},
            { name: 'Customer support', max: 38000},
            { name: 'Development', max: 52000},
            { name: 'Marketing', max: 25000}
        ]
    },
    series: [{
        name: 'Budget vs spending',
        type: 'radar',
        // areaStyle: {normal: {}},
        data: [
            {
                value: [4300, 10000, 28000, 35000, 50000, 19000],
                name: 'Budget'
            },
            {
                value: [5000, 14000, 28000, 31000, 42000, 21000],
                name: 'Spending'
            }
        ]
    }]
    }
  }

}
