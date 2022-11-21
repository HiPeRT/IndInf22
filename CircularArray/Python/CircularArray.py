from threading import *
import time



class Circular_Array:
    def __init__(self,l, array):
        self.lenght=l
        self.array=array
        self.head=0
        self.tail=0

    def print(self,index):
        i=index
        while i < self.lenght + index:
            print(self.array[(i % self.lenght)],end=" ")

            i = i + 1
        print(" ")



    def popM(self,index):
        l = len(self.array)

        for x in range(index , l - 1):
            self.array[x] = self.array[x + 1]
        self.array = self.array[:l - 1]
        return self.array

    def appendM(self,val):
        l = len(self.array) + 1
        b = [None for x in range(l)]
        for x in range(l - 1):
            b[x] = self.array[x]
        b[l - 1] = val
        return b

    def Add(self,element):
        self.array=self.appendM(element)
        self.head=(self.head+1)%self.lenght
        self.lenght = len(self.array)

    def Extract(self):
        self.array=self.popM(0)
        self.tail=(self.tail+1)%self.lenght
        self.lenght=len(self.array)

    def MTAdd(self, lock,obj,Carattere):
        while True:

            if self.lenght < 5: #5 is the lenght of the array.
                lock.acquire()
                obj.acquire()
                self.Add(Carattere)
                self.print(self.lenght)
                time.sleep(2)
                obj.release()
                lock.release()

    def MTExtract(self,lock,obj):
        while True:

            if self.lenght == 5:
                lock.acquire()
                obj.acquire()
                self.Extract()
                time.sleep(2)
                obj.release()
                lock.release()