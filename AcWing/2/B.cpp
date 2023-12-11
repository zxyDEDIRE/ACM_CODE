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
int n;
void solve()
{
	int l=0,r=0;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		char ch;
		int x;
		cin>>ch>>x;
		if(i==1)p[x]=0;
		else
		{
			if(ch=='L')l++,p[x]=-l;
			else if(ch=='R')r++,p[x]=r;
			else if(ch=='?')
			{
				if(p[x]<0)cout<<min(l+p[x],r-p[x])<<endl;
				else if(p[x]>0)cout<<min(l+p[x],r-p[x])<<endl;
				else cout<<min(l,r)<<endl;
			}
		}
	}
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