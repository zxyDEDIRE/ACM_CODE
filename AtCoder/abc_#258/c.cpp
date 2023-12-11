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
string str;
int n,q;
void solve()
{
    cin>>n>>q>>str;
    int s=0;
    while(q--)
    {
        int fl,x;
        cin>>fl>>x;
        if(fl==2)
        {
            int t=(x+s-1)%n;
            cout<<str[t]<<endl;
        }
        else if(fl==1)
        {
            int t=n-x;
            s=(s+t)%n;
        }
        //cout<<"S: ";
        //cout<<s<<endl;
    }
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);

        solve();
    return 0;
}
/*
abc
*/