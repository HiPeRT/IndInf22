inputStr = str(input("Inserisci la stringa: "))
nInputs = len(inputStr)

index = 0

def next():
    global index
    if (index >= nInputs):
        return 'x'
    
    ret = inputStr[index]
    index += 1

    return ret

def nextState(currState: int, inp: str):
    match currState:
        case 0:
            match inp:
                case 'a':
                    return 2
                case 'b':
                    return 1
                case 'c':
                    return 3
                case _:
                    pass
        case 1:
            match inp:
                case 'b':
                    return 1
                case 'c':
                    return 3
                case 'a' | _:
                    pass
        case 2:
            match inp:
                case 'a':
                    return 0
                case 'b' | 'c' | _:
                    pass
        case 3:
            return -2
        case _:
            return -3
    return -1

def isFinalState(s: int):
    return s == 3


def error(inp: str, currState: int, state: int):
    print("ERROR!")
    print("Input " + inp + " is not legal for state " + str(currState))
    print("Error code is " + str(state))
    exit()

if __name__ == "__main__":
    print ("Input size is " + str(nInputs))

    currState = 0
    state = -1
    c = ''

    while True:
        c = next()

        if c == 'x' and not isFinalState(currState):
            error(c, currState, state)
        
        print("Next input word is " + c + ", current state is " + str(currState))

        state = nextState(currState, c)

        if state < 0:
            error(c, currState, state)
        
        print("Next state will be " + str(state))

        if(isFinalState(state)):
            break

        currState = state
    
    print("Input sequence is legal")
