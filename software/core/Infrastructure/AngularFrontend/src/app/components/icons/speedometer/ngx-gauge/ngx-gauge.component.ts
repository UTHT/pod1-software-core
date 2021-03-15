import { Component } from '@angular/core';
 
@Component({
    selector: 'ngx-gauge-component',
    templateUrl: './ngx-gauge.component.html'
})
export class NgxGaugeComponent {
    
    gaugeType = "semi";
    gaugeValue = 28.3;
    gaugeLabel = "Speed";
    gaugeAppendText = "km/hr";

    public randomize(): void {

        this.gaugeValue += 0.1*(Math.round(Math.random()) * 4 - 1);
        setTimeout(() => { this.randomize(); }, 50);
    }
}