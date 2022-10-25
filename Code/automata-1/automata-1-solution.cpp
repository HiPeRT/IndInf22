#include <iostream>

using namespace std;

const char inputs[] = {'a', 'a', 'b', 'c'};
int ninputs = sizeof(inputs) / sizeof(inputs[0]);

/*
 * Gets next inputs, or 'x' if no inputs available.
 * WARNING: this function shifts the input, once you call it!
 */
char next()
{
    static int i = 0;
    if(i >= ninputs)
        return 'x';
    return inputs[i++];
}

void write(std::string s)
{
    cout << s << endl;
}

/*
 * Computes next state. Returns the following
 *   >=0 : the next state
 *   -1  : input sequence not legal
 *   -2  : we're in final state
 *   -3  : internal error
 */
int nextState(int currState, char input)
{
    switch(currState)
    {
        case 0: // if in S0
            switch(input)
            {
                case 'a':
                    write ("output is 4\n");
                    return 2;
                case 'b':
                    write ("output is 2\n");
                    return 1;
                case 'c':
                    write ("output is 9\n");
                    return 3;
                default:
                    break;
            }
            break;

        case 1: // if I am in S1
            switch(input)
            {
                case 'a':
                    break;
                case 'b':
                    write ("output is 1\n");
                    return 1;
                case 'c':
                    write ("output is 6\n");
                    return 3;
                default:
                    break;
            }
            break;

        case 2: // if I am in S2
            switch(input)
            {
                case 'a':
                    write ("output is 5\n");
                    return 0;
                case 'b':
                    break;
                case 'c':
                    break;
                default:
                    break;
            }
            break;

        case 3: // if I am in S3
            return -2;

        default: // if I am in S>4
            return -3;
    }

    // If we're here, it's an error
    return -1;
}

bool isFinalState(int s)
{
    return s == 3;
}

int main()
{
    cout << "Inputs size is " << ninputs << endl;
    int currState = 0;
    int state = -1;
    char c;

    while(1)
    {
        // Get next input
        c = next();

        // We ran out of inputs, and
        if(c == 'x')
        {
            if(!isFinalState(currState))
                goto error;
                // This should never happen, if our algo works well
            else
                break;
        }

        cout << "Next input word is " << c << ", current state is " << currState << endl;

        state = nextState(currState, c);

        // Check for errors
        if(state < 0)
            goto error;

        cout << "Next state will be " << state << endl;

        if(isFinalState(state))
            break;

        // Update curr state
        currState = state;
    }

    cout << "Input sequence is legal for our Language" << endl;
    return 0;

    error:
    cout << "ERROR!" << endl;
    cout << "Input " << c << " not legal for state " << currState << endl;
    cout << "Error code is " << state << endl;
    return state;
}