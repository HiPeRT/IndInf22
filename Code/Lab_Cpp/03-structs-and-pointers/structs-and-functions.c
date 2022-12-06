#include <stdio.h>

typedef struct
{
    int a;
    int b;
} mystruct;

void fn_with_copy(mystruct s)
{
    s.a *= 2;
}

void fn_with_ref(mystruct *s)
{
    s->a *= 2;
}

int main()
{
    mystruct s;
    s.a = 11,
    s.b = 19;
    printf("s.a is %d s.b is %d\n", s.a, s.b);
    
    fn_with_ref(&s);
    printf("s.a is %d s.b is %d\n", s.a, s.b);

    return 0;
}