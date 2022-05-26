import { compileComponentFromMetadata } from '@angular/compiler';
import { ComponentFixture, TestBed } from '@angular/core/testing';

import { SensorGroupComponent } from './sensor-group.component';

const testCases = [
  {
    title: "F",
    data: [
      {
        id: 'F1',
        state: 'inactive'
      },
      {
        id: 'F2',
        state: 'active'
      },
      {
        id: 'F3',
        state: 'active'
      },
      {
        id: 'F4',
        state: 'error'
      },
      {
        id: 'F5',
        state: 'active'
      },
      {
        id: 'F6',
        state: 'active'
      },
    ]
  },
  {
    title: "G",
    data: [
      {
        id: 'G1',
        state: 'active'
      },
      {
        id: 'G2',
        state: 'active'
      },
      {
        id: 'G3',
        state: 'active'
      },
      {
        id: 'G4',
        state: 'active'
      },
      {
        id: 'G5',
        state: 'active'
      },
      {
        id: 'G6',
        state: 'active'
      },
    ]
  },
  {
    title: "H",
    data: [
      {
        id: 'H1',
        state: 'error'
      },
      {
        id: 'H2',
        state: 'error'
      },
      {
        id: 'H3',
        state: 'error'
      },
      {
        id: 'H4',
        state: 'error'
      },
      {
        id: 'H5',
        state: 'error'
      },
      {
        id: 'H6',
        state: 'error'
      },
    ]
  },
  {
    title: "I",
    data: [
      {
        id: 'I1',
        state: 'inactive'
      },
      {
        id: 'I2',
        state: 'inactive'
      },
      {
        id: 'I3',
        state: 'inactive'
      },
      {
        id: 'I4',
        state: 'inactive'
      },
      {
        id: 'I5',
        state: 'inactive'
      },
      {
        id: 'I6',
        state: 'inactive'
      },
    ]
  }
]

testCases.forEach(test => {
  describe('SensorGroupComponent', () => {
    let component: SensorGroupComponent;
    let fixture: ComponentFixture<SensorGroupComponent>;

    beforeEach(async () => {
      await TestBed.configureTestingModule({
        declarations: [SensorGroupComponent]
      })
        .compileComponents();
    });

    beforeEach(() => {
      fixture = TestBed.createComponent(SensorGroupComponent);
      component = fixture.componentInstance;

      component.title = test.title;
      component.data = test.data;

      fixture.detectChanges();
    });

    it('should create', () => {
      expect(component).toBeTruthy();
    });

    it('should be defined', () => {
      expect(component.data).toBeDefined();
      expect(component.title).toBeDefined();
    });

    it('should match input', () => {
      expect(component.title).toEqual(test.title);
      expect(component.data).toEqual(test.data);
    });
  });
})