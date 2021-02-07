import { Injectable } from '@angular/core';
import { BehaviorSubject } from 'rxjs'

@Injectable({
  providedIn: 'root'
})
export class WebsocketService {
  websocket: WebSocket;
  private data: any = {}
  //global store of the history
  public dataHistory: any[] = [];
  private dataSub = new BehaviorSubject<any>(this.dataHistory);
  public history = this.dataSub.asObservable();

  constructor() { }

  //connect method to initialize connection to the server (call once)
  public connect(){
    this.websocket = new WebSocket("ws://localhost:8080");
    
    this.websocket.onopen = event => { 
      //Any clients during connection to the websocket must send this connection event!!!
      this.websocket.send(JSON.stringify({eventType: 'connection', data: {clientType: 'dashboard'}}))
    }

    this.websocket.onmessage = event => {
      const {eventType, data} = JSON.parse(event.data)

      //Handle messages that are coming in, evenType struture will be enforced
      switch (eventType) {
        case 'init':
          this.websocket.send(JSON.stringify({eventType: 'mock_request'}))
          return
        default:
          this.data = data
          this.data.time = new Date()
          this.dataHistory.push(this.data)
          if (this.dataHistory.length > 20){
            this.dataHistory.shift()
          }
          this.dataSub.next(this.dataHistory)
          return
      }
    }

    this.websocket.onclose = event => { 
      //Todo: handle event when the server come down (trying to reconnect / display server is disconnected)
      console.log('disconnected')
    }
  }

  public getMockData(){
    this.websocket.send(JSON.stringify({eventType: 'mock_request'}))
  }

  public getDataHistory(){
    return this.dataHistory
  } 
}
