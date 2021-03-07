import { fakeAsync, flush, TestBed, tick } from '@angular/core/testing';
import { Location } from "@angular/common";
import { RouterTestingModule } from '@angular/router/testing';
import { AppComponent } from './app.component';
import { Router } from '@angular/router';
import { LayoutComponent } from './components/layout/layout.component';
import { LogsComponent } from './components/logs/logs.component';

describe('AppComponent', () => {
  beforeEach(async () => {
    await TestBed.configureTestingModule({
      imports: [
        RouterTestingModule
      ],
      declarations: [
        AppComponent
      ],
    }).compileComponents();
  });

  it('should create the app', () => {
    const fixture = TestBed.createComponent(AppComponent);
    const app = fixture.componentInstance;
    expect(app).toBeTruthy();
  });

  it(`should have as title 'AngularFrontend'`, () => {
    const fixture = TestBed.createComponent(AppComponent);
    const app = fixture.componentInstance;
    expect(app.title).toEqual('AngularFrontend');
  });
});

// see https://codecraft.tv/courses/angular/unit-testing/routing/ for how these unit tests work
describe('Router: App', () => {

  let location: Location;
  let router: Router;

  beforeEach(() => {
    TestBed.configureTestingModule({
      imports: [RouterTestingModule.withRoutes([
        {
          path: '',
          pathMatch: 'full',
          component: LayoutComponent
        },
        {
          path: 'logs',
          component: LogsComponent
        }
      ])],
      declarations: [
        LayoutComponent,
        LogsComponent,
        AppComponent
      ]
    });

    router = TestBed.get(Router);
    location = TestBed.get(Location);
  
    const fixture = TestBed.createComponent(AppComponent);
    router.initialNavigation();
  });

  it("fakeAsync works", fakeAsync(() => {
    let promise = new Promise(resolve => {
      setTimeout(resolve, 10);
    });
    let done = false;
    promise.then(() => (done = true));
    tick(50);
    expect(done).toBeTruthy();
  }));

  it('navigate to "" redirects you to /', fakeAsync(() => {
    router.navigate([""]).then(() => {
      expect(location.path()).toBe("/");
    });
  }));

  it('navigate to "logs" takes you to /logs', fakeAsync(() => {
    router.navigate(["/logs"]).then(() => {
      expect(location.path()).toBe("/logs");
    });
    flush(); // required for last unit test using fakeAsync
  }));
});