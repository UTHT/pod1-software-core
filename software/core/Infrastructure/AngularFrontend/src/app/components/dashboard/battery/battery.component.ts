import { Component, OnInit, Input, AfterViewInit } from '@angular/core';
import {WebsocketService} from '../../../services/websocket.service';

@Component({
  selector: 'battery-component',
  templateUrl: './battery.component.html',
  styleUrls: ['./battery.component.css']
})
export class BatteryComponent implements OnInit {
	@Input() public color: string = '#3DCC93';
	@Input() public value: number = 100;
	@Input() public label: string = "battery label";
	@Input() idNum: string;
	arrayColor = [];
	totalPin = 5;
	pinColor = '#efefed';

	constructor(private wsService: WebsocketService) {}

	ngOnInit() {
		//this.renderArrayColor();
		 this.updateBatteryPercentage();
	}

	// ngOnChanges(){
	// 	this.renderArrayColor();
	// }

	renderArrayColor() {
		this.arrayColor = []
		const part = 100 / this.totalPin;
		let currentLevel = 0 + part;
		for (let i = 0; i < this.totalPin; i++) {
			if (this.value >= currentLevel) {
				this.arrayColor.push({ full: true, color: this.color, width: '30px' });
				currentLevel += part;
			} else {
				if (this.value != 0){
					const newWidth = ((this.value - currentLevel + part) * 30) / part;
					this.arrayColor.push({ full: false, color: this.pinColor, width: newWidth + 'px' });
				}else{
					this.arrayColor.push({ full: true, color: this.pinColor, width: '30px' });
				}
				for (let j = i + 1; j < this.totalPin; j++) {
					this.arrayColor.push({ full: true, color: this.pinColor, width: '30px' });
				}
				break;
			}
		}
	}

	public updateBatteryPercentage(): void {
		// if (Math.floor(Math.random() * 50)==0){
			// this.arrayColor = []	
			// this.value -= 1;
			// this.renderArrayColor();
		// }


		this.wsService.history.subscribe(historyArray => {
			if (historyArray && historyArray.length > 0){
			//   console.log(historyArray);
			//   this.currSpeed = historyArray[historyArray.length-1].obj.SPEED[0]._value;
			  this.value = historyArray[historyArray.length-1].obj.BATTERY[this.idNum]._value;
			  // if (this.count % 5000 == 0){
				// this.speedArray.push([this.value/1000,Math.floor(this.currSpeed)])
				// if (this.speedArray.length > 10){
				//   this.speedArray.shift();
				// }
			  // }
			}
			this.renderArrayColor();
		  })

        // setTimeout(() => { this.updateBatteryPercentage(); }, 200);
    }
}
