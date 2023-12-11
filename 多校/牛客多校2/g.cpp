#include<bits/stdc++.h>
using namespace std;
int ans[1000006];
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,m;
        cin>>n;
        m=sqrt(n)+0.5;
        int now=1,tot=n;
        while(tot>0)
        {
            // cout<<tot<<" "<<now<<endl;
            if(tot<m)
            {
                for(int i=1;i<=tot;i++)
                {
                    ans[now++]=i;
                }
                break;
            }
            int tmp=tot-m+1;
            for(int i=1;i<=m;i++)//m个
            {
                ans[now++]=tmp;
                tmp++;
                tot--;
            }
        }
        for(int i=1;i<=n;i++)
            cout<<ans[i]<<" \n"[i==n];
    }
}