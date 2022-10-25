#include "runtime.h"

using namespace std;

const char inputs[] = {'a', 'a', 'b', 'c'};
int ninputs = sizeof(inputs) / sizeof(inputs[0]);

char nextChar()
{
    static int i = 0;
    if (i >= ninputs)
        return 'x';
    return inputs[i++];
}
