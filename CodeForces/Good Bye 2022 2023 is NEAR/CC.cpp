/*
	嵌套变量重复
	特殊样例 0 1 2 n
	数组越界
	开long long
*/
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long
using ull=unsigned long long;
using ll=long long;
using pii=pair<int,int>;
const int dx[]={0,0,1,-1,1,-1,1,-1};
const int dy[]={1,-1,0,0,1,-1,-1,1};
const int mod=998244353;
const int inf=0x3f3f3f3f;
const int INF=1e9+7;
const int maxn=1e6+100;
int mp[111][111];
int p[maxn];
int n;
void solve()
{
	cin>>n;
	memset(mp,0,sizeof(mp));
	map<int,bool>s;
	int fl=0;
	for(int i=1;i<=n;i++)
	{
		cin>>p[i];
		if(s.count(p[i]))fl=1;
		s[p[i]]=true;
		for(int j=2;j<=100;j++)
			mp[j][p[i]%j]++;
	}
	if(fl){
		cout<<"No"<<endl;
		return ;
	}
	for(int j=2;j<=100;j++)
	{
		int flag=1;
		for(int i=0;i<j;i++)
			if(mp[j][i]<2)
				flag=0;
		if(flag){
			cout<<"No"<<endl;
			return ;
		}
	}
	cout<<"Yes"<<endl;
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