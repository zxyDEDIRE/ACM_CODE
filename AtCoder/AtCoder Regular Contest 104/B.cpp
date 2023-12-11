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
bool ok(char s,char t)
{
	if(s=='#'&&t=='#')return 1;
	if(s=='C'&&t=='G')return 1;
	if(s=='G'&&t=='C')return 1;
	if(s=='A'&&t=='T')return 1;
	if(s=='T'&&t=='A')return 1;
	return 0;
}
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
			if(i%2==0)continue;
			int p = k+lc[k]-1;
			if (i<=p){
				lc[i]=min(lc[2*k-i],p-i+1);
			}else{	lc[i]=1;}
			while(ok(ch[i+lc[i]],ch[i-lc[i]]))lc[i]++;
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
	void doit()
	{
		int ans=0;
		for(int i=1;i<=N;i++)
			ans+=lc[i]/2;
		cout<<ans<<endl;
	}
}Manch;
char s[maxn];
int n;
void solve()
{
	scanf("%d",&n);
	scanf("%s",s+1);
	Manch.init(s);
	Manch.manacher();
	Manch.debug();
	Manch.doit();
}
signed main(){
 // freopen("C:\\Users\\tob\\Desktop\\P4391_9.in.txt","r",stdin);
 // freopen("C:\\Users\\tob\\Desktop\\P4391_9.out.txt","w",stdout);
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
21
ATGCATCGTCAGCTAGCTACG
13
GCTAGCTGCTACG
GC
GCTAGC
AGCT
GC
TA
CG
*/