import { Component, OnInit } from '@angular/core';

@Component({
  selector: 'app-epie',
  templateUrl: './epie.component.html',
  styleUrls: ['./epie.component.css']
})
export class EpieComponent implements OnInit {
  options: any;

  constructor() { }

  ngOnInit(): void {
    this.options = {
      legend: {
        data: ['A', 'B', 'C'],
        align: 'left',
      },
      series: [
        {
          name: 'demo',
          type: 'pie',
          data: [
            { value: 300, name: 'A' },
            { value: 50, name: 'B' },
            { value: 100, name: 'C' },
          ]
        }
      ]
    }
  }

}
