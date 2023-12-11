/*
	嵌套变量重复
	特殊样例 0 1 2 n
	数组越界
	开long long
*/
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
using ull=unsigned long long;
using ll=long long;
using pii=pair<int,int>;
const int dx[]={0,0,1,-1,1,-1,1,-1};
const int dy[]={1,-1,0,0,1,-1,-1,1};
const int mod=998244353;
const int inf=0x3f3f3f3f;
const int INF=1e9+7;
const int maxn=1e6+100;
map<int,int>mpa,mpb;
set<int>s,t;
int ans[maxn];
int p[maxn];
int a[maxn];
int n,m,k,sum;
void solve()
{
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++)
		cin>>p[i],a[i]=p[i];
	sort(a+1,a+1+m,[&](int x,int b){
		return x<b;
	});

	for(int i=1;i<=m;i++)
		mpa[a[i]]++,s.insert(a[i]);
	
	for(int i=1;i<=k;i++)
		sum+=a[i],mpb[a[i]]++,t.insert(a[i]);

	ans[m]=sum;
	if(t.count(p[1]))
	{
		mpb[p[1]]--;
		if(mpb[p[1]]==0)t.erase(p[1]);
		sum-=p[1];
	}
	mpa[p[1]]--;
	if(mpa[p[1]]==0)s.erase(p[1]);


	cout<<sum<<endl;
	for(int i=m+1;i<=m+1;i++)
	{
		mpa[p[i]]++;
		s.insert(p[i]);

		int top=*s.begin();
		mpb[top]++;
		t.insert(top);
		sum+=top;
		ans[i]=top;

		int x=p[i-m+1];
		mpa[x]--;
		if(mpa[x]==0)s.erase(x);

		if(t.count(x))
		{
			mpb[x]--;
			if(mpb[x]==0)t.erase(x);
			sum-=x;
		}
	}
	for(int i=m;i<=n;i++)
		cout<<ans[i]<<" ";
	cout<<endl;
}
signed main(){
 // freopen("C:\\Users\\tob\\Desktop\\P4391_9.in.txt","r",stdin);
 // freopen("C:\\Users\\tob\\Desktop\\P4391_9.out.txt","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	// int __;cin>>__;
	// while(__--)
		solve();
//  fclose(stdin);
//  fclose(stdout);
	return 0;
}