#include<iostream>
#include<vector>
#include<utility>

using namespace std;

pair<int , int> largestPair(vector<int>&arr){
    int n = arr.size();
    if(n<2){
       cout<<"array must have 2 elements";
    }
    int first= max(arr[0],arr[1]);
    int second = min(arr[0],arr[1]);

    for(int i=2;i<n;i++){
        if(arr[i]>first){
            second=first;
            first=arr[i];
        }
        else if(arr[i] > second){
            second = arr[i];
        }
    }
    return {first,second};
}

int main(){
    int n;
    cin>>n;
    vector<int>v(n);

    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    pair<int,int> result=largestPair(v);

    cout<<"Largest Pair :" << result.first << " and " << result.second << endl;
}