/*
	嵌套变量重复
	特殊样例 0 1 2 n
	数组越界
	开long long
*/
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
// #define p(x) array<int,x>
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
	cin>>n;
	vector<int>p(n+1,0);	
	for(int i=1;i<=n;i++)
		cin>>p[i];
	auto mg_sort = [&](auto mg_sort,int l,int r)->ll{
		if(l>=r)return 0;
		int mid=(l+r)>>1;
		ll t = mg_sort(mg_sort,l,mid)+mg_sort(mg_sort,mid+1,r);
		vector<int>temp;
		int i=l,j=mid+1;
		while(i<=mid&&j<=r)
		{
			if(p[i]<=p[j])temp.push_back(p[i++]);
			else t+=mid-i+1,temp.push_back(p[j++]);
		}
		while(i<=mid)temp.push_back(p[i++]);
		while(j<=r)temp.push_back(p[j++]);
		for(int i=l,j=0;i<=r;i++,j++)
			p[i]=temp[j];
		return t;
	};
	cout<<mg_sort(mg_sort,1,n);
}
signed main(){
 // freopen("C:\\Users\\tob\\Desktop\\P4391_9.in.txt","r",stdin);
 // freopen("C:\\Users\\tob\\Desktop\\P4391_9.out.txt","w",stdout);
	// ios::sync_with_stdio(false);
	// cin.tie(nullptr);cout.tie(nullptr);
	// int __;cin>>__;
	// while(__--)
		solve();
//  fclose(stdin);
//  fclose(stdout);
	return 0;
}