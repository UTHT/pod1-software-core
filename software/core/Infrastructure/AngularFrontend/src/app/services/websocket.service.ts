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
          this.dataSub.next(this.data)
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
}
