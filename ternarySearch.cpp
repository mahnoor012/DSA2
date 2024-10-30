#include<bits/stdc++.h>
using namespace std;
int ternary(int arr[],int l,int r,int k)
{
    if(r>=l)
    {
    int mid1=l+(r-l)/3;
    int mid2=r-(r-l)/3;
    if(arr[mid1]==k) return mid1;
    if(arr[mid2]==k) return mid2;
    if(arr[mid1]>k) return ternary(arr,l,mid1-1,k);
    else if(arr[mid2]<k) return ternary(arr,mid2+1,l,k);
    else return ternary(arr,mid1+1,mid2-1,k);
    }
    return -1;
}
int main()
{
    int n;
    cout<<"Give the size of array ";
    cin>>n;
    int arr[n];
    int k;
    cout<<"Give the value of searching key ";
    cin>>k;
    cout<<"Array"<<endl;
    for(int i=0; i<n; i++)
    {
        cin>>arr[i];
    }
    int left=0;
    int right=sizeof(arr)/sizeof(arr[0]);
    int r=ternary(arr,left,right,k);
    if(r==-1) cout<<"Not founded"<<endl;
    else
    {
        cout<<"Found at "<<" position "<<r+1<<endl;
        cout<<"Found at "<<" index "<<r<<endl;
    }

}
