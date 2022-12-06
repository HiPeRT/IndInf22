#include <stdio.h>

// Declare a struct
struct mystruct
{
    int a;
    int b;
};

// Let's define a datatype for this
typedef struct mystruct mydatatype;

// Compressed form
// typedef struct mystruct
// {
//     int a;
//     int b;
// } mydatatype;

int main()
{
    struct mystruct s;
    s.a = 11,
    s.b = 19;
    printf("s.a is %d s.b is %d\n", s.a, s.b);

    mydatatype s1;
    s1.a = 11,
    s1.b = 19;

    printf("s1.a is %d s1.b is %d\n", s1.a, s1.b);

    return 0;
}