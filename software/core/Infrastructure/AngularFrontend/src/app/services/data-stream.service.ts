import { Injectable } from '@angular/core';
import { BehaviorSubject } from 'rxjs';

@Injectable({
  providedIn: 'root',
})
export class DataStreamService {
  x: Array<any> = [];
  y: Array<any> = [];

  data: any = {
    labels: this.x,
    datasets: [
      {
        label: 'Mock Live Data',
        data: this.y,
        fill: false,
        borderColor: '#565656',
      },
    ],
  };
  private dataSub = new BehaviorSubject<any>(this.data);
  currentData = this.dataSub.asObservable();

  constructor() {}

  newY({ time, value }) {
    this.x.push(new Date(time * 1000).toLocaleString());
    this.y.push(value);

    const newData = {
      labels: this.x,
      datasets: [
        {
          label: 'Mock Live Data',
          data: this.y,
          fill: false,
          borderColor: '#565656',
        },
      ],
    };
    this.data = newData;
    this.dataSub.next(this.data);
  }
}
