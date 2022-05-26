import { Component, OnInit } from '@angular/core';
import {WebsocketService} from '../../services/websocket.service';


enum ButtonType{
  Start = 0,
  Drive = 1,
  Emergency_button = 2
}


@Component({
  selector: 'app-controls',
  templateUrl: './controls.component.html',
  styleUrls: ['./controls.component.css']
})
export class ControlsComponent implements OnInit {


  constructor(private wsService: WebsocketService) { }

  ngOnInit(): void {
  }

  onClickStart(){
    this.wsService.sendButtonData(ButtonType.Start)
  }

  onClickDrive(){
    this.wsService.sendButtonData(ButtonType.Drive)
  }

  onClickEmergency(){
    this.wsService.sendButtonData(ButtonType.Emergency_button)
  }
}
