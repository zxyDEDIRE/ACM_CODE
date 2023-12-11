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
const int maxn=1e6;
vector<int>v[maxn];
int p[maxn];
int n,m;
void solve()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>p[i];
		// int l=1,r=m;
		// if(p[i]<0)l=(-p[i]+i-1)/i;

		int l=max(1,(-p[i]+i-1)/i);
		int r=min(m,(n-p[i]+i-1)/i);
		// cout<<"l:"<<l<<" r:"<<r<<endl;
		for(int j=l;j<=r;j++){
			v[j].push_back(p[i]+j*i);
			// cout<<p[i]+j*i<<" ";
		}
		// cout<<endl;
	}
	// cout<<"*************"<<endl;
	for(int i=1;i<=m;i++)
	{
		sort(v[i].begin(),v[i].end());
		int fl=0;
		for(auto j:v[i])
		{
			// cout<<j<<" ";
			if(j==fl)fl++;
			else if(j<fl);
			else break;
		}
		// cout<<endl;
		cout<<fl<<endl;
	}
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