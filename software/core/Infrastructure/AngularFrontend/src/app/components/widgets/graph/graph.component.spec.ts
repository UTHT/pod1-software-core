import { ComponentFixture, TestBed } from '@angular/core/testing';

import { GraphComponent } from './graph.component';

describe('GraphComponent', () => {
  let component: GraphComponent;
  let fixture: ComponentFixture<GraphComponent>;

  beforeEach(async () => {
    await TestBed.configureTestingModule({
      declarations: [ GraphComponent ]
    })
    .compileComponents();
  });

  beforeEach(() => {
    fixture = TestBed.createComponent(GraphComponent);
    component = fixture.componentInstance;

    component.settings = {
      unit: 'bar',
      gaugeType: 'arch',
      gaugeSize: '125',
      graphWidth: 200,
      graphHeight: 100,
      max: 3,
    };
    component.dataList = [1,2,3,4,5];

    fixture.detectChanges();
  });

  it('should create', () => {
    expect(component).toBeTruthy();
  });

  it('should be defined', () => {
    expect(component.dataList).toBeDefined();
    expect(component.settings).toBeDefined();
  })

  it('should match input', () => {
    expect(component.dataList).toEqual([1,2,3,4,5]);
    expect(component.settings).toEqual({
      unit: 'bar',
      gaugeType: 'arch',
      gaugeSize: '125',
      graphWidth: 200,
      graphHeight: 100,
      max: 3,
    });
  })

  it('should match expected output', () => {
    expect(component.lineChartData[0].data).toEqual([1,2,3,4,5]);
    expect(component.lineChartOptions.scales.yAxes[0].ticks.max).toEqual(3);
  })
});
