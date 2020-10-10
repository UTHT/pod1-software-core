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
import { NgxChartsModule } from '@swimlane/ngx-charts';
import { LineChartComponent2 } from "./components/ngx-charts/line-chart/line-chart.component";
import { BarChartComponent2 } from "./components/ngx-charts/bar-chart/bar-chart.component";
import { DoughnutChartComponent2 } from "./components/ngx-charts/doughnut-chart/doughnut-chart.component";
import { BrowserAnimationsModule } from '@angular/platform-browser/animations';

@NgModule({
  declarations: [
    AppComponent,
    WebsocketComponent,
    LineChartComponent,
    BarChartComponent,
    DoughnutChartComponent,
    RadarChartComponent,
    ScatterChartComponent,
    LineChartComponent2,
    BarChartComponent2,
    DoughnutChartComponent2
  ],
  imports: [
    BrowserModule,
    AppRoutingModule,
    ChartsModule,
    NgxChartsModule,
    BrowserAnimationsModule
  ],
  providers: [],
  bootstrap: [AppComponent]
})
export class AppModule { }
