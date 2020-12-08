import { ComponentFixture, TestBed } from '@angular/core/testing';

import { PodstateComponent } from './podstate.component';

describe('PodstateComponent', () => {
  let component: PodstateComponent;
  let fixture: ComponentFixture<PodstateComponent>;

  beforeEach(async () => {
    await TestBed.configureTestingModule({
      declarations: [ PodstateComponent ]
    })
    .compileComponents();
  });

  beforeEach(() => {
    fixture = TestBed.createComponent(PodstateComponent);
    component = fixture.componentInstance;
    fixture.detectChanges();
  });

  it('should create', () => {
    expect(component).toBeTruthy();
  });
});
