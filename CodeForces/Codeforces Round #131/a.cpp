/*
    嵌套变量重复
    特殊样例 0 1 2 n
    数组越界
    开long long
*/
#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
const int maxn=1e6;
int p[3][3];
void solve()
{
    int flag=0;
    int cnt=0;
    for(int i=1;i<=2;i++)
        for(int j=1;j<=2;j++){
            cin>>p[i][j];
            if(p[i][j])flag=1,cnt++;
        }
    if(!flag)cout<<0<<endl;
    else
    {
        if(cnt==4)cout<<2<<endl;
        else cout<<1<<endl;
    }
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int __;cin>>__;
    while(__--)
        solve();
    return 0;
}