#include <stdio.h>
#include <math.h>
#include <stdlib.h>
int main()
{
    int T,i = 0,one = 1;
    char N_str[100000],result[50000];
    scanf("%d",&T);getchar();
    for (i = 0; i<T; i++)
    {
        fgets(N_str,sizeof(N_str),stdin);
        int num = atoi(N_str),j = 0;
        if (num%2 == 0)
        {
            //char result[(num/2)+2];
            for (j = 1; j<((num/2)+1); j++)
            {
                result[j]='0';
            }
            result[0]='1';
            result[(num/2)+1]='\0';
        }
        else
        {
            //char result[((num-1)/2)+2];
            for (j = 1; j<(((num-1)/2)+1); j++)
            {
                result[j]='0';
            }
            result[0]='1';
            result[((num-1)/2)+1]='\0';
        }
        printf("%d %s",one,result);
        printf("\n");
    }
    return 0;
}
