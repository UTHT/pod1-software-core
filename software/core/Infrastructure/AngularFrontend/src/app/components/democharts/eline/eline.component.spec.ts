import { ComponentFixture, TestBed } from '@angular/core/testing';

import { ElineComponent } from './eline.component';

describe('ElineComponent', () => {
  let component: ElineComponent;
  let fixture: ComponentFixture<ElineComponent>;

  beforeEach(async () => {
    await TestBed.configureTestingModule({
      declarations: [ ElineComponent ]
    })
    .compileComponents();
  });

  beforeEach(() => {
    fixture = TestBed.createComponent(ElineComponent);
    component = fixture.componentInstance;
    fixture.detectChanges();
  });

  it('should create', () => {
    expect(component).toBeTruthy();
  });
});
