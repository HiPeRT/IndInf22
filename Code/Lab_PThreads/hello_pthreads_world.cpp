#include <iostream>
using namespace std;

#include <pthread.h>

void *my_pthread_fn(void *arg)
{
    // Thread body
    cout << "\t\t\t\t\tHello PThreads World! I am another thread" << endl;

    return NULL;
}

int main()
{
    pthread_t myid;
    pthread_attr_t attr;
    int ret;
    void *retval;
    /*
    int pthread_create ( pthread_t *ID,
                     pthread_attr_t *attr,
                     void *(*body)(void *),
                     void * arg
 			 );

    */
    cout << "Hello PThreads World! I am the main thread" << endl;

    ret = pthread_attr_init(&attr);

    // Fork
    ret = pthread_create(&myid,
                         &attr,
                         my_pthread_fn,
                         NULL );

    ret = pthread_attr_destroy(&attr);

    // Join
    pthread_join(myid, &retval);

    return 0;
}