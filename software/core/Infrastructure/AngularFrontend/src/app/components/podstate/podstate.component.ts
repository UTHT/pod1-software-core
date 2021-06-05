import { Component, OnInit } from '@angular/core';

@Component({
  selector: 'app-podstate',
  templateUrl: './podstate.component.html',
  styleUrls: ['./podstate.component.css']
})
export class PodstateComponent implements OnInit {
  //Fixed display properties for each group of items
  stateGroupMap: any = {
    startup: {
      title: 'Startup',
      layout: 'two-row'
    },
    shutdown: {
      title: 'Shutdown',
      layout: 'two-row'
    },
    ready: {
      title: 'Ready',
      layout: 'two-row'
    },
    active: {
      title: 'Active',
      layout: 'two-row'
    },
  }
  
  //Fixed display properties of each podstate item
  itemPropsMap: any = {
    off: {
      title: 'Off',
      position: 'topright'
    },
    debug: {
      title: 'Debug Mode',
      position: 'midright'
    },
    // comms: {
    //   title: 'Comms Check',
    //   position: 'midright'
    // },
    // system: {
    //   title: 'System Check',
    //   position: 'bottomright'
    // },
    shutdown: {
      title: 'Shutdown',
      position: 'topright'
    },
    lock: {
      title: 'Lock',
      position: 'topright'
    },
    arms: {
      title: 'Arms',
      position: 'bottomright'
    },
    braking:{
      title: 'Braking',
      position: 'bottomleft'
    },  
    emergency: {
      title: 'Emergency Stop',
      position: 'topright'
    },
    drive: {
      title: 'Drive',
      position: 'bottomright'
    }
  }

  //Pod state data variable to be updated as data comes in
  podstateData: any[] = [{
    name: 'startup', 
    items:  [
      {name: 'off', isActive: false, isError: false, },
      {name: 'debug',  isActive: false, isError: false, },
      // {name: 'comms', isActive: false, isError: false, },
      // {name: 'system',  isActive: false, isError: false, }
    ]},
    {
      name: 'shutdown',
      items: [
        {name: 'shutdown',  isActive: false, isError: false},
      ]
    },
    {
      name: 'ready',
      
      items:[
        {name: 'lock',  isActive: false, isError: false },
        {name: 'arms',  isActive: false, isError: false},
      ]
    },
    {
      name: 'active',
      items:[
        {name: 'braking', isActive: false, isError: false, },
        {name: 'emergency', isActive: false, isError: true, },
        {name: 'drive',  isActive: false, isError: false, },
      ]
    }]

  constructor() { }

  ngOnInit(): void {
  }

}
