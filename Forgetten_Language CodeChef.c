#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void compare_languages(char old_language[],int old_size,char new_language[],int new_size,int* arr);
void compare_languages(char old_language[],int old_size,char new_language[],int new_size,int* arr)
{
    int i,j,count = 0,result = 1;
    for (i = 0; i<(old_size); i=i+6)
    {
        char old_string[6] = {old_language[i+0],old_language[i+1],old_language[i+2],old_language[i+3],old_language[i+4],'\0'};
        count = 0;
        for (j = 0; j<(new_size); j=j+6)
        {
            char new_string[6] = {new_language[j+0],new_language[j+1],new_language[j+2],new_language[j+3],new_language[j+4],'\0'};
            result = strcmp(new_string,old_string);
            if (result == 0)
            {
                *(arr + (i/6)) = 1;
            }
        }
    }
}
int main(void)
{
    int T,cases = 0;
    int N,K,L,j = 0,k = 0;
    char yes[4] = "YES";
    char no[3] = "NO";
    scanf("%d",&T);getchar();
    for (cases = 0; cases<T; cases++)
    {
        scanf("%d %d",&N,&K);getchar();
        char dictionary[(5*N)+(N)];
        int counter_array[N];
        int * ptr = counter_array;
        for (j = 0; j<N; j++)
        {
            *(ptr + j) = 0;
        }
        fgets(dictionary,sizeof(dictionary),stdin);
        for (j = 0; j<K; j++)
        {
            scanf("%d",&L);getchar();
            char new_language[(5*L)+(L)];
            fgets(new_language,sizeof(new_language),stdin);
            char new_language_array[6*L];
            for (k = 0; k<((6*L)-1);k++)
            {
                new_language_array[k] = new_language[k];
            }
            new_language_array[(6*L)-1] = '\0';
            compare_languages(dictionary,sizeof(dictionary),new_language_array,sizeof(new_language),ptr);
        }
        for (k = 0; k<N; k++)
        {
            if (counter_array[k] == 1)
            {
                printf("%s ",yes);
            }
            else
            {
                printf("%s ",no);
            }
        }
        printf("\n");

    }
    return 0;
}
