import { ComponentFixture, TestBed } from '@angular/core/testing';

import { LiveLineComponent } from './live-line.component';

describe('LiveLineComponent', () => {
  let component: LiveLineComponent;
  let fixture: ComponentFixture<LiveLineComponent>;

  beforeEach(async () => {
    await TestBed.configureTestingModule({
      declarations: [ LiveLineComponent ]
    })
    .compileComponents();
  });

  beforeEach(() => {
    fixture = TestBed.createComponent(LiveLineComponent);
    component = fixture.componentInstance;
    fixture.detectChanges();
  });

  it('should create', () => {
    expect(component).toBeTruthy();
  });
});
