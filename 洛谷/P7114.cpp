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
struct ExKmp{
//result: ext[i] = LCP(S[i,lens],T)
//require: nxt[i] = LCP(T[i,lent],T)
//nxt : s  Mode_String
//ext : s  Text_String t Mode_String
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
char s[maxn];
int nxt[maxn];
int num[maxn][30];
int n;
void solve()
{
	scanf("%s",s+1);
	n=strlen(s+1);
	exKMP.exkmp(s,n,s,n,nxt,nxt);
	exKMP.debug_nxt(nxt,n);

	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<26;j++)
			num[i][j]+=num[i-1][j];
		num[i][s[i]-'0']++;
	}

	

	

}
signed main(){
 // freopen("C:\\Users\\tob\\Desktop\\P4391_9.in.txt","r",stdin);
 // freopen("C:\\Users\\tob\\Desktop\\P4391_9.out.txt","w",stdout);
	// ios::sync_with_stdio(false);
	// cin.tie(nullptr);cout.tie(nullptr);
	int __;cin>>__;
	while(__--)
		solve();
//  fclose(stdin);
//  fclose(stdout);
	return 0;
}
/*
nnrnnr
[debug] nxt[1]=6
[debug] nxt[2]=1
[debug] nxt[3]=0
[debug] nxt[4]=3
[debug] nxt[5]=1
[debug] nxt[6]=0


*/