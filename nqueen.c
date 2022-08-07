#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int n;

void printSolution(int matrix[n][n])
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            printf("%d\t",matrix[i][j]);
        }
        printf("\n");
    }
}

bool isSafe(int matrix[n][n],int rows,int columns,int curr_row,int curr_col)
{
    for(int i=0;i<columns;i++)
    {
        if(matrix[curr_row][i]==1)
        {
            return false;
        }
    }
    for(int i=curr_row,j=curr_col;i<rows,j<columns;i++,j++)
    {
        if(matrix[i][j]==1)
        {
            return false;
        }
    }
    for(int i=curr_row,j=curr_col;i>=0,j>=0;i--,j--)
    {
        if(matrix[i][j]==1)
        {
            return false;
        }
    }
    for(int i=curr_row,j=curr_col;i>=0,j<columns;i--,j++)
    {
        if(matrix[i][j]==1)
        {
            return false;
        }
    }
    for(int i=curr_row,j=curr_col;i<rows,j>=0;i++,j--)
    {
        if(matrix[i][j]==1)
        {
            return false;
        }
    }
    return true;
}

bool NQueens(int matrix[n][n],int rows,int columns,int curr_col)
{
    if(curr_col>=n)
    {
        printf("\n");
        printSolution(matrix);
        return true;
    }
    for(int i=0;i<rows;i++)
    {
        if(isSafe(matrix,rows,columns,i,curr_col))
        {
            matrix[i][curr_col]=1;
            if(NQueens(matrix,rows,columns,curr_col+1))
            {
                if(i==n)
                {
                return true;
                }
            }
            matrix[i][curr_col]=0;
        }
    }
    return false;
}


void main()
{
    int rows,columns;
    printf("enter the no of queens:\n");
    scanf("%d",&n);
    rows=columns=n;
    int matrix[n][n];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            matrix[i][j]=0;
        }
    }
    if((NQueens(matrix,rows,columns,0)))
    {
        printf("no solution exists\n");
    }
}
