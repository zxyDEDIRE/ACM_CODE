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
	int n;
	vector<int>p;
	cin>>n;
	p.resize(n);
	for(auto &i:p)
		cin>>i;
	int cnt_a=0,cnt_b=0,ma=0;
	for(auto i:p)
	{
		if(i==0)cnt_a++;
		else cnt_b++;
		ma=max(ma,i);
	}
	if(cnt_a<=cnt_b+1)cout<<0<<endl;
	else if(ma!=1)cout<<1<<endl;
	else cout<<2<<endl;
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
0 0 1 0 1 0 1 0 1 0 1 0
*/