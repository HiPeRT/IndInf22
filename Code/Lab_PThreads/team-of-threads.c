#include <stdio.h>
#include <pthread.h>

// void * is "like" Object for Java: can be used for generic type
void * pthreads_fn(void * args)
{
    int myid = (int) args; // This is my uniqe identifier, as assigned by programmer in main()
    unsigned int myid_from_so = pthread_self(); // This is my uniqe identifier, as assigned by O.S.
    printf("Hello PThreads world! My id is %u\n", myid);

    return 100 + myid; // Return whatever you want/need to return
}

int main()
{
    const unsigned int NUM_THREADS = 16;
    pthread_t mythreads[NUM_THREADS];
    pthread_attr_t myattr;
    void *returnvalue;

    for(int i=1; i<NUM_THREADS; i++) // ==> FORK
    {
        pthread_attr_init(&myattr);
        int err = pthread_create (&mythreads[i], &myattr, pthreads_fn, (void *) i); // Pass 'i' as identifier for thread
        pthread_attr_destroy(&myattr);
    }

    // Now, the man (master) thread can do other useful stuff, here
    // while other (slave) threads execute in parallel
    
    for(int i=0; i<NUM_THREADS; i++) // <== JOIN
    {
        pthread_join(mythreads[i], returnvalue); // Now, returnvalue contains the value returned by pthreads_fn
    }

    return 0;
}