import { Component, OnInit, Input } from '@angular/core';

@Component({
  selector: 'app-podstate-item',
  templateUrl: './podstate-item.component.html',
  styleUrls: ['./podstate-item.component.css']
})
export class PodstateItemComponent implements OnInit {
  @Input() name: string;
  @Input() isActive: Boolean=false;
  @Input() isError: Boolean=false;

  constructor() { }

  ngOnInit(): void {
  }

}
