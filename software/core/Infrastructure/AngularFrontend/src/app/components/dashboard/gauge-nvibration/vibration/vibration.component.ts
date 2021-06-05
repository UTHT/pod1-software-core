import { Component, OnInit , Input} from '@angular/core';

@Component({
  selector: 'vibration-gauge',
  templateUrl: './vibration.component.html',
  styleUrls: ['./vibration.component.css']
})
export class VibrationComponent implements OnInit {
  @Input()
  speed: number;

  gaugeType = "arch";
  gaugeValue = 0;
  gaugeLabel = "Vibration";
  gaugeAppendText = "-";

  constructor() { }

  ngOnInit(): void {
  }

}
