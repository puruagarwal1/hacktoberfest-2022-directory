#include<iostream>
#include<vector>
using namespace std;

bool search(vector<int> &a,int key){
    int n=a.size();
    int s=0;
    int e=n-1;

    while(s<=e){
        int mid=(s+e)/2;
        if(a[mid]==key){
            return 1;
        }
        //if similar elements present
         if((a[s] == a[mid]) && (a[e] == a[mid]))
            {
                s++;
                e--;
            }
			

       if(a[s]<=a[mid]){
          if(key >= a[s] && key<=a[mid]){
            e=mid-1;
          }else{
            s=mid+1;
          }
       }else{
        if(key >= a[s] && key<=a[mid]){
            e=mid-1;
        }else{
            s=mid+1;
        }
       }
    }
    return 0;
}

int main(){
    vector<int> a{1,0,1,1,1};
    int key;
    cin>>key;
    cout<<search(a,key)<<endl;
    return 0;
}
