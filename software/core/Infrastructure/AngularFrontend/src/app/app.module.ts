import { BrowserModule } from '@angular/platform-browser';
import { NgModule } from '@angular/core';

import { NgxEchartsModule } from 'ngx-echarts'
import { ChartModule } from 'primeng/chart';
import * as echarts from 'echarts'

import { AppRoutingModule } from './app-routing.module';
import { AppComponent } from './app.component';
import { WebsocketComponent } from './components/websocket/websocket.component';
import { PrimengComponent } from './components/primeng/primeng.component';
import { LineComponent } from './components/democharts/line/line.component';
import { BarComponent } from './components/democharts/bar/bar.component';
import { DoughnutComponent } from './components/democharts/doughnut/doughnut.component';
import { RadarComponent } from './components/democharts/radar/radar.component';
import { LiveLineComponent } from './components/democharts/live-line/live-line.component';
import { NgxechartsComponent } from './components/ngxecharts/ngxecharts.component';
import { EbarComponent } from './components/democharts/ebar/ebar.component';
import { ElineComponent } from './components/democharts/eline/eline.component';
import { EpieComponent } from './components/democharts/epie/epie.component';
import { EradarComponent } from './components/democharts/eradar/eradar.component';
import { LiveElineComponent } from './components/democharts/live-eline/live-eline.component';

@NgModule({
  declarations: [
    AppComponent,
    WebsocketComponent,
    PrimengComponent,
    LineComponent,
    BarComponent,
    DoughnutComponent,
    RadarComponent,
    LiveLineComponent,
    NgxechartsComponent,
    EbarComponent,
    ElineComponent,
    EpieComponent,
    EradarComponent,
    LiveElineComponent,
  ],
  imports: [BrowserModule, AppRoutingModule, ChartModule, NgxEchartsModule.forRoot({echarts})],
  providers: [],
  bootstrap: [AppComponent],
})
export class AppModule {}
