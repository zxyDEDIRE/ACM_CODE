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
const int maxn=2e4+100;
const int N=555;
map<string,int>mp;
string nm[maxn];
pii p[maxn];
int f[maxn];
int num[maxn];
int n,m,k,q;
int get(int x,int y){
	return (x-1)*m+y;
}
int find(int r){
	cout<<r<<endl;
	return f[r]=f[r]==r?f[r]:find(f[r]);
}
void check(int x,int y,int k,int op=1)
{
	if(x<1||y<1||x>n||y>m){
		if(op)
			cout<<"out of bounds!"<<endl;
		return ;
	}
	int fa=find(get(x,y));
	if(fa==0)
	{
		f[get(x,y)]=k;
		num[k]++;
		p[k].first=x,p[k].second=y;
		if(op)cout<<"vanquish!"<<endl;
	}
	else if(fa==k)
	{
		p[k].first=x,p[k].second=y;
		if(op)cout<<"peaceful."<<endl;
	}
	else
	{
		int fa=find(get(x,y));
		int fl=0;
		if(num[fa]>num[k])fl=1;
		else if(num[fa]<num[k])fl=-1;
		else if(nm[fa]>nm[k])fl=1;
		else fl=-1;

		if(fl==1)
		{
			num[fa]+=num[k];
			f[k]=fa;
			mp[nm[k]]=0;
			if(op)cout<<nm[fa]<<" wins!"<<endl;
		}
		else
		{
			num[fa]=num[k];
			f[fa]=k;
			p[k].first=x,p[k].second=y;
			mp[nm[fa]]=0;
			if(op)cout<<nm[k]<<" wins!"<<endl;
		}
	}
}
void solve()
{
	cin>>n>>m>>k;
	for(int i=1;i<=k;i++){
		int x,y;
		cin>>nm[i]>>x>>y;
		mp[nm[i]]=i;
		check(x,y,i,0);
	}
	cin>>q;
	while(q--)
	{
		string str;
		char op;
		cin>>str>>op;
		int k=mp[str];
		if(k==0){
			cout<<"unexisted empire."<<endl;
			continue;
		}
		auto [x,y]=p[k];
		if(op=='W')check(x-1,y,k);
		else if(op=='S')check(x+1,y,k);
		else if(op=='A')check(x,y-1,k);
		else check(x,y+1,k);
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