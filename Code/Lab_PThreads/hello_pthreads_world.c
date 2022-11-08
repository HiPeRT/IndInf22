#include <stdio.h>
#include <pthread.h>

// void * is equivalent to "Object" in Java, or "object" in C#
void *my_pthread_fn(void *arg)
{
    // Thread body
    printf("\t\t\t\tHello PThreads World! I am the newly created PThread!\n");
    printf("\t\t\t\t...more stuff by the PThread...\n");
    
    return NULL;
}


int main()
{
    // Here, code is run by the main thread
    printf("Hello World! I am main thread!\n");
    
    // This function call is done by the main thread
    //my_pthread_fn(NULL);// NULL is defined as (void *) 0


    pthread_attr_t myattr;
    pthread_attr_init(&myattr);
    pthread_t mythread;

    /*
    int pthread_create (pthread_t *ID,         => Thread ID (out)
                        pthread_attr_t *attr,  => Thread params (we'll see)
                        void *(*body)(void *), => Thread body function
                        void * arg             => Params ('arg' in thread body function call)
 			           );
    */

    int err = pthread_create (&mythread, &myattr, my_pthread_fn, NULL); // ==> FORK

    // Here, the main thread can do other stuff!
    printf("I am the main thread, and I can do other stuff, here!\n");
    printf("...more stuff...\n");
    printf("...more stuff...\n");
    printf("...more stuff...\n");

    void *returnvalue;
    pthread_join(mythread, &returnvalue); // <== JOIN
    
    return 0;
}