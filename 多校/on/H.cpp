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
const int N=300;
bitset<N>q[N];
int p[maxn];
int l[maxn];
int k,r,len;
void solve()
{
	cin>>k>>r;
	len=ceil(1.0*512/r);
	int x=256-len;
	int ans_1=x/(k-1);
	int ans_2=x%(k-1);
	int ned=128-len;
	// cout<<"Len:"<<len<<endl;
	// cout<<"ned "<<ned<<" ans_1:"<<ans_1<<" x:"<<x<<endl;
	// cout<<"ans_2:"<<ans_2<<endl;

	int ano=ned-(r-1)*ans_1;
	int sum=0;
	// cout<<"ano "<<ano<<endl;

	p[1]=len;
	for(int i=2;i<=k;i++)
		p[i]=ans_1;
	for(int i=r;i<=k;i+=r){
		if(ano>0)
			p[i]+=ano;
		sum+=ano;
	}
	// cout<<"sum:"<<sum<<endl;
	if(sum>ans_2){
		cout<<-1<<endl;
		return ;
	}
	else if(ano>=0&&sum<ans_2)
		p[k-1]+=ans_2-sum;


	
	// for(int i=1;i<=k;i++)
	// {
	// 	p[i]+=p[i-1];
	// 	int r=p[i];
	// 	int l=r-len+1;
	// 	for(int j=1;j<=256;j++)
	// 		if(j>=l&&j<=r)
	// 			q[i][j]=1;
	// 		else q[i][j]=0;
	// }
	// for(int i=1;i+r-1<=k;i++)
	// {
	// 	bitset<N>now;
	// 	for(int j=0;j<r;j++)
	// 		now|=q[i+j];
	// 	if(now.count()<128){
	// 		cout<<-1<<endl;
	// 		return ;
	// 	}
	// }
	for(int i=1;i<=k;i++)
	{
		p[i]+=p[i-1];
		int r=p[i];
		int l=r-len+1;
		for(int j=1;j<=256;j++)
			if(j>=l&&j<=r)cout<<"1";
			else cout<<"0";
		cout<<endl;
	}


}
signed main(){
 // freopen("data.in","r",stdin);
 // freopen("data.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	// for(int k=3;k<=26;k++)
	// 	for(int r=3;r<=k;r++)
			solve();
	return 0;
}
/*
22 6 0
22 7
23 6
23 7 0
24 6
24 7
24 8
25 6
25 7
25 8
25 9
26 5
26 6
26 7
26 8
26 9
26 10
*/