#include<bits/stdc++.h>
#include<iostream>
#include<math.h>
using namespace std;
 
void merge(int arr[],int l,int mid, int r){
    int n1=mid-l+1;
    int n2=r-mid;
    int a[n1];
    int b[n2];
    for(int i=0;i<n1;i++){
        a[i]=arr[l+i];
    }
    for(int i=0;i<n2;i++){
        b[i]=arr[mid+1+i];
    }

    int i=0,j=0,k=l;
    while(i<n1 && j<n2){
        if(a[i]<b[j]){
            arr[k]=a[i];
            i++;
            k++;
        }
        else{
            arr[k]=b[j];
            j++;
            k++;
        }
    }

    while(i<n1){
        arr[k]=a[i];
            i++;
            k++;
    }
    while(j<n2){
        arr[k]=b[j];
            j++;
            k++;

    }



}

void mergeSort(int arr[],int l,int r){
    int mid;
    if(l<r){
        mid = (l+r)/2;
        mergeSort(arr,l,mid);
        mergeSort(arr,mid+1,r);
        merge(arr,l,mid,r);
    }
}

int32_t main(){
    int n;
    cout<<"ENter the size of array:"<<endl;
    cin>>n;
    int arr[n];
    cout<<"Enter the array Elements:"<<endl;
    for(int i=0;i<n;i++){
        cout<<"ENter "<<i<<" Element: "<<endl;
        cin>>arr[i];   
    }
    int l,r;
    l=0;
    r=n-1;
    mergeSort(arr,l,r);
    cout<<endl<<"Printing Sorted elements:"<<endl;
    for(int i=0;i<n;i++){
        cout<<arr[i]<<endl;
    }

    return 0;
}