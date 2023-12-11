#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
const int maxn=1e6;
struct node{
	ll x,y;
}p[maxn];
int n,m,k,ma;
bool check(int id)
{
	ll x=p[id].x;
	for(int i=1;i<=n;i++)
	{
		if(i==id)i++;
		if(x<p[i].x)return 0;
		x*=2;
		if(x>=p[n].x)break;
	}
	return 1;
}
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>p[i].x;
		p[i].y=i;
	}
	sort(p+1,p+1+n,[&](node a,node b){
		return a.x<b.x;});
	int l=1,r=n,ans=r;
	while(l<r-1)
	{
		int mid=(l+r)>>1;
		if(check(mid))ans=mid,r=mid;
		else l=mid;
	}
	if(check(ans-1))ans=ans-1;
	//cout<<ans<<endl;
	vector<int>v;
	
	for(int i=1;i<=n;i++)
		if(i>=ans)v.push_back(p[i].y);
	sort(v.begin(),v.end());
	cout<<v.size()<<endl;
	for(auto i:v)
		cout<<i<<" ";
	
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    solve();
    return 0;
}