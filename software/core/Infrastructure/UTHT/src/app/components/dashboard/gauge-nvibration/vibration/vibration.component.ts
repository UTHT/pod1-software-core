import { Component, OnInit } from '@angular/core';
import {WebsocketService} from '../../../../services/websocket.service';

@Component({
  selector: 'vibration-gauge',
  templateUrl: './vibration.component.html',
  styleUrls: ['./vibration.component.css']
})
export class VibrationComponent implements OnInit {

  speed: number;

  vibrationType = "arch";
  vibrationValue = 0;
  vibrationLabel = "Vibration";
  vibrationAppendText = "";

  constructor(private wsService: WebsocketService) { }

  ngOnInit(): void {
    this.randomize();
  }

  randomize() {
    this.wsService.history.subscribe(historyArray => {
      if (historyArray && historyArray.length > 0){
        //console.log(historyArray);
        this.vibrationValue = historyArray[historyArray.length-1].obj.VIBRATION[0]._value;
        
      }
    })
  }

}
