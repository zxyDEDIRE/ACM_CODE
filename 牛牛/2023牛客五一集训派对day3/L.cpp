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
const int dx[]={0,0,1,-1,1,-1,1,-1};
const int dy[]={1,-1,0,0,1,-1,-1,1};
const int mod=998244353;
const int inf=0x3f3f3f3f;
const int INF=1e9+7;
const int maxn=1e6+100;
string fl="Lovely";
string s,t;
void solve()
{
	cin>>s;
	int flag=1;
	t=s.substr(0,6);
	for(int i=0;i<t.size();i++)
	{
		if(i==0||i==4)
		{
			if(t[i]!='L'&&t[i]!='l')flag=0;
		}
		else if(i==1)
		{
			if(t[i]!='o'&&t[i]!='O')flag=0;
		}
		else if(i==2)
		{
			if(t[i]!='v'&&t[i]!='V')flag=0;
		}
		else if(i==3)
		{
			if(t[i]!='e'&&t[i]!='E')flag=0;
		}
		else if(i==5)
		{
			if(t[i]!='y'&&t[i]!='Y')flag=0;
		}
	}
	if(flag)cout<<t<<endl;
	else cout<<"ugly"<<endl;
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