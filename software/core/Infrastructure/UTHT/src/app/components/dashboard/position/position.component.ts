import { Component, Input } from '@angular/core';

/**
 * @title Determinate progress-bar
 */
@Component({
    selector: 'position-component',
    templateUrl: './position.component.html',
})
export class PositionComponent {
    mode = 'determinate';
    color = 'warn';
    @Input() public position: number = 0;

    ngOnInit(): void {
        //this.updatePosition();
    }

    updatePosition() {
        this.position += 0.1;
        // update every 0.1s
        setTimeout(() => { this.updatePosition(); }, 100);
    }
}