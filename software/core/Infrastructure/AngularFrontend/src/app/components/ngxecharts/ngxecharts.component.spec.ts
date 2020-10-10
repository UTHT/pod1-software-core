import { ComponentFixture, TestBed } from '@angular/core/testing';

import { NgxechartsComponent } from './ngxecharts.component';

describe('NgxechartsComponent', () => {
  let component: NgxechartsComponent;
  let fixture: ComponentFixture<NgxechartsComponent>;

  beforeEach(async () => {
    await TestBed.configureTestingModule({
      declarations: [ NgxechartsComponent ]
    })
    .compileComponents();
  });

  beforeEach(() => {
    fixture = TestBed.createComponent(NgxechartsComponent);
    component = fixture.componentInstance;
    fixture.detectChanges();
  });

  it('should create', () => {
    expect(component).toBeTruthy();
  });
});
