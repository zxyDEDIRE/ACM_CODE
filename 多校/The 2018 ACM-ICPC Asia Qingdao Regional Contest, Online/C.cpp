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
const int maxn=1e6+100;
struct node{
	int op,v,k;
}p[maxn];
bitset<maxn>vis;
int in[maxn];
int n;
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		in[i]=0;
		string op;cin>>op;
		if(op=="add"){
			p[i].op=1;
			cin>>p[i].v;
		}
		else if(op=="beq"){
			p[i].op=2;
			cin>>p[i].v>>p[i].k;
		}
		else if(op=="bne"){
			p[i].op=3;
			cin>>p[i].v>>p[i].k;
		}
		else if(op=="blt"){
			p[i].op=4;
			cin>>p[i].v>>p[i].k;
		}
		else if(op=="bgt"){
			p[i].op=5;
			cin>>p[i].v>>p[i].k;
		}
	}
	vis.reset();
	int r=0;
	int x=1;
	while(x<=n)
	{
		auto [op,v,k]=p[x];
		in[x]++;
		if(in[x]>260){
			cout<<"No\n";
			return ;
		}
		if(op==1){
			r=(r+v)%256;
			x++;
		}
		else if(op==2){
			if(r==v)x=k;
			else x++;
		}
		else if(op==3){
			if(r!=v)x=k;
			else x++;
		}
		else if(op==4){
			if(r<v)x=k;
			else x++;
		}
		else if(op==5){
			if(r>v)x=k;
			else x++;
		}
	}
	cout<<"Yes"<<endl;
}
signed main(){
 // freopen("data.in","r",stdin);
 // freopen("data.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	int __;cin>>__;
	while(__--)
		solve();
	return 0;
}
/*
4
2
add 1
blt 5 1
3
add 252
add 1
bgt 252 2
2
add 2
bne 7 1
3
add 1
bne 252 1
beq 252 1

*/