import { ComponentFixture, TestBed } from '@angular/core/testing';

import { PositionComponent } from './position.component';

const testCases = [
  {
    position: 0
  },
  {
    position: 25
  },
  {
    position: 100
  }
]

testCases.forEach(test => {
  describe('PositionComponent', () => {
    let component: PositionComponent;
    let fixture: ComponentFixture<PositionComponent>;

    beforeEach(async () => {
      await TestBed.configureTestingModule({
        declarations: [PositionComponent]
      })
        .compileComponents();
    });

    beforeEach(() => {
      fixture = TestBed.createComponent(PositionComponent);
      component = fixture.componentInstance;

      component.position = test.position;

      fixture.detectChanges();
    });

    it('should create', () => {
      expect(component).toBeTruthy();
    });

    it('should be defined', () => {
      expect(component.position).toBeDefined();
    })

    it('should match input', () => {
      expect(component.position).toEqual(test.position);
    })
  });
});