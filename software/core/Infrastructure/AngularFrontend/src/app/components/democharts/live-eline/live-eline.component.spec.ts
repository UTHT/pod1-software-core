import { ComponentFixture, TestBed } from '@angular/core/testing';

import { LiveElineComponent } from './live-eline.component';

describe('LiveElineComponent', () => {
  let component: LiveElineComponent;
  let fixture: ComponentFixture<LiveElineComponent>;

  beforeEach(async () => {
    await TestBed.configureTestingModule({
      declarations: [ LiveElineComponent ]
    })
    .compileComponents();
  });

  beforeEach(() => {
    fixture = TestBed.createComponent(LiveElineComponent);
    component = fixture.componentInstance;
    fixture.detectChanges();
  });

  it('should create', () => {
    expect(component).toBeTruthy();
  });
});
