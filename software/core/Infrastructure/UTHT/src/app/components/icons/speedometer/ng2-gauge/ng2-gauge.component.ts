import { Component } from '@angular/core';

@Component({
    selector: 'ng2-gauge-component',
    templateUrl: './ng2-gauge.component.html'
})
export class Ng2GaugeComponent {
    input = 5000;
    max = 9000;
    sectors = [{
      from: 6500,
      to: 8000,
      color: 'orange'
    }, {
      from: 8000,
      to: 9000,
      color: 'red'
    }];
    public randomize(): void {

        this.input += Math.round(4* (Math.round(Math.random()) * 4 - 1));
        setTimeout(() => { this.randomize(); }, 50);
    }
}