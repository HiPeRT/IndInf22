#include <stdio.h>

void fn_with_copy_param(int a_param)
{
    a_param = 10;
}

// This function has a reference parameter ('a_ptr'), hence, it has the so-called SIDE-EFFECTS,
// meaning it might modify the value of a variable which is not on its stack
void fn_with_reference_param(int *a_ptr)
{
    printf("a_ptr is 0x%x\n", (unsigned int) a_ptr);
    printf("*a_ptr is %d\n", *a_ptr);
    *a_ptr = 17; // Modify 'a' by referencing it
}

int main()
{
    // This is a DANGLING POINTER, as we haven't initialized it yet
    int *ptr;

    // To stay safe..now it points to '0', which is in a R/O memory region
    // (typically, the ".text" fragment, which is where program code resides)
    ptr = NULL;

    int a = 11;
    printf("a is %d, and its address is 0x%x\n", a, (unsigned int) &a);

    // Assign the address of 'a' to ptr
    ptr = &a;
    printf("ptr is 0x%x\n", (unsigned int) ptr);

    // Directly modify the value of 'a'
    a = 15;
    printf("a is %d\n", a);

    // Modify 'a' through the pointer
    *ptr = 7;
    printf("a is %d\n", a);

    fn_with_copy_param(a); // I am copying 'a', i.e., I am creating a new copy!
    printf("a is %d\n", a); // 'a' doesn't change

    fn_with_reference_param(&a); // I am passing the ADDRESS of 'a', by dereferencing (using '&')
    printf("a is %d\n", a); // 'a' changes
    
    return 0;
}