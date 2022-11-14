from threading import *
import time


def Semaphore_Threads(Lista,Carattere):
    obj = Semaphore()
    lock = Lock()
    def MTAdd(lock):
        while True:

            if Lista.lunghezza<5:


                lock.acquire()
                obj.acquire()
                Lista.Add(Carattere)
                Lista.print(Lista.lenght)
                time.sleep(2)
                lock.release()
                obj.release()

    def MTremove(lock):
        while True:

            if Lista.lunghezza==5:
                lock.acquire()
                obj.acquire()
                Lista.Extract()
                time.sleep(2)
                lock.release()
                obj.release()

    t1 = Thread(target = MTAdd , args = [lock])
    t2 = Thread(target = MTremove , args = [lock])
    t1.start()
    t2.start()
    t1.join()
    t2.join()