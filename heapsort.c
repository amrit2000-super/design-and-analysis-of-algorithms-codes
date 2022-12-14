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

void heapify(int i,int a[],int n)
{
    int largest=i;
    int left=2*i+1;
    int right=2*i+2;
    if(i<n && left<n && a[left]>a[largest])
    {
        largest=left;
    }
    if(i<n && right<n && a[right]>a[largest])
    {
        largest=right;
    }
    if(largest!=i)
    {
        swap(&a[i],&a[largest]);
        heapify(2*i+1,a,n);
    }
}


void heapsort(int a[],int n)
{
    for(int i=(n/2);i>=0;i--)
    {
        heapify(i,a,n);
    }
    
    for(int i=n-1;i>=0;i--)
    {
        swap(&a[i],&a[0]);
        heapify(0,a,i);
    }
}

void main()
{
    int n;
    printf("enter the size of the array:\n");
    scanf("%d",&n);
    int a[n];
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
    heapsort(a,n);
    printf("the elements of the array after performing heap sort are:\n");
    for(int i=0;i<n;i++)
    {
        printf("%d\t",a[i]);
    }
    printf("\n");
}
