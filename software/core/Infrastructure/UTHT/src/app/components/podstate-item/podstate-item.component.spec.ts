import { ComponentFixture, TestBed } from '@angular/core/testing';

import { PodstateItemComponent } from './podstate-item.component';

describe('PodstateItemComponent', () => {
  let component: PodstateItemComponent;
  let fixture: ComponentFixture<PodstateItemComponent>;

  beforeEach(async () => {
    await TestBed.configureTestingModule({
      declarations: [ PodstateItemComponent ]
    })
    .compileComponents();
  });

  beforeEach(() => {
    fixture = TestBed.createComponent(PodstateItemComponent);
    component = fixture.componentInstance;
    fixture.detectChanges();
  });

  it('should create', () => {
    expect(component).toBeTruthy();
  });
});
