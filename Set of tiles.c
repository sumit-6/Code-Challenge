#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int searcher(char str[],int sizeofstr, char c);
int calculate(int occurence[], int sizeofOA,int* array,int pointer,int RequiredString_size, int * counter);
int fact(int f);
void fillZERO(int* arr,int size_arr);

void fillZERO(int* arr,int size_arr)
{
    int i = 0;
    for(i = 0; i<size_arr; i++)
    {
        *(arr + i) = 0;
    }
}

int fact(int f)
{
    if (f == 0)
    {
        return 1;
    }
    return f*fact(f-1);
}

int calculate(int occurence[], int sizeofOA,int* array,int pointer,int RequiredString_size, int * counter)
{
    int i = 0,denominator = 1,a = 0,alternate_sum = 0;
    for (i = 0; i<(sizeofOA - 1); i++)
    {
        alternate_sum = alternate_sum + (*(array + i));
        denominator = denominator*fact(*(array + i));
    }
    if (pointer == (sizeofOA - 1))
    {
        for (i = 0; i<=(occurence[pointer]); i++)
        {
            if ((alternate_sum + i) == RequiredString_size)
            {
                *(array + pointer) = i;
                return (fact(RequiredString_size)/((denominator)*(fact(i))));
            }
        }
    }
    else
    {
        for (i = 0; i<=(occurence[pointer]); i++)
        {
            if ((alternate_sum + i) <= RequiredString_size)
            {
                *(array + pointer) = i;
                a = calculate(occurence,sizeofOA,array,(pointer+1),RequiredString_size,counter);
                *counter = *counter + a;
                *(array + pointer) = 0;
            }
        }
    }
    return (0);
}

int searcher(char str[],int sizeofstr, char c)
{
    int i = 0,freq = 0;
    for (i = 0; i<sizeofstr; i++)
    {
        if (str[i] == c)
        {
            freq++;
        }
    }
    return freq;
}

int main()
{
    char str[100];
    int sizeofstr = 0,i = 0,j=0,temp = 0, element1, element2,count = 0;
    gets(str);
    for (i = 0; str[i] != '\0'; i++)
    {
        sizeofstr++;
    }
    for (i = 0; i< sizeofstr; i++)
    {
        for (j = i+1; j< sizeofstr; j++)
        {
            element1 = str[i]; element2 = str[j];
            if (element1 > element2)
            {
                temp = str[i];
                str[i] = str[j];
                str[j] = temp;
            }
        }
    }
    temp = 0;
    for (i = 0; i < sizeofstr; i++)
    {
        if (str[i] != str[i+1])
        {
            temp++;
        }
    }
    int answer[temp];
    fillZERO(answer,temp);
    int unique[temp];

    temp = 0;
    for (i = 0; i < (sizeofstr); i++)
    {
        if (str[i] != str[i+1])
        {
            unique[temp] = searcher(str,sizeofstr,str[i]);

            temp++;
        }
    }
    printf("Check: ");
    for (i = 0; i < (sizeof(unique)/sizeof(unique[0])); i++)
    {
        printf("%d ",unique[i]);
    }
    printf("\n");
    for (i = 1; i<= sizeofstr; i++)
    {
        fillZERO(answer,(sizeof(answer)/sizeof(answer[0])));
        temp = calculate(unique,(sizeof(unique)/sizeof(unique[0])),answer,0,i,&count);
    }
    printf("OUTPUT: %d",count);
    return 0;
}
