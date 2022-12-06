#include <stdio.h>
#include <cuda.h>

__global__ void fun()
{
  //printf("\t\t\t\t\t[DEVICE] Hello World!\n");
  
  int thrId = threadIdx.x;
  int blkId = blockIdx.x;
  
  int thrNum = blockDim.x;
  int blkNum = gridDim.x;

  int i =  threadIdx.x + blockIdx.x * blockDim.x;
  // every thread has a unique i
  if(i >= 15)
    return;

  //arr[i] = i*2;// do something
  
  printf("\t\t\t\t\t[DEVICE] Hello World! I am thread #%d out of %d, and I belong to block #%d out of %d\n", thrId, thrNum, blkId, blkNum);
  
  return;
}

int main()
{
  printf("[HOST] Hello World!\n");
  
  funzione<<<3,5>>>();

  printf("[HOST] Some more work on host\n");

  cudaDeviceSynchronize();
  
  printf("[HOST] Device ended its work!\n");
  
  return 0;
}
