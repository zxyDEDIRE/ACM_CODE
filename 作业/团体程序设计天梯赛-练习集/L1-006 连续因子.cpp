/*
	嵌套变量重复 特殊样例 0 1 2 n 数组越界 开long long
	清空 建图别用vector
*/
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define pp(x) array<int,x>
using ull=unsigned long long;
using ll=long long;
using pii=pair<int,int>;
const int dx[]={0,0,1,-1,1,-1,1,-1};
const int dy[]={1,-1,0,0,1,-1,-1,1};
const int mod=998244353;
const int inf=0x3f3f3f3f;
const int INF=1e9+7;
const int maxn=1e6+100;
void solve()
{
	int n;
	int l=1,r=13,ans=0,_l=1,_r=0;
	cin>>n;
	auto check=[&](int k)->bool{
		long long now=1;
		for(int i=2;i<=1+k;i++)
			now*=i;
		if(n%now==0){
			_l=2,_r=1+k;
			return 1;
		}
		for(int i=3;i+k-1<=n;i++)
		{
			now=now/(i-1)*(i+k-1);
			if(now>n)break;
			if(n%now==0){
				_l=i,_r=i+k-1;
				return 1;
			}
		}
		return 0;
	};
	while(l<r-1)
	{
		int mid=(l+r)>>1;
		if(check(mid))ans=mid,l=mid;
		else r=mid;
	}
	while(check(ans+1))ans++;
	cout<<ans<<endl;
	for(int i=_l;i<=_r;i++)
	{
		cout<<i;
		if(i!=_r)cout<<"*";
	}
	cout<<endl;
}
void solve_1()
{
	int n;
	vector<int>v;
	cin>>n;
	for(int i=2;i*i<=n;i++)
		if(n%i==0){
			v.push_back(i);
			if(n/i!=i)
				v.push_back(n/i);
		}
	sort(v.begin(),v.end());
	int ans=0,_l=0,_r=0,now=1;
	for(int i=0,r=0;i<v.size();i++)
	{
		if(r<i)now=1,r=i;
		while(r<v.size()&&v[r]-v[i]==r-i&&now*v[r]<=n)
			r++;
		// cout<<v[i]<<" "<<v[r]<<" "<<now<<endl;
		now/=v[i];
		if(r-i>ans)
		{
			ans=r-i;
			_l=v[i];
			_r=v[r-1];
		}
	}
	cout<<ans<<endl;
	// cout<<_l<<" "<<_r<<endl;
	for(int i=_l;i<=_r;i++)
	{
		cout<<i;
		if(i!=_r)cout<<"*";
	}
}
signed main(){
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.in.txt","r",stdin);
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.out.txt","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	// int __;cin>>__;
	// while(__--)
		solve_1();
//  fclose(stdin);
//  fclose(stdout);
	return 0;
}
/*
362880
2 3 4 5 6 7
*/