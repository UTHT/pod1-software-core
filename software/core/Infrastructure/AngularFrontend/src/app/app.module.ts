import { BrowserModule } from '@angular/platform-browser';
import { NgModule } from '@angular/core';

import { AppRoutingModule } from './app-routing.module';
import { AppComponent } from './app.component';
import { WebsocketComponent } from './components/websocket/websocket.component';
import { PrimengComponent } from './components/primeng/primeng.component';
import { LineComponent } from './components/democharts/line/line.component';
import { ChartModule } from 'primeng/chart';
import { BarComponent } from './components/democharts/bar/bar.component';
import { DoughnutComponent } from './components/democharts/doughnut/doughnut.component';
import { RadarComponent } from './components/democharts/radar/radar.component';

@NgModule({
  declarations: [
    AppComponent,
    WebsocketComponent,
    PrimengComponent,
    LineComponent,
    BarComponent,
    DoughnutComponent,
    RadarComponent,
  ],
  imports: [BrowserModule, AppRoutingModule, ChartModule],
  providers: [],
  bootstrap: [AppComponent],
})
export class AppModule {}
