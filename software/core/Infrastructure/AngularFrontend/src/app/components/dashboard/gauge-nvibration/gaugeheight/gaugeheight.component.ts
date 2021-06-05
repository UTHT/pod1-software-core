import { Component, OnInit , Input} from '@angular/core';

@Component({
  selector: 'gauge-height',
  templateUrl: './gaugeheight.component.html',
  styleUrls: ['./gaugeheight.component.css']
})
export class GaugeheightComponent implements OnInit {
  @Input()
  speed: number;

  gaugeType = "arch";
  gaugeValue = 0;
  gaugeLabel = "Gap Height";
  gaugeAppendText = "-";
  constructor() { }

  ngOnInit(): void {
  }

}
