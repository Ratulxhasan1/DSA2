#include<iostream>
#include<vector>
#include<cctype>
using namespace std;

bool isVowel(char arr){
    arr=tolower(arr);
    return(arr =='a' || arr=='e' || arr =='i' || arr=='o' || arr=='u' );

}

int countVowels(vector<char>&arr,int low,int high){
    if(low==high){
       return isVowel(arr[low])?1:0;
    }

    int mid=(low+high)/2;
    int leftCount=countVowels(arr,low,mid);
    int rightCount=countVowels(arr,mid+1,high);

    return leftCount + rightCount;

}

int main(){
  string s;
  cin>>s;
  vector<char> v(s.begin(),s.end());

    int result=countVowels(v,0,v.size()-1);

    cout<<"Vowels :" << result << endl;

}