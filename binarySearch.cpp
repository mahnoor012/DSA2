#include<bits/stdc++.h>
using namespace std;
int binary(int arr[],int left,int right,int f)
{
    if(right>=left)
    {
        int mid=left+(right-left)/2;
        if(arr[mid]==f) return mid;
        if(arr[mid]>f) return binary(arr,left,mid-1,f);
        else if(arr[mid]<f) return binary(arr,mid+1,right,f);
    }
    else if(right<=left)
    {
        return -1;
    }
}
int main()
{
    int n;
    cout<<"Give the size of array ";
    cin>>n;
    int arr[n];
    int f;
    cout<<"Give the value of searching key ";
    cin>>f;
    cout<<"Array"<<endl;
    for(int i=0; i<n; i++)
    {
        cin>>arr[i];
    }
    int left=0;
    int right=sizeof(arr)/sizeof(arr[0]);
    int r=binary(arr,left,right,f);
    if(r==-1) cout<<"Not founded"<<endl;
    else
    {
        cout<<"Found at "<<r+1<<" position"<<endl;
        cout<<"Found at "<<r<<" index"<<endl;
    }

}


