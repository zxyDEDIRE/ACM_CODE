/*
	嵌套变量重复
	特殊样例 0 1 2 n
	数组越界
	开long long
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
	int n,q;
	vector<int>pre,suf;

	cin>>n>>q;
	pre.resize(n+1);
	suf.resize(n+1);
	for(int i=1;i<=n;i++)
		pre[i]=suf[i]=i;

	auto find_p=[pre](auto self,int r)->int{
		return pre[r]=pre[r]==r?pre[r]:self(self,pre[r]);
	};
	auto find_s=[suf](auto self,int r)->int{
		return suf[r]=suf[r]==r?suf[r]:self(self,suf[r]);
	};

	while(q--)
	{
		int op,x,y;
		cin>>op;
		if(op==1)
		{
			cin>>x>>y;
			pre[y]=x;
			suf[x]=y;
		}
		else if(op==2)
		{
			cin>>x>>y;
			pre[y]=y;
			suf[x]=x;
		}
		else
		{
			vector<int>v;
			cin>>x;
			while(pre[x]!=x)
				x=pre[x];
			while(suf[x]!=x){
				v.push_back(x);
				x=suf[x];
			}
			v.push_back(x);
			cout<<v.size()<<" ";
			for(auto i:v)
				cout<<i<<" ";
			cout<<endl;
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