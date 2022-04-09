import { Component, OnInit } from '@angular/core';
import {WebsocketService} from '../../../services/websocket.service';

@Component({
  selector: 'app-gaugenvibration',
  templateUrl: './gauge-nvibration.component.html',
  styleUrls: ['./gauge-nvibration.component.css']
})
export class GaugeNvibrationComponent implements OnInit {

  constructor(private wsService: WebsocketService) { }

  ngOnInit(): void {
  }


  

}
