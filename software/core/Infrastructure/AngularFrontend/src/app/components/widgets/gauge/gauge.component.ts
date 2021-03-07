import { Component, OnInit, Input } from '@angular/core';

@Component({
  selector: 'app-gauge',
  templateUrl: './gauge.component.html',
  styleUrls: ['./gauge.component.css']
})
export class GaugeComponent implements OnInit {
  @Input() value: number = 0;
  @Input() label: string = "";
  @Input() unit: string = "";
  @Input() gaugeSize: number = 0;

  gaugeType = "arch";

  ngOnInit() {
  }
}
