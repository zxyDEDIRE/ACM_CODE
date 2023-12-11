/*
	嵌套变量重复
	特殊样例 0 1 2 n
	数组越界
	开long long
*/
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
using ull=unsigned long long;
using ll=long long;
using pii=pair<int,int>;
const int dx[]={0,0,1,-1,1,-1,1,-1};
const int dy[]={1,-1,0,0,1,-1,-1,1};
const int mod=998244353;
const int inf=0x3f3f3f3f;
const int INF=1e9+7;
const int maxn=1e6+100;
string s;
int n,k;
void solve()
{
	cin>>n>>k>>s;
	char ma='a',mi='z';
	vector<int>vis(100,0);
	for(auto i:s){
		mi=min(mi,i),ma=max(ma,i),vis[i-'a']=1;
	}
	if(k>n)	
	{
		cout<<s;
		for(int i=0;i<k-n;i++)
			cout<<mi;
		cout<<endl;
		return ;
	}
	int fl;
	for(int i=k-1;i>=0;i--)
	{
		if(s[i]==ma)continue;
		char x=s[i];x++;
		while(!vis[x-'a'])x++;
		s[i]=x;
		fl=i;
		break;
	}
	for(int i=0;i<k;i++)
	{
		if(i<=fl)cout<<s[i];
		else cout<<mi;
	}
	cout<<endl;
}
signed main(){
 // freopen("C:\\Users\\tob\\Desktop\\P4391_9.in.txt","r",stdin);
 // freopen("C:\\Users\\tob\\Desktop\\P4391_9.out.txt","w",stdout);
	// ios::sync_with_stdio(false);
	// cin.tie(nullptr);cout.tie(nullptr);
	int __;cin>>__;
	while(__--)
		solve();
//  fclose(stdin);
//  fclose(stdout);
	return 0;
}