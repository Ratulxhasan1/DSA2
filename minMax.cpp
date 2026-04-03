#include<iostream>
#include<vector>
#include<utility>
using namespace std;

pair<int , int> maxMin(vector<int>&arr , int low , int high){
        if(low==high){
            return{arr[low] , arr[high]};
        }
       if(high == low+1){
        if(arr[low] > arr[high]){
            return{arr[low] , arr[high]};
        }
        else{
            return {arr[high] , arr[low]};
        }
       }
       int mid=(low+high)/2;

       pair<int , int> left= maxMin(arr,low,mid);
       pair<int , int> right=maxMin(arr,mid+1,high);

       int maximum = max(left.first,right.first);
       int minimum = min(left.second, right.second);

       return{maximum , minimum};
}

int main(){
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }

  pair<int , int> res=maxMin(v,0,n-1);

  cout<< " MAX :" << res.first << endl;
  cout<< "MIN :" << res.second << endl;


    
}