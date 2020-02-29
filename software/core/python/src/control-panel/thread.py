import time
from worker import worker
import threading

'''This is the function that will be run in the thread. Infinite loop incrementing
a and emitting every 4 seconds'''
def thread_function(work: worker) -> None:
    a = 0
    while(True):
        work.emit(a)
        a = a + 1
        time.sleep(0.25)