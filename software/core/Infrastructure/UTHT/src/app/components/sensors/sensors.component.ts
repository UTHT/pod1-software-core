import { Component, OnInit } from '@angular/core';

@Component({
  selector: 'app-sensors',
  templateUrl: './sensors.component.html',
  styleUrls: ['./sensors.component.css']
})
export class SensorsComponent implements OnInit {

  dataFront = [
    {
      id: 'F1',
      state: 'inactive'
    },
    {
      id: 'F2',
      state: 'active'
    },
    {
      id: 'F3',
      state: 'active'
    },
    {
      id: 'F4',
      state: 'error'
    },
    {
      id: 'F5',
      state: 'active'
    },
    {
      id: 'F6',
      state: 'active'
    },
  ]

  dataBack = [
    {
      id: 'B1',
      state: 'active'
    },
    {
      id: 'B2',
      state: 'error'
    },
    {
      id: 'B3',
      state: 'active'
    },
    {
      id: 'B4',
      state: 'error'
    },
    {
      id: 'B5',
      state: 'active'
    },
    {
      id: 'B6',
      state: 'inactive'
    },
  ]

  dataLeft = [
    {
      id: 'L1',
      state: 'inactive'
    },
    {
      id: 'L2',
      state: 'inactive'
    },
    {
      id: 'L3',
      state: 'active'
    },
    {
      id: 'L4',
      state: 'error'
    },
    {
      id: 'L5',
      state: 'error'
    },
    {
      id: 'L6',
      state: 'error'
    },
  ]

  dataRight = [
    {
      id: 'R1',
      state: 'active'
    },
    {
      id: 'R2',
      state: 'active'
    },
    {
      id: 'R3',
      state: 'active'
    },
    {
      id: 'R4',
      state: 'active'
    },
    {
      id: 'R5',
      state: 'active'
    },
    {
      id: 'R6',
      state: 'active'
    },
  ]

  constructor() { }

  ngOnInit(): void {
  }

}
