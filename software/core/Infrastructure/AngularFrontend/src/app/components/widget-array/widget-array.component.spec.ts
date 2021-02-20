import { ComponentFixture, TestBed } from '@angular/core/testing';

import { WidgetArrayComponent } from './widget-array.component';

describe('WidgetArrayComponent', () => {
  let component: WidgetArrayComponent;
  let fixture: ComponentFixture<WidgetArrayComponent>;

  beforeEach(async () => {
    await TestBed.configureTestingModule({
      declarations: [ WidgetArrayComponent ]
    })
    .compileComponents();
  });

  beforeEach(() => {
    fixture = TestBed.createComponent(WidgetArrayComponent);
    component = fixture.componentInstance;
    fixture.detectChanges();
  });

  it('should create', () => {
    expect(component).toBeTruthy();
  });
});
