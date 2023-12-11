/*
    嵌套变量重复
    特殊样例 0 1 2 n
    数组越界
    开long long
*/
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
using ll=long long;
using pii=pair<int,int>;
const int maxn=1e6;
vector<int>s,t;
int n,cnt;
void solve()
{
    cin>>n;
    cnt=0;
    s.clear();
    t.clear();
    for(int i=1;i<=n;i++)
    {
        int x;cin>>x;
        if(x==0)cnt++;
        else s.push_back(x);
    }
    for(int i=n;i>=1;i--)
    {
        // for(auto i:s)
        //     cout<<i<<" ";
        // cout<<endl;
        // cout<<cnt<<endl;
        if(s.size()==0){
            cout<<0<<endl;
            return ;
        }

        if(cnt)
        {
            if(s.size())t.push_back(s[0]);
            cnt--;
        }
        for(int i=0;i<s.size()-1;i++)
        {
            int x=s[i+1]-s[i];
            if(x)t.push_back(s[i+1]-s[i]);
            else cnt++;
        }
        sort(t.begin(),t.end());
        s=t;
        t.clear();
    }
    if(cnt)cout<<0<<endl;
    else cout<<s[0]<<endl;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int __;cin>>__;
    while(__--)
        solve();
    return 0;
}
/*
0 0 0 8 13
0 0 5 8
0 0 3 5
0 2 3
1 2
1
*/