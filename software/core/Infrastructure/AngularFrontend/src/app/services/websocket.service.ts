import { Injectable } from '@angular/core';
import { BehaviorSubject } from 'rxjs'

@Injectable({
  providedIn: 'root'
})
export class WebsocketService {
  websocket: WebSocket;
  private data: any = {}
  private dataSub = new BehaviorSubject<any>(this.data);
  public serverMessage = this.dataSub.asObservable();

  constructor() { }

  public connect(){
    this.websocket = new WebSocket("ws://localhost:8080");
    
    this.websocket.onopen = event => { 
      this.websocket.send(JSON.stringify({eventType: 'connection', data: {clientType: 'dashboard'}}))
    }

    this.websocket.onmessage = event => {
      const {eventType, data} = JSON.parse(event.data)
      // console.log(eventType, data)
      
      switch (eventType) {
        case 'init':
          this.websocket.send(JSON.stringify({eventType: 'mock_request'}))
          return
        default:
          this.data = data
          this.dataSub.next(this.data)
          return
      }

      
      // const newData = JSON.parse(event.data)
      // console.log(newData)
      // this.data = newData
      //  this.dataSub.next(this.data)
    }

    this.websocket.onclose = event => { 
      console.log('disconnected')
    }
  }

  public getMockData(){
    this.websocket.send(JSON.stringify({eventType: 'mock_request'}))
  }
}
