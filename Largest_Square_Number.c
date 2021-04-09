#include <stdio.h>
#include <math.h>
#include <string.h>

int NofD(int j,int k);
int NofD(int j,int k)
{
    int count = 0;
    while (j != 0)
    {
        count++;
        j = j/10;
    }
    while (k != 0)
    {
        count++;
        k = k/10;
    }
    return count;
}

void its(char* c,int k,int j);
void its(char* c,int k,int j)
{
    int index = 0,sum = 0,temp = k,digit1 = 0,digit2 = 0;
    while (temp != 0)
    {
        temp = temp / 10;
        digit1++;
    }
    temp = k;
    while (temp != 0)
    {
        sum = sum + temp%10*pow(10,digit1-index-1);
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



    temp = j;sum = 0;index = 0;
    while (temp != 0)
    {
        temp = temp / 10;
        digit2++;
    }
    temp = j;
    while (temp != 0)
    {
        sum = sum + temp%10*pow(10,digit2-index-1);
        temp = temp/10;
        index++;
    }
    index = digit1;
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
       return 0;
   }
   else if (*(string2 + index) == '\0')
   {
       return 1;
   }
   else if ((*(string1 + index) != '\0') && (*(string2 + index) != '\0'))
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
    int ix = 0,iy = 0,flag = 0,count = 0;
    char str1[100];
    char str2[100];
    char* add1;char* add2;
    add1 = &str1[0];
    add2 = &str2[0];
    int T,i,index = 0;
    long int N,j,k;
    scanf("%d",&T);
    for (i = 0; i<T; i++)
    {
        j = 0;k = 0;index = 0;
        char* max;
        char* temp;
        char* strlist[100];
        scanf("%ld",&N);

        for (j = 1; j<=(int)(pow(N,0.5)); j++)
        {
            for (k = j; k<=(int)(pow(N,0.5)); k++)
            {
                if (k*k == (N - j*j))
                {
                    its(add1,j,k);
                    its(add2,k,j);
                    *(strlist+index) = add1;
                    index++;
                    *(strlist+index) = add2;
                    index++;
                    flag = 1;
                    add1 = add1 + NofD(j,k) + 1;
                    add2 = add2 + NofD(k,j) + 1;
                }
            }
        }
        ix = 0;
        while (ix < index)
        {
            temp = *(strlist + ix);
            iy = 0;
            while (*(temp + iy) != '\0')
            {
                printf("%c",*(temp + iy));
                iy++;
            }
            ix++;
            printf(" ");
        }
        printf("\n");
        if (flag == 1)
        {
            *(strlist+index) = '\0';
            k = 1;
            max = *(strlist + 0);
            temp = *(strlist + 0);
            while (k <= (index -1))
            {
                if (arrange_lexicographically(*(strlist+k),max,0) == 0)
                {
                    temp = *(strlist+k);
                }
                k++;
                max = temp;
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
