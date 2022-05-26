import { Component, Input } from '@angular/core';
 
@Component({
    selector: 'temperature-gauge-component',
    templateUrl: './temperature-gauge.component.html'
})
export class TemperatureGaugeComponent {
    @Input() temperature: number;
    @Input() name: string;

    gaugeType = "semi";
    gaugeValue = 0;
    gaugeLabel = "";
    gaugeAppendText = "°C";

    ngOnInit() {
        this.gaugeValue = this.temperature;
        this.gaugeLabel = this.name;
        this.getTemperature();
    }
    getTemperature() {
        this.gaugeValue = this.temperature | 0;
        setTimeout(() => { this.getTemperature(); }, 50);
    }
}