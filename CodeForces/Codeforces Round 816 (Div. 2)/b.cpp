/*
	嵌套变量重复
	特殊样例 0 1 2 n
	数组越界
	开long long
*/
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
using ll=long long;
using pii=pair<int,int>;
const int inf=0x3f3f3f3f;
const int INF=1e9+7;
const int maxn=1e6;
ll p[maxn];
ll n,k,b,s,cnt;
void NO(){
	cout<<-1<<endl;
}
void solve()
{
	cin>>n>>k>>b>>s;
	memset(p+1,0ll,sizeof(ll)*n);
	p[1]=b*k;
	s-=p[1];
	if(s<0)return NO();
	for(int i=2;i<=n;i++)
	{
		if(s>=k-1)
		{
			p[i]=k-1;
			s-=k-1;
		}
		else
		{
			p[i]=s;
			s=0;
		}
	}
	if(s<=k-1)
	{
		p[1]+=s;
	}
	else return NO();
	for(int i=1;i<=n;i++)
		cout<<p[i]<<" ";
	cout<<endl;



}
signed main(){
//  freopen("in1.txt","r",stdin);
//  freopen("out1.txt","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	int __;cin>>__;
	while(__--)
		solve();
//  fclose(stdin);
//  fclose(stdout);
	return 0;
}