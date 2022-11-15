#include <stdio.h>

#include <pthread.h>

// This is global, because we want it to be visible both to main() and pthread_fn()
// NOTE as a genral rule, we should NEVER work on global objects, as they represent an uncontrolled dependency
const int N_ELEM = 16;
int arr[N_ELEM];

void * pthreads_fn(void * args)
{
    int myid = (int) args; // This is my uniqe identifier, as assigned by programmer in main()
    
    printf("Hello PThreads world! My id is %u\n", myid);

    // I will work on the "myid-th" element of the array
    arr[myid] = arr[myid] * 2;

    return NULL; // We work on a global object. No need to return anything, here
}

int main()
{
    // We spawn as many threads as the elements of the array:
    // this means that our data partitioning strategy assigns one array element to each thread
    const unsigned int NUM_THREADS = N_ELEM;

    pthread_t mythreads[NUM_THREADS];
    pthread_attr_t myattr;
    void *returnvalue = new int;

    // Init arr
    for(int i=0; i<N_ELEM; i++)
        arr[i]= i;        

    for(int i=1; i<NUM_THREADS; i++) // ==> FORK
    {
        pthread_attr_init(&myattr);
        int err = pthread_create (&mythreads[i], &myattr, pthreads_fn, (void *) i); // Pass 'i' as identifier for thread
        pthread_attr_destroy(&myattr);
    }

    // We want the master thread to do the very same work of other threads
    pthreads_fn((void *) 0);
    
    for(int i=1; i<NUM_THREADS; i++) // <== JOIN
        pthread_join(mythreads[i], returnvalue);

    // Check (after join!!)
    for(int i=0; i<N_ELEM; i++)
        printf("arr[%d] now is %d\n", i, arr[i]);

    return 0;
}