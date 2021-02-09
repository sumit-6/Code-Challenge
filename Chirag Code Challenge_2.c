#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int check_availability(char time[],char P_time[]);
int check_availability(char time[],char P_time[])
{
    if ((time[0]=='1') && (time[1]=='2'))
    {
        time[0] = '0';
        time[1] = '0';
    }
    if ((time[9]=='1') && (time[10]=='2'))
    {
        time[9] = '0';
        time[10] = '0';
    }
    if ((P_time[0]=='1') && (P_time[1]=='2'))
    {
        P_time[0] = '0';
        P_time[1] = '0';
    }
    char temp_L[5] = {time[0],time[1],time[3],time[4],'\0'};
    int L = atoi(temp_L);
    char L_midday[3] = {time[6],time[7],'\0'};

    char temp_R[5] = {time[9],time[10],time[12],time[13],'\0'};
    int R = atoi(temp_R);
    char R_midday[3] = {time[15],time[16],'\0'};

    char temp_P[5] = {P_time[0],P_time[1],P_time[3],P_time[4],'\0'};
    int P = atoi(temp_P);
    char P_midday[3] = {P_time[6],P_time[7],'\0'};

    char AM[3] = "AM";
    char PM[3] = "PM";
    //Meeting is in morning
    if (strcmp(P_midday,AM) == 0)
    {
        if ((strcmp(L_midday,AM) == 0) && (strcmp(R_midday,AM) == 0))
        {
            if ((L<=P) && (P<=R))
            {
                return 1;
            }
            else
                return 0;
        }
        if ((strcmp(L_midday,AM) == 0) && (strcmp(R_midday,PM) == 0))
        {
            if (L<=P)
            {
                return 1;
            }
            else
                return 0;
        }
        if ((strcmp(L_midday,PM) == 0) && (strcmp(R_midday,PM) == 0))
        {
            return 0;
        }
    }
    //Meeting is not in morning
    if (strcmp(P_midday,PM) == 0)
    {
        if ((strcmp(L_midday,AM) == 0) && (strcmp(R_midday,AM) == 0))
        {
            return 0;
        }
        if ((strcmp(L_midday,AM) == 0) && (strcmp(R_midday,PM) == 0))
        {
            if (P<=R)
            {
                return 1;
            }
            else
                return 0;
        }
        if ((strcmp(L_midday,PM) == 0) && (strcmp(R_midday,PM) == 0))
        {
            if ((L<=P) && (P<=R))
            {
                return 1;
            }
            else
                return 0;
        }
    }
}
int main()
{
    char P[10],interval[19];
    int *arrayptr;
    int T = 0,N = 0,i = 0,j = 0;
    scanf("%d",&T);getchar();
    for (i = 0; i<T; i++)
    {
        fgets(P,sizeof(P),stdin);
        scanf("%d",&N);getchar();
        arrayptr = (int*)malloc(N*sizeof(int));

        for (j = 0; j<N; j++)
        {
            fgets(interval,sizeof(interval),stdin);
            arrayptr[j] = check_availability(interval,P);
        }
        for (j = 0; j<N; j++)
        {
            printf("%d",arrayptr[j]);
        }
        free(arrayptr);
        printf("\n");
    }
    return 0;
}
