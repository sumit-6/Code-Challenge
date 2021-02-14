#include <stdio.h>
int main()
{
    long int T,i;
    long long N,K,x,y,difference;
    scanf("%ld",&T);getchar();
    for (i = 0; i<T; i++)
    {
        scanf("%lld %lld %lld %lld",&N,&K,&x,&y);getchar();
        difference = y - x;
        if ((difference == N) || (difference == -N))
        {
            printf("%lld %lld\n",x,y);
        }
        else if (difference == 0)
        {
            printf("%lld %lld\n",N,N);
        }
        else
        {
            if (difference<0)
            {
                if (K%4 == 1)
                {
                    printf("%lld %lld\n",(N),(N+difference));
                }
                else if(K%4 == 2)
                {
                    printf("%lld %lld\n",(N+difference),(N));
                }
                else if(K%4 == 3)
                {
                    printf("%lld %lld\n",0,(0-difference));
                }
                else if(K%4 == 0)
                {
                    printf("%lld %lld\n",(0-difference),0);
                }
            }
            else
            {
                if (K%4 == 1)
                {
                    printf("%lld %lld\n",(N-difference),(N));
                }
                else if(K%4 == 2)
                {
                    printf("%lld %lld\n",(N),(N-difference));
                }
                else if(K%4 == 3)
                {
                    printf("%lld %lld\n",difference,0);
                }
                else if(K%4 == 0)
                {
                    printf("%lld %lld\n",0,difference);
                }
            }
        }
    }
    return 0;
}
