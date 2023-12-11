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
int p[maxn];
int n,s;
void NO(){cout<<"No"<<endl;}
void YES(){cout<<"Yes"<<endl;}
void solve()
{
	cin>>n>>s;
	for(int i=1;i<=n;i++)
		cin>>p[i];
	sort(p+1,p+1+n);
	int fl=1,t=0;

	for(int i=1;i<=n;i++)
	{
		while(fl<p[i])
		{
			t+=fl;
			fl++;
		}
		fl++;
	}
	s-=t;
	if(s<0)return NO();
	while(s>0)
	{
		s-=fl;
		fl++;
	}
	if(s!=0)return NO();
	return YES();
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