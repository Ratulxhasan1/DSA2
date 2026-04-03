#include<iostream>
#include<vector>
#include<climits>
using namespace std;

int maxCrossingSum(vector<int>&arr , int low , int mid , int high){
    int sum=0;
    int leftSum=INT_MIN;

    for(int i=mid;i>=low;i++){
        sum+=arr[i];
        leftSum=max(leftSum,sum);
    }
    sum=0;
   int rightSum=INT_MIN;
   for(int i=mid+1;i<=high;i++){
    sum+=arr[i];
    rightSum=max(rightSum,sum);
   }
   return leftSum + rightSum;

}

int maxSubArray(vector<int>&arr,int low,int high){
    if(low == high ){
        return arr[low];
    }

    int mid=(low+high)/2;

    int leftMax=maxSubArray(arr,low,mid);
    int rightMax=maxSubArray(arr,mid+1,high);
    int crossSum=maxCrossingSum(arr,low,mid,high);

    return max(max(leftMax,rightMax),crossSum);
}

int main(){
    int n;
    cin>>n;
    vector<int>v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    int maxSumSubArray = maxSubArray(v,0,v.size()-1);

    cout<< "Max Sum SubArray :" << maxSumSubArray << endl;

}