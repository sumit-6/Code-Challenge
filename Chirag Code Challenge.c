#include <stdio.h>
void update(long int* x, long int* y,  int* increment_x,  int* increment_y);
void change_direction(long int* x, long int* y, int* increment_x, int* increment_y, long int* N);
int terminate(int x, int y, int N);

void update(long int* x, long int* y, int* increment_x, int* increment_y)
{
    *x = *x + *increment_x;
    *y = *y + *increment_y;
}
void change_direction(long int* x, long int* y, int* increment_x, int* increment_y, long int* N)
{
    if (*x == *N && *y != *N)
    {
        *increment_x = -1;
    }
    else if (*x != *N && *y == *N)
    {
        *increment_y = -1;
    }
    else if (*x != 0 && *y == 0)
    {
        *increment_y = 1;
    }
    else if (*x == 0 && *y != 0)
    {
        *increment_x = 1;
    }
}
int terminate(int x, int y, int N)
{
    if (x == 0 && y == 0)
        return 1;
    else if (x == 0 && y == N)
        return 1;
    else if (x == N && y == 0)
        return 1;
    else if (x == N && y == N)
        return 1;
    return 0;
}
int main()
{
    int T,i,j,flag = 0,increment_x,increment_y;
    long int N,x,y,K,final_x,final_y,count;

    scanf("%i",&T);
    for ( i = 0; i<T ; i++)
    {
        scanf("%li %li %li %li",&N,&K,&x,&y);
        increment_x = 1;
        increment_y = 1;
        flag = 0;
        count=0;
        while (count != K)
        {
            update(&x,&y,&increment_x,&increment_y);
            change_direction(&x,&y,&increment_x,&increment_y,&N);
            flag = terminate(x,y,N);
            if (flag == 1)
            {
                printf("%li %li",x,y);
                break;
            }
            if (x == N || y == N)
            {
                final_x = x;
                final_y = y;
                count++;
            }
        }
        if (flag != 1)
        {
            printf("%li %li",final_x,final_y);
            printf("\n");
        }
    }
    return 0;
}
