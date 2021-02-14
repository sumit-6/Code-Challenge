#include <stdio.h>
#include <stdlib.h>
#include <math.h>
void Primer(long long* prime_arrays,long long N);
void Primer(long long* prime_arrays,long long N)
{
    long long i = 0,j = 0,k = 0;
    for (i = 0; i<=N; i++)
    {
        *(prime_arrays + i) = 1;
    }
    *(prime_arrays + 0) = 0;
    *(prime_arrays + 1) = 0;
    for (j = 2; j<=(long long)pow(N,0.5); j++)
    {
        if ( *(prime_arrays + j) == 1 )
        {
            for (k = 2; (j*k) <= N; k++)
            {
                *(prime_arrays + (j*k)) = 0;
            }
        }
    }
}
int main(void)
{
    long long N,i;
    scanf("%lld",&N);getchar();
    long long* ptr = (long long*)malloc(N*sizeof(long long));
    Primer(ptr,N);
    for (i = 2; i<=N; i++)
    {
        if (ptr[i] == 1)
        {
            printf("%lld ",i);
        }
    }
    return 0;
}
