import { Component, OnInit } from '@angular/core';

@Component({
  selector: 'app-podstate',
  templateUrl: './podstate.component.html',
  styleUrls: ['./podstate.component.css']
})
export class PodstateComponent implements OnInit {
  podstateData: any = {
    startup: [
      {name: 'Off', isActive: false, isError: false, css_position: 'topright' },
      {name: 'Debug Mode', isActive: false, isError: false, css_position: 'midleft'},
      {name: 'Comms Check', isActive: false, isError: false, css_position: 'midright'},
      {name: 'System Check', isActive: false, isError: false, css_position: 'bottomright'}
    ],
    shutdown: [
      {name: 'Shutdown', isActive: false, isError: false, css_position: 'topleft'},
    ],
    ready: [
      {name: 'Lock', isActive: false, isError: false, css_position: 'topright'},
      {name: 'Arms', isActive: false, isError: false, css_position: 'bottomright'},
    ],
    active: [
      {name: 'Braking', isActive: false, isError: false, css_position: 'topleft'},
      {name: 'Emergency Stop', isActive: false, isError: true, css_position: 'midright'},
      {name: 'Drive', isActive: false, isError: false, css_position: 'bottomleft'},
    ],
  }

  constructor() { }

  ngOnInit(): void {
  }

}
