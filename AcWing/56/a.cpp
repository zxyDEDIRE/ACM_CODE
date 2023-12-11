#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
const int maxn=1e6;
int n;
map<int,int>mp;
void solve()
{
    cin>>n;
    int ma=0;
    for(int i=1;i<=n;i++){
        int x;cin>>x;
        mp[x]++;
        ma=max(ma,mp[x]);
    }
    cout<<ma<<endl;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);

    solve();
    return 0;
}

作者：十月三日
链接：https://www.acwing.com/activity/content/code/content/3624811/
来源：AcWing
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。