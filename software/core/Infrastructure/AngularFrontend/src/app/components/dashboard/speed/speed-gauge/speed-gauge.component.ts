import { Component } from '@angular/core';
 
@Component({
    selector: 'speed-gauge-component',
    templateUrl: './speed-gauge.component.html'
})
export class SpeedGaugeComponent {
    
    gaugeType = "arch";
    gaugeValue = 0
    gaugeLabel = "Speed";
    gaugeAppendText = "km/h";

    // public randomize(): void {

    //     this.gaugeValue += 0.1*(Math.round(Math.random()) * 4 - 1);
    //     setTimeout(() => { this.randomize(); }, 50);
    // }
}