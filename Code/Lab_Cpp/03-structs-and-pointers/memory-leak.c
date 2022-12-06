#include <stdlib.h>

int main()
{
    int *ptr = NULL;

    // (Bohr)Bug! Writing at address '0', which is not legal
    //*ptr = 4;

    ptr = (int *) malloc(sizeof(int)); // Allocate a single integer in HEAP, and put its address in ptr (resp. "new" in C++)
    *ptr = 5;

    ptr = (int *) malloc(sizeof(int) * 3); // Allocate an array of three integers, and put its address in ptr
    // MEM LEAK!!! We lost the only ref we have to the previously allocated "int" object!!!!
    // we shall have called free(ptr), resp "delete" in C++, BEFORE re-assigning ptr

    // These two are both accessing the first element of the array
    *ptr = 3;
    ptr[0] = 4;

    ptr[2] = 11;
    ptr[25] = 7; // OUT OF MEMORY!! This is a BUG!! 25 > 3 (...)

    return 0;
}