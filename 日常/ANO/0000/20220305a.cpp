#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=1e5;
string a,b;
int p[100];
bool check(int x,int y)
{
    p[y]--;
    int flag=0;
    for(int i=x+1;i<b.size();i++)
    {
        int t=b[i]-'0';
        for(int j=9;j>=0;j--)
            if(p[j]&&t>j)return 1;
    }
    p[y]++;
    return 0;
}
signed main()
{
    cin>>a>>b;
    for(int i=0;i<a.size();i++)p[a[i]-'0']++;
    int flag=1;
    if(a.size()<b.size())
    {
        for(int i=9;i>=0;i--)
            while(p[i])cout<<i,p[i]--;
        return 0;
    }
    for(int i=0;i<b.size();i++)
    {
        if(flag)
        {
            int t=b[i]-'0';
            for(int j=t;j>=0;j--)
            {
                if(p[j]&&check(i,j))
                {
                	
                    cout<<j;
                    p[j]--;
                    if(j<t)flag=0;
                }
            }
        }
        else
        {
            for(int j=9;j>=0;j--)
                while(p[j])cout<<j,p[j]--;
            return 0;
        }
    }
}
/*

521
520
*/
