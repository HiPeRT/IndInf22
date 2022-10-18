#include "nextCharLib.hpp"

using namespace std;

/*
 * Gets next inputs, or 'x' if no inputs available.
 * WARNING: this function shifts the input, once you call it!
 */
char nextChar(const char* inputs)
{
    int ninputs = sizeof(inputs) / sizeof(inputs[0]);
    
    static int i = 0;
    if (i >= ninputs)
        return 'x';
    return inputs[i++];
}