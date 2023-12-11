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
vector<int>f(int x)
{
	vector<int>v;
	while(x){
		v.push_back(x%2);
		x>>=1;
	}
	return v;
}
void solve()
{
	int n;
	cin>>n;
	vector<int>p=f(n);
	int s=n;
	int a=n,b=0;
	for(int i=p.size()-1;i>=0;i--)
	{
		if(p[i])continue;
		int x=(1<<i);
		if(s>=x*2)
		{
			s-=x*2;
			a+=x;
			b+=x;
		}
	}
	if(s){
		cout<<-1<<endl;
		return ;
	}
	cout<<a<<" "<<b<<endl;
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
/*
10010
11001
01011

1010
1101
0111
*/