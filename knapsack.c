#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int max(int a,int b)
{
    if(a>=b)
    {
        return a;
    }
    else
    {
        return b;
    }
}


void main()
{
    int n;
    printf("enter the no of items:\n");
    scanf("%d",&n);
    int weights[n],value[n],capacity;
    for(int i=0;i<n;i++)
    {
        printf("enter the value and weight of item%d:",i+1);
        scanf("%d %d",&value[i],&weights[i]);
    }
    printf("enter the capacity of the bag:\n");
    scanf("%d",&capacity);
    int table[capacity][capacity+1];
    for(int i=0;i<capacity;i++)
    {
        for(int j=0;j<capacity+1;j++)
        {
            if(i==0)
            {
                table[i][j]=0;
            }
            else if(j-weights[i-1]>=0)
            {
                table[i][j]=max(table[i-1][j],(value[i-1]+table[i-1][j-weights[i-1]]));
            }
            else
            {
                table[i][j]=table[i-1][j];
            }
        }
    }
    printf("the max profit is %d\n",table[capacity-1][capacity]);
}