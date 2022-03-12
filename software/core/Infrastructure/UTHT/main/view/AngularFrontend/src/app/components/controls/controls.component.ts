import { Component, OnInit } from '@angular/core';
import {WebsocketService} from '../../services/websocket.service';

@Component({
  selector: 'app-controls',
  templateUrl: './controls.component.html',
  styleUrls: ['./controls.component.css']
})
export class ControlsComponent implements OnInit {

  constructor(private wsService: WebsocketService) { }

  ngOnInit(): void {
  }

  onClick(){
    this.wsService.getMockData()
  }
}
