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

    component.label = "Test label";
    component.value = 5;
    component.type = "SPEED";
    component.inputDataArray = [1,2,3,4,5];

    fixture.detectChanges();
  });

  it('should create', () => {
    expect(component).toBeTruthy();
  });

  it('should be defined', () => {
    expect(component.label).toBeDefined();
    expect(component.value).toBeDefined();
    expect(component.type).toBeDefined();
    expect(component.inputDataArray).toBeDefined();
  })

  it('should match input', () => {
    expect(component.label).toEqual("Test label");
    expect(component.value).toEqual(5);
    expect(component.type).toEqual("SPEED");
    expect(component.inputDataArray).toEqual([1,2,3,4,5]);
  })

  it('shoud match expect output settings', () => {
    expect(component.settings.unit).toEqual('m/s');
    expect(component.settings.gaugeType).toEqual('arch');
    expect(component.settings.gaugeSize).toEqual('200');
    expect(component.settings.graphWidth).toEqual(400);
    expect(component.settings.graphHeight).toEqual(100);
    expect(component.settings.max).toEqual(25);
  })

  it('should update datalist', () => {
    expect(component.dataList).toBeDefined();
  })
});
