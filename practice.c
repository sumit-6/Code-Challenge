/*
Chef decided to find the connections with all of his friends in an unnamed social network.
He calls a user of the social network his friend if there is a common substring of the
string "chef" and the nickname of that user with length ≥ 2.

Given a list of users of the social network, compute the number of Chef's friends.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int searcher(char chef[],int pos1,char Person[],int pos2,int NoOfChar);
int searcher(char chef[],int pos1,char Person[],int pos2,int NoOfChar)
{
    int result;
    char name1[] = {chef[pos1],'\0'};
    char name2[] = {Person[pos2],'\0'};
    if ((chef[pos1]!='\0') || (Person[pos2]!='\0'))
    {
        if (strcmp(name1,name2) == 0)
        {
            NoOfChar++;
            result = searcher(chef,(pos1+1),Person,(pos2+1),NoOfChar);
            return result;
        }
        else
        {
            return (NoOfChar);
        }
    }
    else
    {
        return (NoOfChar);
    }
}
int main()
{
    int j = 0,i = 0,k = 0,count = 0,Matches=0;
    char chef[] = "chef";
    char Person[100];
    long int N;
    scanf("%li",&N);getchar();
    for (k = 0; k<N; k++)
    {
        fgets(Person,100,stdin);
        for (j = 0; chef[j] != '\0'; j++)
        {
            for (i = 0; Person[i] != '\0'; i++)
            {
                Matches = searcher(chef,j,Person,i,0);
                if (Matches >= 2)
                {
                    count++;
                    goto statement;
                }
            }
        }
        statement:continue;
    }
    printf("%d",count);
    return 0;
}
