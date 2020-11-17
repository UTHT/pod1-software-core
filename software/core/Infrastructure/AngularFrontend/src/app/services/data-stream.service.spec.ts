import { TestBed } from '@angular/core/testing';

import { DataStreamService } from './data-stream.service';

describe('DataStreamService', () => {
  let service: DataStreamService;

  beforeEach(() => {
    TestBed.configureTestingModule({});
    service = TestBed.inject(DataStreamService);
  });

  it('should be created', () => {
    expect(service).toBeTruthy();
  });
});
