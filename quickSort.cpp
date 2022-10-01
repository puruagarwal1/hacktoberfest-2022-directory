#include<bits/stdc++.h>
#include<iostream>
#include<math.h>
using namespace std;

void quickSort(int[],int,int);
int main(){
    int array[11]={1,5,4,22,6,8,9,10,7,3,2};
    int n=sizeof(array)/sizeof(array[0]);
    quickSort(array,0,n-1);
    for(int i=0;i<n;i++){
        printf("%d\t",array[i]);
    }
    return 0;
}
void quickSort(int array[],int start,int end){
    int pivot=start;
    int i=start;
    int j=end;
    int temp;
    if(start==end){
        return;
    }
    while(i<j && j>=start && i<=end){
        while(array[pivot]>=array[i] && i<=end)
        {
            i++;
        }
        while(array[pivot]<=array[j] && j>start){
            j--;
        }
        if(i>j){
            temp=array[j];
            array[j]=array[pivot];
            array[pivot]=temp;
        }
        else{
            temp=array[i];
            array[i]=array[j];
            array[j]=temp;
        }
    }
    if((j-1)<start){
        //if start<j-1 means there is no element before pivot as now pivot element is at index j i.e is starting inddex
        quickSort(array,j+1,end);
    }
    else if((j+1)>end){
        //if start<j-1 means there is no element after pivot as now pivot element is at index j i.e is ending index
        quickSort(array,start,j-1);
    }
    else{
        quickSort(array,start,j-1);
        quickSort(array,j+1,end);
    }
}