/*
	嵌套变量重复
	特殊样例 0 1 2 n
	数组越界
	开long long
*/
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long
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
	int n,k,x,ans=0;
	vector<int>p,v;
	cin>>n>>k>>x;
	p.resize(n+1);
	for(int i=1;i<=n;i++)
		cin>>p[i];

	auto h=[&](int mid)->int{
		int ans=0;
		for(auto i:v)
			ans+=abs(i-mid);
		return ans;
	};

	auto f=[&]()->int{
		int l=*min_element(v.begin(),v.end());
		int r=*max_element(v.begin(),v.end());
		while(l<r-1)
		{
			int mid_l=ceil(l+1.0*(r-l)/3);
			int mid_r=floor(l+1.0*(r-l)*2/3);
			int ans_l=h(mid_l);
			int ans_r=h(mid_r);
			// cout<<l<<" "<<r<<endl;
			// cout<<mid_l<<" "<<mid_r<<endl;
			// cout<<ans_l<<" "<<ans_r<<endl;
			// cout<<endl;
			if(ans_l>=ans_r)l=mid_l;
			else r=mid_r;
		}
		while(h(l+1)<h(l))l++;
		while(h(l-1)<h(l))l--;
		return h(l);
	};

	for(int i=1;i<=k;i++)
	{
		v.clear();
		for(int j=i;j<=n;j+=k)
			v.push_back(p[j]);
		ans+=f();
		// cout<<ans<<endl;
		// break;
	}
	cout<<ans*x<<endl;
}
signed main(){
 // freopen("C:\\Users\\tob\\Desktop\\P4391_9.in.txt","r",stdin);
 // freopen("C:\\Users\\tob\\Desktop\\P4391_9.out.txt","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	int __;cin>>__;
	while(__--)
		solve();
//  fclose(stdin);
//  fclose(stdout);
	return 0;
}
/*
1
8 2 4
1 3 5 7 9 11 13 15
*/