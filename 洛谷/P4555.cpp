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
char ch[maxn];
int lc[maxn];
int l[maxn];
int r[maxn];
int N;
struct Manacher{
	
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
		// puts(ch);
		lc[1]=1;  int k=1,ma=0;
		for (int i=2;i<=N;i++){
			int p = k+lc[k]-1;
			if (i<=p){
				lc[i]=min(lc[2*k-i],p-i+1);
			}else{	lc[i]=1;}
			while(ch[i+lc[i]]==ch[i-lc[i]])lc[i]++;
			if(i+lc[i]>k+lc[k])k=i;
			l[i+lc[i]-1]=max(l[i+lc[i]-1],lc[i]-1);
			r[i-lc[i]+1]=max(r[i-lc[i]+1],lc[i]-1);
		}
		// for(int i=1;i<=N;i+=2)
		// {
		// 	cout<<i<<" "<<l[i]<<" "<<r[i]<<endl;
		// }
		// cout<<endl;
		for(int i=N;i>=1;i--)
			l[i]=max(l[i+2]-2,l[i]);
		for(int i=1;i<=N;i++)
			r[i]=max(r[i-2]-2,r[i]);
		// cout<<l[13]<<" "<<r[13]<<endl;
		for(int i=3;i<=N-1;i+=2)
		{
			// cout<<i<<" "<<l[i]<<" "<<r[i]<<" "<<l[i]+r[i]<<endl;
			ma=max(ma,l[i]+r[i]);
		}
		cout<<ma<<endl;
	}
	void debug(){
		puts(ch);
		for (int i=1;i<=N;i++){
			printf("lc[%d]=%d\n",i,lc[i]);
		}
	}
}Manch;
char s[maxn];
void solve()
{
	scanf("%s",s+1);
	Manch.init(s);
	Manch.manacher();
}
signed main(){
 // freopen("C:\\Users\\tob\\Desktop\\P4391_9.in.txt","r",stdin);
 // freopen("C:\\Users\\tob\\Desktop\\P4391_9.out.txt","w",stdout);
	// ios::sync_with_stdio(false);
	// cin.tie(nullptr);cout.tie(nullptr);
		solve();
//  fclose(stdin);
//  fclose(stdout);
	return 0;
}
/*
#a#b#a#
#b#a#a#c#a#a#b#b#a#c#a#b#b#
qwq
abcba
adsaaas
*/