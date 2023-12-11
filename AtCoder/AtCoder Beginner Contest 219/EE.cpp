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
int f(int x,int y){return (x-1)*4+y-1;}
bool vis[100];
int mp[100];
int p[100];
int n=4,cnt=0;
int find(int r){
	return p[r]=p[r]==r?p[r]:find(p[r]);
}
void un(int x,int y)
{
	int fa=find(x);
	int fb=find(y);
	if(fa!=fb)p[fa]=fb;
}
int check(int tmp)
{
	for(int i=0;i<16;i++)
	{
		if(tmp&(1<<i))vis[i]=1;
		else vis[i]=0;
		if(mp[i]&&!vis[i])return 0;
		p[i]=i;
	}
	p[16]=16;
	for(int i=0;i<16;i++)
	{
		if(i+4<16&&vis[i]==vis[i+4])un(i,i+4);
		if(i%4<=2&&vis[i]==vis[i+1])un(i,i+1);
		if(!vis[i])un(i,16);
	}
	int cnt=0;
	for(int i=0;i<=16;i++)
		if(find(i)==i)cnt++;
	return cnt==2;
}
void solve()
{
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++){
			int ch;cin>>ch;
			if(ch)mp[f(i,j)]=1;
		}
	for(int tmp=0;tmp<(1<<16);tmp++)
		cnt+=check(tmp);
	cout<<cnt<<endl;
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