#include<bits/stdc++.h>
using namespace std;
int freq[8];
int coinChange(int c[],int n,int i,int m)
{
    if(n==0 || i>=m) return 0;
    else if(c[i]<=n)
    {
        freq[i]++;
        return 1+coinChange(c,n-c[i],i,m);
    }
    else
    {
        return coinChange(c,n,i+1,m);
    }
}
int main()
{
    cout<<"Enter the amount to change : ";
    int n; //total amount
    cin>>n;
    cout<<"How many different type of coin you have : ";
    int m;
    cin>>m;
    cout<<"List of different type of coin ";
    int c[m];
    for(int j=0;j<m;j++)
    {
        cin>>c[j];
    }
    int i=0;//current picked coin
    int r=coinChange(c,n,i,m);
    cout<<"\nTotal coin "<<r<<endl;
    for(i=0;i<m;i++)
    {
        cout<<freq[i]<<" coin of " <<c[i]<<" paisa "<<endl;
    }
}
