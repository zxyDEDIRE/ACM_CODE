#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
const int maxn=1e6;
int p[maxn];
int a[maxn],b[maxn];
int n,k,ans;
void solve()
{
    cin>>n>>k;
    ans=0;
    for(int i=1;i<=n;i++){
        cin>>p[i];
        ans+=p[i];
        a[ans]++;
    }

}
int main(){
	cout<<60*24<<endl;
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int __;cin>>__;
    while(__--)
    solve();
    return 0;
}