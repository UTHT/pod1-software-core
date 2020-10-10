import { ComponentFixture, TestBed } from '@angular/core/testing';

import { EradarComponent } from './eradar.component';

describe('EradarComponent', () => {
  let component: EradarComponent;
  let fixture: ComponentFixture<EradarComponent>;

  beforeEach(async () => {
    await TestBed.configureTestingModule({
      declarations: [ EradarComponent ]
    })
    .compileComponents();
  });

  beforeEach(() => {
    fixture = TestBed.createComponent(EradarComponent);
    component = fixture.componentInstance;
    fixture.detectChanges();
  });

  it('should create', () => {
    expect(component).toBeTruthy();
  });
});
