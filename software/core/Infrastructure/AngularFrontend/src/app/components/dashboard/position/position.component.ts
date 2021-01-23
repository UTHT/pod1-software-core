import { Component } from '@angular/core';

/**
 * @title Determinate progress-bar
 */
@Component({
    selector: 'position-component',
    templateUrl: './position.component.html',
})
export class PositionComponent {
    mode = 'buffer';
    position = 0;

    ngOnInit(): void {
        this.updatePosition();
    }

    updatePosition() {
        this.position += 1;
        // update every 1s
        setTimeout(() => { this.updatePosition(); }, 1000);
    }
}