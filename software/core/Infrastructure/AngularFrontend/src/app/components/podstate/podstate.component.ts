import { Component, OnInit } from '@angular/core';

@Component({
  selector: 'app-podstate',
  templateUrl: './podstate.component.html',
  styleUrls: ['./podstate.component.css']
})
export class PodstateComponent implements OnInit {
  podstateData: any = {
    startup: [
      {name: 'Off', isActive: false, css_position: 'topright' },
      {name: 'Debug Mode', isActive: false, css_position: 'midleft'},
      {name: 'Comms Check', isActive: false, css_position: 'midright'},
      {name: 'System Check', isActive: false, css_position: 'bottomright'}
    ],
    shutdown: [
      {name: 'Shutdown', isActive: false, css_position: 'topleft'},
    ],
    ready: [
      {name: 'Lock', isActive: false, css_position: 'topright'},
      {name: 'Arms', isActive: false, css_position: 'bottomright'},
    ],
    active: [
      {name: 'Braking', isActive: false, css_position: 'topleft'},
      {name: 'Emergency Stop', isActive: false, css_position: 'midright'},
      {name: 'Drive', isActive: false, css_position: 'bottomleft'},
    ],
  }

  constructor() { }

  ngOnInit(): void {
  }

}
