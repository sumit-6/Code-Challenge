#include <stdio.h>
#include <math.h>
#include <string.h>

void its(char* c,int k);
void its(char* c,int k)
{
    int index = 0,sum = 0,temp = k,digits = 0;
    while (temp != 0)
    {
        temp = temp / 10;
        digits++;
    }
    temp = k;
    while (temp != 0)
    {
        sum = sum + temp%10*pow(10,digits-index-1);
        temp = temp/10;
        index++;
    }
    index = 0;
    while (sum != 0)
    {
        *(c + index) = sum%10 + 48;
        sum = sum/10;
        index++;
    }
    *(c + index) = '\0';
}

int arrange_lexicographically(char* string1,char* string2,int index);
int arrange_lexicographically(char* string1,char* string2,int index)
{
   int value;
   if ((*(string1+index) == '\0') && (*(string2+index) == '\0'))
   {
       return 0;
   }
   else if (*(string1 + index) == '\0')
   {
       *(string1 + index + 1 ) = '\0';
       value = arrange_lexicographically(string1,string2,index+1);
   }
   else if (*(string2 + index) == '\0')
   {
       *(string2 + index + 1 ) = '\0';
       value = arrange_lexicographically(string1,string2,index+1);
   }
   else
   {
       if (*(string1+index) > *(string2+index))
       {
           return 0;
       }
       else if (*(string1+index) < *(string2+index))
       {
           return 1;
       }
       else
       {
           value = arrange_lexicographically(string1,string2,index+1);
       }
   }
   return value;
}

int main()
{
    char str1[100];
    char str2[100];
    char zero[3] = "00";
    int T,i,index = 0;
    long int N,j,k;
    scanf("%d",&T);
    for (i = 0; i<T; i++)
    {
        j = 0;k = 0;index = 0;
        char* max;
        char* strlist[100];
        strcpy(str1,zero);strcpy(str2,zero);
        scanf("%ld",&N);

        for (j = 1; j<=(pow(N,0.5)); j++)
        {
            for (k = 1; k<=(pow(N,0.5)); k++)
            {
                if (k*k == (N - j*j))
                {
                    its(&str1[0],j*10 + k);
                    its(&str2[0],k*10 + j);
                    *(strlist+index) = &str1[0];
                    index++;
                    *(strlist+index) = &str2[0];
                    index++;
                }
            }
        }
        if ((strcmp(str1,zero) != 0) && (strcmp(str2,zero) != 0))
        {
            *(strlist+index) = '\0';
            k = 0;
            while (k <= (index -2))
            {
                if (arrange_lexicographically(*(strlist+k),*(strlist+k+1),0) == 0)
                {
                    max = *(strlist+k);
                }
                else
                {
                    max = *(strlist+k+1);
                }
                k++;
            }
            j = 0;
            while(*(max+j) != '\0')
            {
                printf("%c",*(max+j));
                j++;
            }
            printf("\n");
        }
    }
    return 0;
}
