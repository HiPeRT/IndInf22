

void * foo(void * arg)
{
    myid_i = (int) arg.i;
    myid_j = (int) arg.j;
    myid_k = (int) arg.k;

    imgOut[myid_i][myid_j][myid_k] = imgIn[myid_i][myid_j][myid_k] * 2;
}


int main()
{
    // for(int i=0; i<1000; i++)
    //     for(int j=0; j<100; j++)
    //      for(int k=0; k<100; k++)
    //        imgOut[i][j][k] = imgIn[i][j][k] * 2;


     for(int i=0; i<1000; i++)
        for(int j=0; j<100; j++)
            for(int k=0; k<100; k++)
                pthread_create(.. .. foo, (void *) (i, j, k));
}