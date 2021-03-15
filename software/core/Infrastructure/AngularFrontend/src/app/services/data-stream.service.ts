import { Injectable } from '@angular/core';
import { BehaviorSubject } from 'rxjs';


@Injectable({
  providedIn: 'root'
})
export class DataStreamService {
  data: any = {}

  private dataSub = new BehaviorSubject<any>(this.data);
  currentData = this.dataSub.asObservable()
  constructor() { }

  updateData(data) {
    this.data = data
    this.dataSub.next(this.data)
  }
}
