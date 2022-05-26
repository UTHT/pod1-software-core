import { ComponentFixture, TestBed } from '@angular/core/testing';

import { SensorItemComponent } from './sensor-item.component';

describe('SensorItemComponent', () => {
  let component: SensorItemComponent;
  let fixture: ComponentFixture<SensorItemComponent>;

  beforeEach(async () => {
    await TestBed.configureTestingModule({
      declarations: [ SensorItemComponent ]
    })
    .compileComponents();
  });

  beforeEach(() => {
    fixture = TestBed.createComponent(SensorItemComponent);
    component = fixture.componentInstance;
    fixture.detectChanges();
  });

  it('should create', () => {
    expect(component).toBeTruthy();
  });
});
