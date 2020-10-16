import { Component, OnInit } from '@angular/core';
import { DataStreamService } from '../../../services/data-stream.service';

@Component({
  selector: 'app-live-line',
  templateUrl: './live-line.component.html',
  styleUrls: ['./live-line.component.css'],
})
export class LiveLineComponent implements OnInit {
  x: Array<any> = [];
  y: Array<any> = [];

  data: any = {
    labels: [],
    datasets: [
      {
        label: 'Mock Live Data',
        data: [],
        fill: false,
        borderColor: '#565656',
      },
    ],
  };
  options: any;

  constructor(private dsService: DataStreamService) {
    this.options = {
      elements: { line: { tension: 0 } },
      animation: { duration: 0 },
    };
  }

  ngOnInit(): void {
    this.dsService.currentData.subscribe((newData) => {
      const updatedData = {
        labels: newData.x,
        datasets: [
          {
            label: 'Mock Live Data',
            data: newData.y,
            fill: false,
            borderColor: '#565656',
          },
        ],
      };

      this.data = updatedData;
    });
  }
}
