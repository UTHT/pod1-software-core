import { Injectable } from '@angular/core';
import { BehaviorSubject } from 'rxjs';

@Injectable({
  providedIn: 'root',
})
export class DataStreamService {
  x: Array<any> = ['may', 'june'];
  y: Array<any> = [10, 20];

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
}
