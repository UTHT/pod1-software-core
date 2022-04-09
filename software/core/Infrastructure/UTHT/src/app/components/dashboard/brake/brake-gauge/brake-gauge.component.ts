import { Component, Input } from '@angular/core';
 
@Component({
    selector: 'brake-gauge-component',
    templateUrl: './brake-gauge.component.html'
})
export class BrakeGaugeComponent {
    @Input() brakePressure: number;
    @Input() name: string;

    gaugeType = "arch";
    gaugeValue = 0;
    gaugeLabel = "";
    gaugeAppendText = "bar";

    ngOnInit() {
        this.gaugeValue = this.brakePressure;
        this.gaugeLabel = this.name;
        this.getBrakePressure();
    }
    getBrakePressure() {
        this.gaugeValue = Math.round(this.brakePressure * 10) / 10;
        setTimeout(() => { this.getBrakePressure(); }, 50);
    }
}