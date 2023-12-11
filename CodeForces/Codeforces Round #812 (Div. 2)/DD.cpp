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
void out(int x,int y){cout<<"? "<<x<<" "<<y<<endl;}
int in(){int x;cin>>x;return x;}
void solve()
{
	int n;
	cin>>n;
	n=(1<<n);
	vector<int>v(n,0);
	for(int i=1;i<=n;i++)
		v[i-1]=i;
	while(v.size()>=4)
	{
		vector<int>p;
		for(int i=0;i<v.size();i+=4)
		{
			int a=v[i+0];
			int b=v[i+1];
			int c=v[i+2];
			int d=v[i+3];
			int ans;
			out(a,c);
			ans=in();
			if(ans==1)//a>c
			{
				out(a,d);
				ans=in();
				if(ans==1)p.push_back(a);
				else p.push_back(d);
			}
			else if(ans==2)//a<c
			{
				out(b,c);
				ans=in();
				if(ans==1)p.push_back(b);
				else p.push_back(c);
			}
			else
			{
				out(b,d);
				ans=in();
				if(ans==1)p.push_back(b);
				else p.push_back(d);
			}
		}
		v=p;
	}
	out(v[0],v[1]);
	int ans=in();
	if(ans==1)cout<<"! "<<v[0]<<endl;
	else cout<<"! "<<v[1]<<endl;
}
signed main(){
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.in.txt","r",stdin);
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.out.txt","w",stdout);
	// ios::sync_with_stdio(false);
	// cin.tie(nullptr);cout.tie(nullptr);
	int __;cin>>__;
	while(__--)
		solve();
//  fclose(stdin);
//  fclose(stdout);
	return 0;
}
/*
0 0 1 2
*/