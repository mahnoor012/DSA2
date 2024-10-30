#include<bits/stdc++.h>
using namespace std;
int partition(int arr[],int left,int right)
{
    int pivot=arr[left];//pivot at left;
    int i=left+1;
    int j=right;

    while(i<=j)
    {
        while(arr[i]<=pivot && i<=right) i++;
        while(arr[j]>pivot && j>left) j--;

        if(i<j)
        {
            swap(arr[i],arr[j]); //swap left,right
            i++;
            j--;
        }
    }
    swap(arr[left],arr[j]); //swap pivot,right
    return j; //return right;
}
void quickSort(int arr[],int left,int right) //problem divide into 2 subproblem
{
    if(left<right)
    {
        int pivot=partition(arr,left,right);

        quickSort(arr,left,pivot-1);   //1st part has the value less than pivot value
        quickSort(arr,pivot+1,right);  //2nd part has the value more than pivot value
    }
}
int main()
{
    //int arr[10]= {5,1,7,4,5,2,6,5,3,8};
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
    quickSort(arr,left,right);
    cout<<"Sorted Array in ascending order"<<endl;
    for(int i=0; i<n; i++)
    {
        cout<<arr[i]<<" ";
    }
}


