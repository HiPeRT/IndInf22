import threading
global lock
class Circular_Array:

    def __init__(self,l, array):
        self.lenght=l
        self.array=array
        self.lunghezza=len(self.array)
        self.head=0
        self.tail=0

    def print(self,index):
        i=index
        while i < self.lenght + index:
            print(self.array[(i % self.lunghezza)],end=" ")
            #print(i % self.lenght)
            i = i + 1
        print(" ")

    def Add(self,element):
        self.array.append(element)
        self.head=(self.head+1)%self.lenght
        self.lunghezza = len(self.array)
        #print("HEAD ora è", str(self.head))

    def Extract(self):
        self.array.pop(0)
        self.lunghezza = len(self.array)
        self.tail=(self.tail+1)%self.lenght






