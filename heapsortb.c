#include <stdio.h>
#include <stdlib.h>

void swap(int *a,int *b)
{
    int temp=0;
    if(*a > *b)
    {
        temp=*a;
        *a=*b;
        *b=temp;
    }
    
    else
    {
        temp=*b;
        *b=*a;
        *a=temp;
    }
}

void heapify(int i,int final[],int n)
{
    int largest=i;
    int left=2*i+1;
    int right=2*i+2;
    if(i<n && left<n && final[left]>final[largest])
    {
        largest=left;
    }
    if(i<n && right<n && final[right]>final[largest])
    {
        largest=right;
    }
    if(largest!=i)
    {
        swap(&final[i],&final[largest]);
        heapify(2*i+1,final,n);
    }
}


void heapsort(int a[],int n,int final[])
{
    for(int i=0;i<n;i++)
    {
        int k=0;
        final[i]=a[i];
        for(k=i/2;k>=0;k--)
        {
        heapify(k,final,i+1);
        }
    }
    
    for(int i=n-1;i>=0;i--)
    {
        swap(&final[i],&final[0]);
        heapify(0,final,i);
    }
}

void main()
{
    int n;
    printf("enter the size of the array:\n");
    scanf("%d",&n);
    int a[n],final[n];
    printf("enter the elements of the array:\n");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    printf("the elements of the array before performing heap sort are:\n");
    for(int i=0;i<n;i++)
    {
        printf("%d\t",a[i]);
    }
    printf("\n");
    heapsort(a,n,final);
    printf("the elements of the array after performing heap sort are:\n");
    for(int i=0;i<n;i++)
    {
        printf("%d\t",final[i]);
    }
    printf("\n");
}
