import { Component, OnInit, Input } from '@angular/core';

@Component({
  selector: 'app-sensor-group',
  templateUrl: './sensor-group.component.html',
  styleUrls: ['./sensor-group.component.css']
})
export class SensorGroupComponent implements OnInit {
  @Input() title: string;

  fakeData:any[] = [
    {
    id: 'j1',
    state: 'inactive'
  },
    {
    id: 'j2',
    state: 'active'
  },
    {
    id: 'j3',
    state: 'active'
  },
    {
    id: 'j4',
    state: 'error'
  },
    {
    id: 'j5',
    state: 'active'
  },
    {
    id: 'j6',
    state: 'active'
  },
  ]

  constructor() { } 

  ngOnInit(): void {
  }
}
