/*
	嵌套变量重复 特殊样例 0 1 2 n 数组越界 开long long
	清空 建图别用vector
*/
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
vector<int>v;
int n,q;
void solve()
{
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		int x;cin>>x;
		v.push_back(x);
	}
	sort(v.begin(),v.end());
	while(q--)
	{
		int op,x,y;
		cin>>op;
		if(op==1)
		{
			cin>>x;
			if(x>v.back())v.push_back(x);
			else
			{
				int fl=lower_bound(v.begin(),v.end(),x)-v.begin();
				if(v[fl]!=x)v[fl]=x;
			}
		}
		else if(op==2)
		{
			cin>>x>>y;
			int fl_1=lower_bound(v.begin(),v.end(),x)-v.begin();
			int fl_2=upper_bound(v.begin(),v.end(),y)-v.begin();
			cout<<fl_2-fl_1<<endl;
		}
	}
}
signed main(){
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.in.txt","r",stdin);
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.out.txt","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	// int __;cin>>__;
	// while(__--)
		solve();
//  fclose(stdin);
//  fclose(stdout);
	return 0;
}
/*
10 11
7 1 7 1 3 9 7 9 10 4
2 2 8
1 8
2 2 8
2 1 20
1 20
2 1 20
2 7 12
1 5
2 7 12
1 12
2 7 12

*/