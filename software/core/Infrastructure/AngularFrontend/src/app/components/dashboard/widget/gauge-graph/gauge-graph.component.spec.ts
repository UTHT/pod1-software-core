import { ComponentFixture, TestBed } from '@angular/core/testing';

import { GaugeGraphComponent } from './gauge-graph.component';

describe('GaugeGraphComponent', () => {
  let component: GaugeGraphComponent;
  let fixture: ComponentFixture<GaugeGraphComponent>;

  beforeEach(async () => {
    await TestBed.configureTestingModule({
      declarations: [ GaugeGraphComponent ]
    })
    .compileComponents();
  });

  beforeEach(() => {
    fixture = TestBed.createComponent(GaugeGraphComponent);
    component = fixture.componentInstance;
    fixture.detectChanges();
  });

  it('should create', () => {
    expect(component).toBeTruthy();
  });
});
