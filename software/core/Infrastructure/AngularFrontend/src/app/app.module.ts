import { BrowserModule } from '@angular/platform-browser';
import { NgModule } from '@angular/core';

import { AppRoutingModule } from './app-routing.module';
import { AppComponent } from './app.component';
import { WebsocketComponent } from './components/legacy/websocket/websocket.component';
import { ChartsModule } from 'ng2-charts';
import { LineChartComponent } from "./components/ng2-charts/line-chart/line-chart.component";
import { BarChartComponent } from "./components/ng2-charts/bar-chart/bar-chart.component";
import { DoughnutChartComponent } from "./components/ng2-charts/doughnut-chart/doughnut-chart.component";
import { RadarChartComponent } from "./components/ng2-charts/radar-chart/radar-chart.component";
import { ScatterChartComponent } from "./components/ng2-charts/scatter-chart/scatter-chart.component";
import { BrowserAnimationsModule } from '@angular/platform-browser/animations';
import { NgxGaugeComponent } from './components/icons/speedometer/ngx-gauge/ngx-gauge.component';
import { Ng2GaugeComponent } from './components/icons/speedometer/ng2-gauge/ng2-gauge.component';
import { NgxGaugeModule } from 'ngx-gauge';
import { Ng2GaugeModule } from 'ng2-gauge';
import { BatteryComponent } from './components/dashboard/battery/battery.component';
import { LayoutComponent } from './components/layout/layout.component';
import { SpeedComponent } from './components/dashboard/speed/speed.component';
import { SpeedGaugeComponent } from './components/dashboard/speed/speed-gauge/speed-gauge.component';
import { SpeedGraphComponent } from './components/dashboard/speed/speed-graph/speed-graph.component';
import { TemperatureComponent } from './components/dashboard/temperature/temperature.component';
import { TemperatureGaugeComponent } from './components/dashboard/temperature/temperature-gauge/temperature-gauge.component';
import { TemperatureGraphComponent } from './components/dashboard/temperature/temperature-graph/temperature-graph.component';
import { BrakeComponent } from './components/dashboard/brake/brake.component';
import { BrakeGaugeComponent } from './components/dashboard/brake/brake-gauge/brake-gauge.component';
import { BrakeGraphComponent } from './components/dashboard/brake/brake-graph/brake-graph.component';
import { PodstateComponent } from './components/podstate/podstate.component';
import { PodstateItemComponent } from './components/podstate-item/podstate-item.component';
import { SensorGroupComponent } from './components/sensor-group/sensor-group.component';
import { ControlsComponent } from './components/controls/controls.component';
import { SensorsComponent } from './components/sensors/sensors.component';
import { SensorItemComponent } from './components/sensor-item/sensor-item.component';
import { WebsocketService } from './services/websocket.service';
import { BrakesComponent } from './components/legacy/brakes/brakes.component';
import { BatteriesComponent } from './components/legacy/batteries/batteries.component';
import { TemperaturesComponent } from './components/legacy/temperatures/temperatures.component';
import { PositionComponent } from './components/dashboard/position/position.component';
import { MatProgressBarModule } from '@angular/material/progress-bar';
import { SwitchComponent } from './components/dashboard/switch/switch.component';
import { MatButtonModule } from '@angular/material/button';
import { LogsComponent } from './components/logs/logs.component';
import { GraphComponent } from './components/widgets/graph/graph.component';
import { GaugeComponent } from './components/widgets/gauge/gauge.component';
import { GaugeGraphComponent } from './components/widgets/gauge-graph/gauge-graph.component';
import { WidgetArrayComponent } from './components/widget-array/widget-array.component';

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
    BatteryComponent,
    LayoutComponent,
    SpeedComponent,
    SpeedGaugeComponent,
    SpeedGraphComponent,
    TemperatureComponent,
    TemperatureGaugeComponent,
    TemperatureGraphComponent,
    BrakeComponent,
    BrakeGaugeComponent,
    BrakeGraphComponent,
    LayoutComponent,
    PodstateComponent,
    PodstateItemComponent,
    SensorGroupComponent,
    ControlsComponent,
    SensorsComponent,
    SensorItemComponent,
    BrakesComponent,
    BatteriesComponent,
    TemperaturesComponent,
    PositionComponent,
    SwitchComponent,
    LogsComponent,
    GraphComponent,
    GaugeComponent,
    GaugeGraphComponent,
    WidgetArrayComponent
  ],
  imports: [
    BrowserModule,
    AppRoutingModule,
    ChartsModule,
    BrowserAnimationsModule,
    NgxGaugeModule,
    Ng2GaugeModule,
    MatProgressBarModule,
    MatButtonModule
  ],
  providers: [WebsocketService],
  bootstrap: [AppComponent]
})
export class AppModule { }
