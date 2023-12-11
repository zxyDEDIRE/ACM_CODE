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
using ull=unsigned long long;
using ll=long long;
using pii=pair<int,int>;
const int dx[]={0,0,1,-1,1,-1,1,-1};
const int dy[]={1,-1,0,0,1,-1,-1,1};
const int inf=0x3f3f3f3f;
const int INF=1e9+7;
const int maxn=1e6;
vector<int>v[maxn];
set<int>s;
int n;
int ms(vector<int>&p,int l,int r)
{
	if(l==r)return 0;
	int mid=(l+r)>>1;
	int ans=ms(p,l,mid)+ms(p,mid+1,r);
	vector<int>tmp(r-l+1);
	int k=0,i=l,j=mid+1;
	while(i<=mid&&j<=r)
	{
		if(p[i]<=p[j])tmp[k++]=p[i++];
		else
		{
			ans+=mid-i+1;
			tmp[k++]=p[j++];
		}
	}
	while(i<=mid)tmp[k++]=p[i++];
	while(j<=r)tmp[k++]=p[j++];
	for(int i=l,j=0;i<=r;i++,j++)p[i]=tmp[j];
	return ans;
}
void solve()
{
	cin>>n;
	vector<int>p(n);
	vector<int>col(n);
	for(int i=0;i<n;i++)
		cin>>col[i];
	for(int i=0;i<n;i++)
	{
		cin>>p[i];
		s.insert(col[i]);
		v[col[i]].push_back(p[i]);
	}
	int ans=ms(p,0,n-1);
	for(auto i:s)
		ans-=ms(v[i],0,v[i].size()-1);
	cout<<ans<<endl;
}
signed main(){
 // freopen("C:\\Users\\tob\\Desktop\\P4391_9.in.txt","r",stdin);
 // freopen("C:\\Users\\tob\\Desktop\\P4391_9.out.txt","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
		solve();
//  fclose(stdin);
//  fclose(stdout);
	return 0;
}