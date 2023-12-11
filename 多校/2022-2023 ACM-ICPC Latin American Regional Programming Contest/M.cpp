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
const int N=111;
struct node{
	bitset<N>a;int b;
	bool operator<(const node&t)const{
		if(t.b!=b)return t.b<b;
		for(int i=0;i<111;i++)
			if(t.a[i]!=a[i])
				return t.a[i]<a[i];
		return 0;
	}
};
map<node,bool>MP;
bitset<N>p[1111];
bitset<N>s;
string str;
int n,m,res=0;
void R(bitset<N>&x)
{
	bool y=x[0];
	x>>=1;
	x[m-1]=y;
}
void L(bitset<N>&x)
{
	bool y=x[m-1];
	x<<=1;
	x[0]=y;
	x[m]=0;
}
void dfs(int step,bitset<N>now)
{
	if(res)return ;
	if(MP.count({now,step}))return ;
	MP[{now,step}]=1;
	// cout<<step<<endl;
	if(step==n+1){
		res=1;
		return ;
	}
	bitset<N>l=now,r=now;
	for(int i=0;i<m;i++)
	{
		if((l&p[step]).count()!=0)break;
		if((l&p[step+1]).count()==0)dfs(step+1,l);
		// if(step>1&&(l&p[step-1]).count()==0)dfs(step-1,l);
		L(l);
	}
	for(int i=0;i<m;i++)
	{
		if((r&p[step]).count()!=0)break;
		if((r&p[step+1]).count()==0)dfs(step+1,r);
		// if(step>1&&(r&p[step-1]).count()==0)dfs(step-1,r);
		R(r);
	}
	l=now,r=now;
	for(int i=0;i<m;i++)
	{
		if((l&p[step]).count()!=0)break;
		// if((l&p[step+1]).count()==0)dfs(step+1,l);
		if(step>1&&(l&p[step-1]).count()==0)dfs(step-1,l);
		L(l);
	}
	for(int i=0;i<m;i++)
	{
		if((r&p[step]).count()!=0)break;
		// if((r&p[step+1]).count()==0)dfs(step+1,r);
		if(step>1&&(r&p[step-1]).count()==0)dfs(step-1,r);
		R(r);
	}
}
void solve()
{
	cin>>n>>m;
	string S;
	cin>>str;
	S=str;
	for(int i=0;i<m;i++)
		if(str[i]=='1')s[i]=1;
	for(int i=1;i<=n;i++)
	{
		cin>>str;
		for(int j=0;j<m;j++)
			if(str[j]=='1')
				p[i][j]=1;
	}
	dfs(0,s);
	if(!res)
	{
		reverse(S.begin(),S.end());
		for(int i=0;i<m;i++)
			if(S[i]=='1')s[i]=1;
			else s[i]=0;
		dfs(0,s);
	}
	if(res)cout<<"Y"<<endl;
	else cout<<"N"<<endl;
}
signed main(){
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.in.txt","r",stdin);
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.out.txt","w",stdout);
	// ios::sync_with_stdio(false);
	// cin.tie(nullptr);cout.tie(nullptr);
	// int __;cin>>__;
	// while(__--)
		solve();
//  fclose(stdin);
//  fclose(stdout);
	return 0;
}
/*
100
101


001011
010110
101100
011001
110010
100101
001011
001011



*/