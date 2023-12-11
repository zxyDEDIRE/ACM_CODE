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
const int mod=19930726;
const int inf=0x3f3f3f3f;
const int INF=1e9+7;
const int maxn=2e6+100;
char ch[maxn];
int lc[maxn];
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
int fp(int b,int p)
{
	int res=1;
	while(p)
	{
		if(p&1)res=(res*b)%mod;
		p>>=1;
		b=(b*b)%mod;
	}
	return res;
}
int mull(int a,int b)
{
	int qw=0;
	while(b)
	{
		if(b&1)qw=(qw+a)%mod;
		a=(a+a)%mod;
		b>>=1;
	}
	return qw;
}
char s[maxn];
void solve()
{
	int n,k;
	scanf("%lld%lld",&n,&k);
	scanf("%s",s+1);
	// puts(s+1);
	Manch.init(s);
	Manch.manacher();
	// Manch.debug();
	vector<int>v;
	for(int i=2;i<=N;i+=2)
		v.push_back(lc[i]-1);
	
	sort(v.begin(),v.end(),[&](int a,int b){
		return a>b;
	});
	// for(auto i:v)
	// 	cout<<i<<" ";cout<<endl;
	int ans=1;
	int num=0;
	int x,y=-1;
	for(int i=0;i<v.size();i++)
	{
		x=v[i];
		if(num)
		{
			for(int j=y-2;j>=x;j-=2)
			{
				if(k>=num){
					ans=mull(ans,fp(j,num)),k-=num;
				}
				else if(k)
					ans=mull(ans,fp(j,k)),k=0;
			}
		}
		if(!k)break;
		ans=mull(ans,x);k--;
		y=x;
		num++;
	}
	// if(k)cout<<-1<<endl;
	// else cout<<ans<<endl;

	if(k)printf("-1\n");
	else printf("%lld\n",ans);
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
100 100
ababaaababbaaaababbababbbaabaaaaabaaaaabaaabbabaabbaaaabbababbaaabbabaaabbbbabbbbaaabbbabbabbabbbbbb

*/