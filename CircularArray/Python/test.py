from CircularArray import Circular_Array

from threading import *

a = ['A', 'B', 'C', 'D', 'E']
Array=Circular_Array(5,a)
#Lista.Semaphore_Threads(Lista,"X")
obj = Semaphore()
lock = Lock()
t1 = Thread(target = Array.MTAdd, args = [lock,obj,"X"])
t2 = Thread(target = Array.MTExtract, args = [lock,obj])
t1.start()
t2.start()
t1.join()
t2.join()