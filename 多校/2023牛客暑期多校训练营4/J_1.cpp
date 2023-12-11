/*
	嵌套变量重复 特殊样例 0 1 2 n 数组越界 开long long
	清空 建图别用vector
*/
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
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
void solve()
{
	vector<array<int,4>>v;
	for(int i=-3;i<=3;i++)
	{
		for(int j=-3;j<=3;j++)
		{
			for(int k=-3;k<=3;k++)
			{
				if(i+j<0)continue;
				if(j+k<0)continue;
				if(i+j+k<0)continue;
				array<int,4>a{i,j,k,min(j+k,k)};
				v.push_back(a);
			}
		}
	}
	sort(v.begin(),v.end(),[&](array<int,4>a ,array<int,4>b){
		return a[3]<b[3];
	});
	for(auto [x,y,z,w]:v)
		cout<<x<<" "<<y<<" "<<z<<" "<<w<<endl;
	cout<<v.size()<<endl;
}
signed main(){
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.in.txt","r",stdin);
 freopen("C:\\Users\\tob\\Desktop\\out.txt","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	// int __;cin>>__;
	// while(__--)
		solve();
//  fclose(stdin);
//  fclose(stdout);
	return 0;
}