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

@NgModule({
  declarations: [
    AppComponent,
    WebsocketComponent,
    LineChartComponent,
    BarChartComponent,
    DoughnutChartComponent,
    RadarChartComponent,
    ScatterChartComponent
  ],
  imports: [
    BrowserModule,
    AppRoutingModule,
    ChartsModule
  ],
  providers: [],
  bootstrap: [AppComponent]
})
export class AppModule { }
