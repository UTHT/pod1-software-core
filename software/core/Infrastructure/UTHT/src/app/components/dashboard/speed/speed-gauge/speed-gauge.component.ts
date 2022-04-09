import { Component, Input } from '@angular/core';
 
@Component({
    selector: 'speed-gauge-component',
    templateUrl: './speed-gauge.component.html'
})
export class SpeedGaugeComponent {
    @Input()
    speed: number;

    gaugeType = "arch";
    gaugeValue = 0;
    gaugeLabel = "Speed";
    gaugeAppendText = "km/h";

    ngOnInit() {
        this.gaugeValue = this.speed;
        this.getSpeed();
    }
    getSpeed() {
        this.gaugeValue = this.speed | 0;
        setTimeout(() => { this.getSpeed(); }, 50);
    }
}