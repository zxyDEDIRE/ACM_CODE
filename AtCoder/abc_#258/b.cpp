/*
    嵌套变量重复
    特殊样例 0 1 2 n
    数组越界
    开long long
*/
#include<bits/stdc++.h>
#define int long long
using namespace std;
using ll=long long;
using pii=pair<int,int>;
const int maxn=100;
int dx[]={0,0,1,-1,1,-1,1,-1};
int dy[]={1,-1,0,0,1,-1,-1,1};
int mp[maxn][maxn];
int n;
ll ma;
void solve()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            scanf("%1d",&mp[i][j]);
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            for(int k=0;k<8;k++)
            {
                int x=i;
                int y=j;
                ll ans=0;
                for(int ii=0;ii<n;ii++)
                {
                    ans=ans*10+mp[x][y];
                    x=(x+dx[k]+n)%n;
                    y=(y+dy[k]+n)%n;
                }
                ma=max(ma,ans);
            }
        }
    }
    cout<<ma<<endl;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
        solve();
    return 0;
}