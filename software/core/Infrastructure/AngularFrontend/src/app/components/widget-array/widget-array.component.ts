import { Component, OnInit, Input } from '@angular/core';
import { WebsocketService } from '../../services/websocket.service'

@Component({
  selector: 'app-widget-array',
  templateUrl: './widget-array.component.html',
  styleUrls: ['./widget-array.component.css']
})
export class WidgetArrayComponent implements OnInit {
  @Input() type: string;
  dataArray: any[] = []
  data: any[] = [
    {_name: "N/A", _value: 0},
  ]
  unit: string;

  constructor(private wsService: WebsocketService) { }

  ngOnInit(): void {
    this.wsService.history.subscribe(historyArray => {
      const mapping = historyArray.map(({obj, time}) => { 
        if (obj){
          const items = obj[this.type];  
          return {items, time}
        }
      })
      this.dataArray = mapping;

      if (historyArray.length > 0) {
        const currentObject = historyArray[historyArray.length - 1];
        const data = currentObject.obj[this.type];
        this.data = data
      }
    })
  }
}
