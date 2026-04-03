#include<iostream>
#include<vector>
using namespace std;

int countEven(vector<int>&arr,int low,int high){
    if(low==high){
        return(arr[low]%2==0)?1:0;
    }
    int mid=(low+high)/2;
    int leftCount=countEven(arr,low,mid);
    int rightCount=countEven(arr,mid+1,high);

    return leftCount + rightCount;
}

int main(){
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    int result=countEven(v,0,n-1);
    cout<<"Total Even Numbers :"<<result<<endl;
}