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
struct Manacher{
	int ch[maxn];
	int lc[maxn];
	int N;
	void init(int *s,int n){
		ch[n*2+1]=-1;
		ch[0]=-2;
		ch[n*2+2]='\0';
		for(int i=1;i<=n;i++)
			ch[i*2]=s[i],ch[i*2-1]=-1;
		ch[n*2+1]=-1;
		ch[1]=-1;
		N=n*2+1;
	}
	void manacher(){
		lc[1]=1;  int k=1,ma=1;
		for (int i=2;i<=N;i++){
			int p = k+lc[k]-1;
			if (i<=p){
				lc[i]=min(lc[2*k-i],p-i+1);
			}else{	lc[i]=1;}

			while(1)
			{
				int flag=0;
				if(ch[i+lc[i]]==ch[i-lc[i]])
				{
					if(ch[i+lc[i]]==-1)flag=1;
					else if( (i+lc[i])%2==0 && lc[i]>=2&&ch[i+lc[i]]<=ch[i+lc[i]-2])flag=1;
					else if( (i+lc[i])%2==0 && lc[i]<2)flag=1;
				}
				if(!flag)break;
				else lc[i]++;
			}


			if(i+lc[i]>k+lc[k])k=i;
			ma=max(ma,lc[i]-1);
		}
		cout<<ma<<endl;
	}
	void debug(){
		// puts(ch);
		for(int i=0;i<=N;i++)
			cout<<ch[i]<<" ";cout<<endl;
		for (int i=1;i<=N;i++){
			printf("lc[%d]=%d\n",i,lc[i]);
		}
	}
}Manch;
int s[maxn];
int n;
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>s[i];
	Manch.init(s,n);
	Manch.manacher();
	// Manch.debug();
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
4 3 3 
*/