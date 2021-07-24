import { ComponentFixture, TestBed } from '@angular/core/testing';

import { AccelerationComponent } from './acceleration.component';

describe('AccelerationComponent', () => {
  let component: AccelerationComponent;
  let fixture: ComponentFixture<AccelerationComponent>;

  beforeEach(async () => {
    await TestBed.configureTestingModule({
      declarations: [ AccelerationComponent ]
    })
    .compileComponents();
  });

  beforeEach(() => {
    fixture = TestBed.createComponent(AccelerationComponent);
    component = fixture.componentInstance;
    fixture.detectChanges();
  });

  it('should create', () => {
    expect(component).toBeTruthy();
  });
});
