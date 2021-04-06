#include <stdio.h>

int calculate_i(long int* A,long int K);
int calculate_i(long int* A,long int K)
{
    int i;
    long int cal = K;
    for (i = 0; i<10; i++)
    {
        cal = cal - *(A + 9 - i);
        if (cal < 0)
        {
            return (10 - i);
        }
    }
    return 1;

}

 int main()
 {
     long int T,K,i;
     int j;
     long int A[10];
     scanf("%ld",&T);
     for (i = 0; i<T; i++)
     {
         for (j = 0; j<10; j++)
         {
             scanf("%ld",&A[j]);
         }
         scanf("%ld",&K);
         printf("%d\n",calculate_i(&A[0],K));
     }
 }
