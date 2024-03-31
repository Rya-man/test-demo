#include<stdio.h>
#include<stdlib.h>

int binsearch(int* arr,int val,int left,int right)
{
    
    if(left<=right)
    {
        int mid = left + (right-left)/2;

        if(arr[mid]==val)
        return mid;

        if(arr[mid]>val)
        return binsearch(arr,val,left,mid-1);

        if(arr[mid]<val)
        return binsearch(arr,val,mid+1,right);
    }
    return -1;

}

void toh(int n,char A,char B,char C)
{
    if(n==1){
    printf("Step %d moved from %c to %c\n",A,C);
    return;
    }
    toh(n-1,)
}

void move(int n, char source, char target, char auxiliary) {
    if (n == 1) {
        printf("Move disk 1 from %c to %c\n", source, target);
        return;
    }
    move(n - 1, source, auxiliary, target);
    printf("Move disk %d from %c to %c\n", n, source, target);
    move(n - 1, auxiliary, target, source);
}

void towerOfHanoi(int n) {
    move(n, 'A', 'C', 'B');
}