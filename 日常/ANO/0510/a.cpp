#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int long long
int n,k;
int a[200005];
int vis[200005];
void solve()
{
	cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    int ans=0;
    vector<int>v;
    int sum=0,fl=a[1],f0=0;
    for(int i=1;i<=n;i++){
        if(fl==a[i]&&f0)continue;
        if(a[i]==fl){
            sum++;
        }
        else{
            sum=1;
            f0=0;
            fl=a[i];
        }
        if(sum>=k){
            f0=1;
            v.push_back(fl);
            continue;
        }
    }
    // for(int i=0;i<v.size();i++){
    //     cout<<v[i]<<" ";
    // }
    // cout<<endl;

    int l=0,r=0,al,ar;
    ans=-1;
    sum=-1;
    for(int i=1;i<v.size();i++){
        if(sum==-1){
            sum=1;
            l=v[0];
            r=v[0];
        }
        if(v[i]==v[i-1]+1){
            sum++;
            r=v[i];
        }
        else {
            sum=1;
            l=v[i];
            r=v[i];
        }
        if(sum>ans){
            ans=sum;
            al=l;
            ar=r;
        }
    }
    if(sum==-1)cout<<-1<<endl;
    else cout<<al<<" "<<ar<<endl;
    //cout<<ans<<endl;
}
signed main()
{
	int __;
	cin >> __;
	//__=1;
	while (__--)
		solve();
}