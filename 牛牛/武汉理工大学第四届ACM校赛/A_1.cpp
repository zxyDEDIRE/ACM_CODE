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
const int maxn=1e6+100;
struct node{
	int op;ll x;
}p[maxn];
struct ExKmp{
	void exkmp(char *s,int lens,char *t,int lent,int *ext,int *nxt)
	{
		ext[0]=0;
		for(int i=1,p0=0,p=0;i<=lens;i++)
		{
			ext[i]=i<=p?min(nxt[i-p0+1],p-i+1):0;
			while(i+ext[i]<=lens&&ext[i]<lent&&s[i+ext[i]]==t[ext[i]+1])ext[i]++;
			if(i+ext[i]-1>=p&&i!=1)p0=i,p=i+ext[i]-1;                  //最右端
		}
	}
	void debug_ext(int *ext,int len){
		for (int i=1;i<=len;i++){
			printf("[debug] ext[%d]=%d\n",i,ext[i]);
		}
	}
	void debug_nxt(int *nxt,int len){
		for (int i=1;i<=len;i++){
			printf("[debug] nxt[%d]=%d\n",i,nxt[i]);
		}
	}
}exKMP;
struct Manacher{
	char ch[maxn];
	int lc[maxn];
	int N;
	void init(char *s){
		int n=strlen(s+1);
		// puts(s+1);
		ch[n*2+1]='#';
		ch[0]='@';
		ch[n*2+2]='\0';
		for(int i=1;i<=n;i++)
			ch[i*2]=s[i],ch[i*2-1]='#';
		N=n*2+1;
	}
	void manacher(){
		lc[1]=1;  int k=1,ma=1;
		for (int i=2;i<=N;i++){
			int p = k+lc[k]-1;
			if (i<=p){
				lc[i]=min(lc[2*k-i],p-i+1);
			}else{	lc[i]=1;}
			while(ch[i+lc[i]]==ch[i-lc[i]])lc[i]++;
			if(i+lc[i]>k+lc[k])k=i;
			ma=max(ma,lc[i]-1);
		}
		// printf("%d\n",ma);
	}
	void debug(){
		puts(ch);
		for (int i=1;i<=N;i++){
			printf("lc[%d]=%d\n",i,lc[i]);
		}
	}
}Manch;
int len[maxn];
char ch[maxn];
int nxt[maxn];
int n,q;
void solve()
{
	cin>>n>>q>>ch+1;
	for(int i=1;i<=q;i++){
		cin>>p[i].op;
		if(p[i].op==1)cin>>ch[++n];
		else cin>>p[i].x;
		len[i]=n;
	}
	ch[n+1]='\0';
	Manch.init(ch);
	Manch.manacher();
	exKMP.exkmp(ch,strlen(ch+1),ch,strlen(ch+1),nxt,nxt);
	for(int i=1;i<=q;i++)
	{
		auto [op,k]=p[i];
		n=len[i];
		k=k%(2*n);
		if(op==1)continue;
		int flag=1;


		if(k==0)
		{
			int x=n+1;
			int y=Manch.lc[x]/2;
			int l=2*y-1;
			if(l<n)flag=0;
		}
		else if(k==n)
			flag=1;
		else if(k<n)
		{
			if(nxt[(n-k+1)]<k)flag=0;
			int x=n + (n-k+1);
			int y=Manch.lc[x]/2;
			int l=y*2;
			if(x%2==0)l--;
			if(l<(n-k))flag=0;
		}
		else if(k>n)
		{
			if(nxt[n-(n*2-k)+1]<(n*2-k))flag=0;
			int x=n + (n-(n*2-k)+1);
			int y=Manch.lc[x];
			int l=y*2;
			if(x%2==0)l--;
			if(l<(k-n))flag=0;
		}
		
		if(flag)cout<<"Yes"<<endl;
		else cout<<"No"<<endl;
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
/*
#a#b#b#a#

*/