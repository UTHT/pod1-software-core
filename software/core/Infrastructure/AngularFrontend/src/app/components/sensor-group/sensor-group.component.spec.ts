import { ComponentFixture, TestBed } from '@angular/core/testing';

import { SensorGroupComponent } from './sensor-group.component';

describe('SensorGroupComponent', () => {
  let component: SensorGroupComponent;
  let fixture: ComponentFixture<SensorGroupComponent>;

  beforeEach(async () => {
    await TestBed.configureTestingModule({
      declarations: [ SensorGroupComponent ]
    })
    .compileComponents();
  });

  beforeEach(() => {
    fixture = TestBed.createComponent(SensorGroupComponent);
    component = fixture.componentInstance;
    fixture.detectChanges();
  });

  it('should create', () => {
    expect(component).toBeTruthy();
  });
});
