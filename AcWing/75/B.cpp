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
struct node{
	string name;
	int id;
	int t;
}p[maxn];
map<string,int>mp;
int n;
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		string a,b;
		cin>>a>>b;
		p[i]={a,i,mp[b]};
	}
	sort(p+1,p+1+n,[&](node a,node b){
		if(a.t!=b.t)return a.t<b.t;
		return a.id<b.id;
	});
	for(int i=1;i<=n;i++)
		cout<<p[i].name<<endl;
}
signed main(){
 // freopen("C:\\Users\\tob\\Desktop\\P4391_9.in.txt","r",stdin);
 // freopen("C:\\Users\\tob\\Desktop\\P4391_9.out.txt","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	// int __;cin>>__;
	// while(__--)
	mp["rat"]=1;
	mp["woman"]=2;
	mp["child"]=2;
	mp["man"]=3;
	mp["captain"]=4;
		solve();
//  fclose(stdin);
//  fclose(stdout);
	return 0;
}