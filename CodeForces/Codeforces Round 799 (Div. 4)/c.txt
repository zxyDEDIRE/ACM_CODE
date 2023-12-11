#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
const int maxn=1e6;
string mp[20];
int n=8;
void solve()
{
    for(int i=0;i<n;i++)
        cin>>mp[i];
    for(int i=1;i<n-1;i++)
    {
        for(int j=1;j<n-1;j++)
        {
            if(mp[i][j]=='#'&&mp[i-1][j-1]=='#'&&mp[i+1][j+1]=='#'&&mp[i][j]=='#'&&mp[i+1][j-1]=='#'&&mp[i-1][j+1]=='#'){
                cout<<i+1<<" "<<j+1<<endl;
                return ;
            }
        }
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int __;cin>>__;
    while(__--)
    solve();
    return 0;
}