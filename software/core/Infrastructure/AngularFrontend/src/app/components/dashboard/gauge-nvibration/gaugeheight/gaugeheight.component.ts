import { Component, OnInit } from '@angular/core';
import {WebsocketService} from '../../../../services/websocket.service';


@Component({
  selector: 'gauge-height',
  templateUrl: './gaugeheight.component.html',
  styleUrls: ['./gaugeheight.component.css']
})
export class GaugeheightComponent implements OnInit {

  speed: number;

  gaugeType = "arch";
  gaugeValue = 0;
  gaugeLabel = "Gap Height";
  gaugeAppendText = "";
  constructor(private wsService: WebsocketService) { }

  ngOnInit(): void {
    this.randomize();
  }

  randomize() {
    this.wsService.history.subscribe(historyArray => {
      if (historyArray && historyArray.length > 0){
        //console.log(historyArray);
        this.gaugeValue = historyArray[historyArray.length-1].obj.GAPHEIGHT[0]._value;
        
      }
    })
  }

}
