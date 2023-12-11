#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long 
#define pp(x) array<int,x>
using ull=unsigned long long;
using ll=long long;
using pii=pair<int,int>;
using pdd=pair<double,double>;
const int dx[]={0,0,1,-1,1,-1,1,-1};
const int dy[]={1,-1,0,0,1,-1,-1,1};
const int mod=998244353;
const int inf=0x3f3f3f3f;
const int INF=1e9+7;
const int maxn=1e6+100;
int k;
void solve()
{
	// cin>>k;
	// k=3;
	cout<<" K: ";
	cin>>k;
	int s=1145158346688;
	/*
		2145144213434
	*/
	for(int i=s;i;i++)
	{
		cout<<i<<endl;
		int x=i;
		int y=i*k;
		string _x =to_string(x);
		string _y =to_string(y);
		if(_x.size()!=_y.size())continue;
		int len=_x.size();
		int ok=0;
		for(int j=0;j<len;j++)
		{
			int l=j;
			int r=0;
			int flag=1;
			for(int k=0;k<len;k++)
				if(_x[l]!=_y[r])flag=0;
				else l=(l+1)%len,r++;
			if(flag)ok=1;
		}
		if(ok){
			cout<<_x<<" "<<_y<<endl;
			exit(0);
		}
	}
}
signed main(){
 // freopen("data.in","r",stdin);
 // freopen("data.out","w",stdout);
	// ios::sync_with_stdio(false);
	// cin.tie(nullptr);cout.tie(nullptr);
	// int __;cin>>__;
	// while(__--)
		solve();
	return 0;
}
/*
k=2
142857
285714
428571

k=3
142857
153846
230769
285714
307692

k=4
102564 
128205 
142857 
153846 
179487 
190476 
205128 
230769 
238095 

k=5
142857

k=6
142857

k=9
109890
*/