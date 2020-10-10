import { Component, OnInit, ViewChild } from '@angular/core';
import { NgxChartsModule } from '@swimlane/ngx-charts';

var single = [
  {
    "name": "Germany",
    "value": 8940000
  },
  {
    "name": "USA",
    "value": 5000000
  },
  {
    "name": "France",
    "value": 7200000
  }
];

@Component({
  selector: 'app-doughnut-chart-2',
  templateUrl: './doughnut-chart.component.html',
  //styleUrls: ['./doughnut-chart.component.scss']
})
export class DoughnutChartComponent2 implements OnInit {
  single: any[] = single;

  view: any[] = [700, 400];

  // options
  gradient: boolean = true;
  showLegend: boolean = true;
  showLabels: boolean = true;
  isDoughnut: boolean = false;
  legendPosition: string = 'below';

  colorScheme = {
    domain: ['#5AA454', '#A10A28', '#C7B42C', '#AAAAAA']
  };

  ngOnInit() {
  }

  onSelect(data): void {
    console.log('Item clicked', JSON.parse(JSON.stringify(data)));
  }

  onActivate(data): void {
    console.log('Activate', JSON.parse(JSON.stringify(data)));
  }

  onDeactivate(data): void {
    console.log('Deactivate', JSON.parse(JSON.stringify(data)));
  }

  public pushOne(): void {
    console.log(this.single)
    this.single[0].value = Math.round(Math.random() * 10);
    this.single[1].value = Math.round(Math.random() * 10);
    this.single[2].value = Math.round(Math.random() * 10);
    this.single = [...this.single];
    setTimeout(() => { this.pushOne(); }, 2000);
  }
}