#include<bits/stdc++.h>
using namespace std;
void kps(int val[],int wt[],int n,int w)
{
    int kp[n+1][w+1]; //create 2d table .Add 1 with string's size for a extra row and column;
    int i,c;

    //fill 2d table
    for(i=0;i<=n;i++)
    {
        for(c=0;c<=w;c++)
        {
            if(i==0 ||c==0) kp[i][c]=0; //first row, first column will be zero;
            else if(wt[i-1]<=c) kp[i][c]=max(kp[i-1][c],val[i-1]+kp[i-1][c-wt[i-1]]);
            else kp[i][c]=kp[i-1][c];

        }
    }

    //to see 2d table
    for(i=0;i<=n;i++)
    {
        for(c=0;c<=w;c++)
        {
            cout<<kp[i][c]<<"\t";
        }
        cout<<endl;
    }
    cout<<endl;

    int last_idx=kp[n][w];
    cout<<"Profit will be "<<last_idx<<" or less than "<<last_idx<<endl;
    i=n;
    c=w;

    //backtrack
    cout<<"List of item : "<<endl;
    while(i>0 && c>0)
    {
        if(kp[i][c]!=kp[i-1][c])
        {
            cout<<"Item "<<i<< " value "<<val[i-1]<<" wight "<<wt[i-1]<<endl;
            c=c-wt[i-1];
        }
        i--;
    }
}
int main()
{
    int val[]={7,2,1,6,12};
    int wt[]={3,1,2,4,6};
    int n=sizeof(val)/sizeof(val[0]);  //number of item
    cout<<n<<endl;
    int w=10; //capacity
    kps(val,wt,n,w);
}
