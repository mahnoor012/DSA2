#include<bits/stdc++.h>
using namespace std;
void lcs(string s1,string s2,int m,int n)
{
    int tbl[m+1][n+1]; //create 2d table .Add 1 with string's size for a extra row and column;
    int i,j;

    //fill 2d table;
    for(i=0;i<=m;i++)
    {
        for(j=0;j<=n;j++)
        {
            if(i==0 ||j==0) tbl[i][j]=0; //first row, first column will be zero;
            else if(s1[i-1]==s2[j-1]) tbl[i][j]=tbl[i-1][j-1]+1; //upper diagonal+1;
            else tbl[i][j]=max(tbl[i-1][j],tbl[i][j-1]); //max(up,left);
        }
    }

    //to see 2d table
    for(i=0;i<=m;i++)
    {
        for(j=0;j<=n;j++)
        {
            cout<<tbl[i][j]<<"\t";
        }
        cout<<endl;
    }
    cout<<endl;

    int last_idx=tbl[m][n];
    cout<<"Length of longest common subsequence is : "<<last_idx<<endl;
    char s3[last_idx+1];
    s3[last_idx]='\0';
    i=m;
    j=n;

    //backtrack
    while(i>0 && j>0)
    {
        if(tbl[i][j]==tbl[i-1][j]) i--;
        else if(tbl[i][j]==tbl[i][j-1]) j--;
        else
        {
            if(s1[i-1]==s2[j-1])
            {
                s3[last_idx-1]=s1[i-1]; //insert character reversely in s3;
                i--;
                j--;
                last_idx--;
            }
        }
    }

    //Longest common subsequence
    cout<<"Longest common subsequence of AAUCGUTFGH and AUAGUTTF is : "<<s3<<endl;


}
int main()
{
    string s1="AAUCGUTFGH";
    string s2="AUAGUTTF";
    int m=s1.size();
    int n=s2.size();
    lcs(s1,s2,m,n);
}

