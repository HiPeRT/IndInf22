#include <iostream>

using namespace std;

const int inputs_size = 2;
const char inputs[] = {'b', 'c'};
//const int inputs_size = 4;
//const char inputs[] = {'a', 'a', 'b', 'c'};

// bool input_ended()
// {
	// return i >= inputs_size;
// }

char next()
{
	static int i = 0;
	return inputs[i++];
}

int main()
{
	cout << "Next input word is " << next() << endl;
	cout << "Next input word is " << next() << endl;
/*
	int state = 0;
	
	while(c == next())
	{
		switch(s)
		{
			case 2:
				if(c != 'a')
					goto error;
				else
					state = 0;
				break;
			default:
				break;
		}
	}
	
	return 0;
   
error:
	cout << "ERROR!" << endl;
	cout << "Input " + c + " not legal in state " + s << endl;
	return -1;
*/
}