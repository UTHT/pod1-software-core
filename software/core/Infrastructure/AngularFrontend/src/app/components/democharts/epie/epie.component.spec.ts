import { ComponentFixture, TestBed } from '@angular/core/testing';

import { EpieComponent } from './epie.component';

describe('EpieComponent', () => {
  let component: EpieComponent;
  let fixture: ComponentFixture<EpieComponent>;

  beforeEach(async () => {
    await TestBed.configureTestingModule({
      declarations: [ EpieComponent ]
    })
    .compileComponents();
  });

  beforeEach(() => {
    fixture = TestBed.createComponent(EpieComponent);
    component = fixture.componentInstance;
    fixture.detectChanges();
  });

  it('should create', () => {
    expect(component).toBeTruthy();
  });
});
