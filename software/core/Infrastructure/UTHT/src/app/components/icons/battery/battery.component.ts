import { Component, OnInit, Input, AfterViewInit } from '@angular/core';

@Component({
  selector: 'battery-component',
  templateUrl: './battery.component.html'
})
export class BatteryPercentageComponent  {
	@Input() public color: string;
	@Input() public percentage: number;
	arrayColor = [];
	totalPin = 5;
	pinColor = '#efefed';

	constructor() {}

	ngOnInit() {
		this.color = '#3DCC93';
		this.percentage = 100;
		this.renderArrayColor();
	}

	renderArrayColor() {
		const part = 100 / this.totalPin;
		let currentLevel = 0 + part;
		for (let i = 0; i < this.totalPin; i++) {
			if (this.percentage >= currentLevel) {
				this.arrayColor.push({ full: true, color: this.color, width: '70px' });
				currentLevel += part;
			} else {
				const newWidth = ((this.percentage - currentLevel + part) * 70) / 20;
				this.arrayColor.push({ full: false, color: this.pinColor, width: newWidth + 'px' });
				for (let j = i + 1; j < this.totalPin; j++) {
					this.arrayColor.push({ full: true, color: this.pinColor, width: '70px' });
				}
				break;
			}
		}
	}

	public randomize(): void {
		this.arrayColor = []
		this.percentage -= 1;
		this.renderArrayColor();
        setTimeout(() => { this.randomize(); }, 200);
    }
}
