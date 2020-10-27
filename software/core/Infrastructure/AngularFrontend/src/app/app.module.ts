import { BrowserModule } from '@angular/platform-browser';
import { NgModule } from '@angular/core';

import { AppRoutingModule } from './app-routing.module';
import { AppComponent } from './app.component';
import { WebsocketComponent } from './components/websocket/websocket.component';
import { TestModuleComponent } from './components/test-module/test-module.component';

@NgModule({
  declarations: [
    AppComponent,
    WebsocketComponent,
    TestModuleComponent
  ],
  imports: [
    BrowserModule,
    AppRoutingModule
  ],
  providers: [],
  bootstrap: [AppComponent]
})
export class AppModule { }
