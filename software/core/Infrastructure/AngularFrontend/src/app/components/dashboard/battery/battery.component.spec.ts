import { ComponentFixture, TestBed } from '@angular/core/testing';

import { BatteryComponent } from './battery.component';

const testCases = [
  {
    color: '#7FFFD4',
    value: 75,
    label: 'Label 1',
    arrayColor: [
      { full: true, color: '#7FFFD4', width: '30px' },
      { full: true, color: '#7FFFD4', width: '30px' },
      { full: true, color: '#7FFFD4', width: '30px' },
      { full: false, color: '#efefed', width: '22.5px' },
      { full: true, color: '#efefed', width: '30px' }
    ],
    totalPin: 5,
    pinColor: '#efefed'
  },
  {
    color: '#F0FFFF',
    value: 100,
    label: 'Label 2',
    arrayColor: [
      { full: true, color: '#F0FFFF', width: '30px' },
      { full: true, color: '#F0FFFF', width: '30px' },
      { full: true, color: '#F0FFFF', width: '30px' },
      { full: true, color: '#F0FFFF', width: '30px' },
      { full: true, color: '#F0FFFF', width: '30px' }
    ],
    totalPin: 5,
    pinColor: '#efefed'
  },
  {
    color: '#FFE4C4',
    value: 0,
    label: 'Label 3',
    arrayColor: [
      { full: true, color: '#efefed', width: '30px' },
      { full: true, color: '#efefed', width: '30px' },
      { full: true, color: '#efefed', width: '30px' },
      { full: true, color: '#efefed', width: '30px' },
      { full: true, color: '#efefed', width: '30px' }
    ],
    totalPin: 5,
    pinColor: '#efefed'
  }
]

testCases.forEach(test => {
  describe('BatteryPercentageComponent', () => {
    let component: BatteryComponent;
    let fixture: ComponentFixture<BatteryComponent>;

    beforeEach(async () => {
      await TestBed.configureTestingModule({
        declarations: [BatteryComponent]
      })
        .compileComponents();
    });

    beforeEach(() => {
      fixture = TestBed.createComponent(BatteryComponent);
      component = fixture.componentInstance;

      component.color = test.color;
      component.value = test.value;
      component.label = test.label;
      component.arrayColor = [];
      component.totalPin = test.totalPin;
      component.pinColor = test.pinColor;

      fixture.detectChanges();
    });

    it('should create', () => {
      expect(component).toBeTruthy();
    });

    it('should be defined', () => {
      expect(component.color).toBeDefined();
      expect(component.value).toBeDefined();
      expect(component.label).toBeDefined();
      expect(component.arrayColor).toBeDefined();
      expect(component.totalPin).toBeDefined();
      expect(component.pinColor).toBeDefined();
    })

    it('should match input', () => {
      expect(component.color).toEqual(test.color);
      expect(component.value).toEqual(test.value);
      expect(component.label).toEqual(test.label);
      expect(component.totalPin).toEqual(test.totalPin);
      expect(component.pinColor).toEqual(test.pinColor);
    })

    it('should match expected output', () => {
      expect(component.arrayColor).toEqual(test.arrayColor);
    })
  });
});