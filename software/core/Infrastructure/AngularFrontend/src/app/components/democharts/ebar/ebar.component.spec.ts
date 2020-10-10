import { ComponentFixture, TestBed } from '@angular/core/testing';

import { EbarComponent } from './ebar.component';

describe('EbarComponent', () => {
  let component: EbarComponent;
  let fixture: ComponentFixture<EbarComponent>;

  beforeEach(async () => {
    await TestBed.configureTestingModule({
      declarations: [ EbarComponent ]
    })
    .compileComponents();
  });

  beforeEach(() => {
    fixture = TestBed.createComponent(EbarComponent);
    component = fixture.componentInstance;
    fixture.detectChanges();
  });

  it('should create', () => {
    expect(component).toBeTruthy();
  });
});
