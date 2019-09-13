#include <stdio.h>
#include <stdlib.h>
void Input(int a[],int n)
{
    int i=0;
    for(i=0;i<n;i++)
   {
    printf("Enter value a[%d]=",i);
    scanf("%d",&a[i]);
   }
}
void Output(int a[],int n)
{
    int i=0;
    printf("The elements of the set are :\n");
    for(i=0;i<n;i++)
    printf("a[%d]=%4d \n",i,a[i]);
}
void Delete(int a[],int n,int k)
{
    int i=0;
    printf("The element you want to delete is at which position?:");
    scanf("%d",&k);
   for(i=k-1;i<n;i++)
   {
       a[i]=a[i+1];
   }
   n--;
   Output(a,n);
}

void Add(int a[],int n,int x,int k2)
{
    int i;
    for(i=n-1;i>=k2;i--)
    {
        a[i+1]=a[i];
    }
    a[k2]=x;
    n++;
}

int main()
{
    int n,k;
    int a[100];
    printf("How many elements do you want in the set?:");
    scanf("%d",&n);
    Input(a,n);
    Output(a,n);
    Delete(a,n,k);

    int x;
    printf("Enter the value of the new element you wish to add = ");
    scanf("%d",&x);
    int k2;
    printf("Position :");
    scanf("%d",&k2);
    Add(a,n,x,k2);
    Output(a,n);
    return 0;
}
