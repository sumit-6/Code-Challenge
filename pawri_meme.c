#include <stdio.h>

int size_of_string(char* A);
int size_of_string(char* A)
{
    int i = 0;
    while (*(A + i) != '\0')
    {
        i++;
    }
    return i;
}

void replace_pawri(char* A,int j);
void replace_pawri(char* A,int j)
{
    int i;
    *(A + j - 2) = 'w';
    *(A + j - 1) = 'r';
    *(A + j ) = 'i';
}

int main()
{
    int T,i,j = 0,k = 0,p = 0;
    scanf("%d",&T);getchar();
    char input[100000];
    char pawri[6] = {'p','a','r','t','y','\0'};
    for (i = 0; i<T; i++)
    {
        j = 0;
        k = 0;
        fgets(input,100000,stdin);
        int sizestr = size_of_string(&input[0]),flag = 0;
        while (input[j] != '\0')
        {
            flag = 0;
            if (input[j] == pawri[k])
            {
                if (k == 4)
                {
                    replace_pawri(&input[0],j);
                    k = -1;
                }
                k++;
                flag = 1;
            }
            j++;
            if (flag == 0)
            {
                k = 0;
            }
        }
        for (p = 0; p<sizestr; p++)
        {
            printf("%c",input[p]);
        }
    }
    return 0;
}
