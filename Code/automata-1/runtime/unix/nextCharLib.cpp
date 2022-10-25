#include "runtime.h"

using namespace std;

char nextChar(const char* inputs)
{
    int ninputs = sizeof(inputs) / sizeof(inputs[0]);
    
    static int i = 0;
    if (i >= ninputs)
        return 'x';
    return inputs[i++];
}
