import { ComponentFixture, TestBed } from '@angular/core/testing';

import { GraphComponent } from './graph.component';

const testCases = [
  {
    input: [1, 2, 3, 4, 5], settings: {
      unit: 'm/s',
      gaugeType: 'arch',
      gaugeSize: '200',
      graphWidth: 400,
      graphHeight: 100,
      max: 25,
    }
  },
  {
    input: [0, 2, 4, 6, 8, 10, 12, 14, 1, 6, 18, 20], settings: {
      unit: 'bar',
      gaugeType: 'arch',
      gaugeSize: '125',
      graphWidth: 200,
      graphHeight: 100,
      max: 3,
    }
  },
  {
    input: [], settings: {
      unit: '°C',
      gaugeType: 'semi',
      gaugeSize: '100',
      graphWidth: 200,
      graphHeight: 100,
      max: 100,
    }
  }
]

testCases.forEach(test => {
  describe('GraphComponent', () => {
    let component: GraphComponent;
    let fixture: ComponentFixture<GraphComponent>;

    beforeEach(async () => {
      await TestBed.configureTestingModule({
        declarations: [GraphComponent]
      })
        .compileComponents();
    });

    beforeEach(() => {
      fixture = TestBed.createComponent(GraphComponent);
      component = fixture.componentInstance;

      component.settings = test.settings;
      component.dataList = test.input;

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
      expect(component.dataList).toEqual(test.input);
      expect(component.settings).toEqual(test.settings);
    })

    it('should match expected output', () => {
      expect(component.lineChartData[0].data).toEqual(test.input);
      expect(component.lineChartOptions.scales.yAxes[0].ticks.max).toEqual(test.settings.max);
    })
  });
});
