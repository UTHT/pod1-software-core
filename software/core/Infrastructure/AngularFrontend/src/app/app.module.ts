import { BrowserModule } from '@angular/platform-browser';
import { NgModule } from '@angular/core';

import { AppRoutingModule } from './app-routing.module';
import { AppComponent } from './app.component';
import { WebsocketComponent } from './components/websocket/websocket.component';
import { ChartsModule } from 'ng2-charts';
import { LineChartComponent } from "./components/ng2-charts/line-chart/line-chart.component";
import { BarChartComponent } from "./components/ng2-charts/bar-chart/bar-chart.component";
import { DoughnutChartComponent } from "./components/ng2-charts/doughnut-chart/doughnut-chart.component";
import { RadarChartComponent } from "./components/ng2-charts/radar-chart/radar-chart.component";
import { ScatterChartComponent } from "./components/ng2-charts/scatter-chart/scatter-chart.component";
import { BrowserAnimationsModule } from '@angular/platform-browser/animations';
import { NgxGaugeComponent } from './components/dashboard/speedometer/ngx-gauge/ngx-gauge.component';
import { Ng2GaugeComponent } from './components/dashboard/speedometer/ng2-gauge/ng2-gauge.component';
import { NgxGaugeModule } from 'ngx-gauge';
import { Ng2GaugeModule } from 'ng2-gauge';
import { BatteryPercentageComponent } from './components/dashboard/battery/battery.component';
import { LayoutComponent } from './components/layout/layout.component';
import { PodstateComponent } from './components/podstate/podstate.component';
import { PodstateItemComponent } from './components/podstate-item/podstate-item.component';

@NgModule({
  declarations: [
    AppComponent,
    WebsocketComponent,
    LineChartComponent,
    BarChartComponent,
    DoughnutChartComponent,
    RadarChartComponent,
    ScatterChartComponent,
    NgxGaugeComponent,
    Ng2GaugeComponent,
    BatteryPercentageComponent,
    LayoutComponent,
    PodstateComponent,
    PodstateItemComponent
  ],
  imports: [
    BrowserModule,
    AppRoutingModule,
    ChartsModule,
    BrowserAnimationsModule,
    NgxGaugeModule,
    Ng2GaugeModule
  ],
  providers: [],
  bootstrap: [AppComponent]
})
export class AppModule { }
