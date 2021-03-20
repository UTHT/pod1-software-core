import { ComponentFixture, TestBed } from '@angular/core/testing';

import { GaugeGraphComponent } from './gauge-graph.component';

const testCases = [
  {
    label: "Test label 1", value: 5, type: "SPEED", input: [1, 2, 3, 4, 5], settings: {
      unit: 'm/s',
      gaugeType: 'arch',
      gaugeSize: '200',
      graphWidth: 400,
      graphHeight: 100,
      max: 25,
    }
  },
  {
    label: "Test label 2", value: 100, type: "BRAKE", input: [0, 2, 4, 6, 8, 10, 12, 14, 1, 6, 18, 20], settings: {
      unit: 'bar',
      gaugeType: 'arch',
      gaugeSize: '125',
      graphWidth: 200,
      graphHeight: 100,
      max: 3,
    }
  },
  {
    label: "Test label 3", value: -50, type: "TEMPERATURE", input: [], settings: {
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
  describe('GaugeGraphComponent', () => {
    let component: GaugeGraphComponent;
    let fixture: ComponentFixture<GaugeGraphComponent>;

    beforeEach(async () => {
      await TestBed.configureTestingModule({
        declarations: [GaugeGraphComponent]
      })
        .compileComponents();
    });

    beforeEach(() => {
      fixture = TestBed.createComponent(GaugeGraphComponent);
      component = fixture.componentInstance;

      component.label = test.label;
      component.value = test.value;
      component.type = test.type;
      component.inputDataArray = test.input;

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
      expect(component.label).toEqual(test.label);
      expect(component.value).toEqual(test.value);
      expect(component.type).toEqual(test.type);
      expect(component.inputDataArray).toEqual(test.input);
    })

    it('shoud match expected output settings', () => {
      expect(component.settings.unit).toEqual(test.settings.unit);
      expect(component.settings.gaugeType).toEqual(test.settings.gaugeType);
      expect(component.settings.gaugeSize).toEqual(test.settings.gaugeSize);
      expect(component.settings.graphWidth).toEqual(test.settings.graphWidth);
      expect(component.settings.graphHeight).toEqual(test.settings.graphHeight);
      expect(component.settings.max).toEqual(test.settings.max);
    })
  })
});
