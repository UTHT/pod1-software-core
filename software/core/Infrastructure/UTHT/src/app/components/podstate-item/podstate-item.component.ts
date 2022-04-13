import { Component, OnInit, Input } from '@angular/core';

@Component({
  selector: 'app-podstate-item',
  templateUrl: './podstate-item.component.html',
  styleUrls: ['./podstate-item.component.css']
})
export class PodstateItemComponent implements OnInit {
  @Input() title: string;
  @Input() isActive: Boolean =false;
  @Input() isError: Boolean;

  constructor() { }

  ngOnInit(): void {
  }

  toggleActive(): void {
    this.isActive = !this.isActive
  }
}
