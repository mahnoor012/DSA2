#include<bits/stdc++.h>
using namespace std;
void merge(int arr[],int left,int right,int mid)
{
    int i=left; //1st part
    int j=mid+1; //2nd part
    int sz=right-left+1;
    int x=0;
    int temp[sz];
    while(i<=mid && j<=right) //when 1st part and 2nd part (both) have values;
    {
        if(arr[i]>=arr[j])
        {
            temp[x]=arr[i];
            i++; x++;
        }
        else
        {
            temp[x]=arr[j];
            j++; x++;
        }
    }
    while(i<=mid) //when only 1st part has values;
    {
          temp[x]=arr[i];
          i++; x++;
    }
    while(j<=right) //when only 2nd part has values;
    {
        temp[x]=arr[j];
        j++; x++;
    }
    x=0;
    for(i=left;i<=right;i++)
    {
        arr[i]=temp[x];
        x++;
    }
}
void mergesort(int arr[],int left,int right) //problem divide into 2 subproblem
{
    if(left<right)
    {
        int mid=left+(right-left)/2;
        mergesort(arr,left,mid);
        mergesort(arr,mid+1,right);

        merge(arr,left,right,mid);
    }
}
int main()
{
    //int arr[10]={6,3,1,2,9,7,6,5,4,2};
    int n;
    cout<<"Give the size of array ";
    cin>>n;
    int arr[n];
    cout<<"Unsorted Array"<<endl;
    for(int i=0; i<n; i++)
    {
        cin>>arr[i];
    }
    int left=0;
    int right=sizeof(arr)/sizeof(arr[0])-1;
    mergesort(arr,left,right);
    cout<<"Sorted Array in descending order"<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
}

