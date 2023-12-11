/*
	嵌套变量重复
	特殊样例 0 1 2 n
	数组越界
	开long long
*/
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long
using ull=unsigned long long;
using ll=long long;
using pii=pair<int,int>;
const int dx[]={0,0,1,-1,1,-1,1,-1};
const int dy[]={1,-1,0,0,1,-1,-1,1};
const int mod=998244353;
const int inf=0x3f3f3f3f;
const int INF=1e9+7;
const int maxn=1e6+100;
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
		lc[1]=1;
		int k=1;
		for (int i=2;i<=N;i++){
			int p = k+lc[k]-1;
			if (i<=p){
				lc[i]=min(lc[2*k-i],p-i+1);
			}else{	lc[i]=1;}
			if(i%2==0)
			{
				lc[i]=0;
				continue;
			}
			while(1)
			{
				if(ch[i+lc[i]]==ch[i-lc[i]]&&ch[i+lc[i]]=='#')lc[i]++;
				else if((ch[i+lc[i]]=='0'&&ch[i-lc[i]]=='1')||(ch[i+lc[i]]=='1'&&ch[i-lc[i]]=='0'))lc[i]++;
				else break;
			}
			if(i+lc[i]>k+lc[k])k=i;
			// cout<<i<<" "<<lc[i]<<endl;
		}
		// printf("%d\n",ma);
	}
	void debug(){
		// puts(ch);
		// for (int i=1;i<=N;i++){
		// 	printf("lc[%d]=%d\n",i,lc[i]);
		// }
		// cout<<endl;
		int ans=0;
		for(int i=1;i<=N;i+=2){
			// printf("lc[%d]=%d\n",i,lc[i]);
			ans+=(lc[i]-1)/2;
		}
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
7
1000110
123456789012345
#1#0#0#0#1#1#0#
# 1
1#0 3
*/