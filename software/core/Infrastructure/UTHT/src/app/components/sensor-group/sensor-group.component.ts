import { Component, OnInit, Input } from '@angular/core';

@Component({
  selector: 'app-sensor-group',
  templateUrl: './sensor-group.component.html',
  styleUrls: ['./sensor-group.component.css']
})
export class SensorGroupComponent implements OnInit {
  @Input() title: string;

  @Input() data: any[];

  constructor() { } 

  ngOnInit(): void {
  }
}
