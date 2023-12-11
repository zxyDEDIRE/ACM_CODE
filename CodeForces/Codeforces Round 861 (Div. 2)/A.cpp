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
int f(int x)
{
	vector<int>v;
	while(x){
		v.push_back(x%10);
		x/=10;
	}
	sort(v.begin(),v.end());
	return v.back()-v[0];
}
void solve()
{
	int l,r;
	cin>>l>>r;
	int ma=0,fl=l;
	for(int i=l;i<=min(r,l+100);i++)
	{
		int now=f(i);
		if(now>ma)
		{
			ma=now;
			fl=i;
		}
	}
	cout<<fl<<endl;
}
signed main(){
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.in.txt","r",stdin);
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.out.txt","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	int __;cin>>__;
	while(__--)
		solve();
//  fclose(stdin);
//  fclose(stdout);
	return 0;
}
/*
4911

4911
4922
*/