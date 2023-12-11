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
int f(char ch){
	if(ch=='W')return 0;
	if(ch=='U')return 1;
	if(ch=='B')return 2;
	if(ch=='G')return 3;
	if(ch=='R')return 4;
	if(ch=='O')return 5;
}
void solve()
{
	int n;
	cin>>n;
	vector<int>p(6,0);
	for(int i=1;i<=n;i++){
		char ch;cin>>ch;
		p[f(ch)]++;
	}
	int m;
	cin>>m;
	for(int i=1;i<=m;i++)
	{
		string str;cin>>str;
		for(auto x:str)
			p[f(x)]--;
	}
	int sum=0;
	for(int i=0;i<5;i++)
		if(p[i]<0){
			cout<<"NO"<<endl;
			return ;
		}
		else sum+=p[i];
	if(p[5]+sum>=0)cout<<"YES"<<endl;
	else cout<<"NO"<<endl;
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