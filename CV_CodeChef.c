#include <stdio.h>
int isVowel(char alphabet)
{
    if ((alphabet == 'a') || (alphabet == 'e') || (alphabet == 'i') || (alphabet == 'o') || (alphabet == 'u'))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int main()
{
    int T,N,i = 0,j = 0,count = 0;
    scanf("%d",&T);getchar();
    for (i = 0; i<T; i++)
    {
        count = 0;
        scanf("%d",&N);getchar();
        char S[N + 1];
        fgets(S,sizeof(S),stdin);
        for (j = 0; j<(N-1); j++)
        {
            if ((isVowel(S[j]) == 0) && (isVowel(S[j + 1]) == 1))
            {
                count++;
            }
        }
        printf("%d\n",count);
    }
    return 0;
}
