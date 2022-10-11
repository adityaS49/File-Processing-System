#include<bits/stdc++.h>
#define ll long long int;
using namespace std;

int main(){
int n;
cout<<"Enter the size of array : ";
cin>>n;
int arr[n];\
cout<<"Enter the numbers : ";
for(int i = 0; i<n;i++){
    cin>>arr[i];
}
sort(arr,arr+n);
cout<<arr[0]<<endl;
cout<<arr[n-1]<<endl;
    return 0;
}