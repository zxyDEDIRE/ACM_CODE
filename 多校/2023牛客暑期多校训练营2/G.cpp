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
const int maxn=2e6+200;
bool check(char a,char b)
{
	if(a=='b'&&b=='q')return 1;
	if(a=='d'&&b=='p')return 1;
	if(a=='p'&&b=='d')return 1;
	if(a=='q'&&b=='b')return 1;
	if(a=='n'&&b=='u')return 1;
	if(a=='u'&&b=='n')return 1;
	if(a=='o'&&a==b)return 1;
	if(a=='s'&&a==b)return 1;
	if(a=='x'&&a==b)return 1;
	if(a=='z'&&a==b)return 1;
	if(a=='#'&&a==b)return 1;
	return 0;
}
char def_char(char a)
{
	if(a=='b')return 'q';
	if(a=='d')return 'p';
	if(a=='p')return 'd';
	if(a=='q')return 'b';
	if(a=='n')return 'u';
	if(a=='u')return 'n';
	if(a=='o')return a;
	if(a=='s')return a;
	if(a=='x')return a;
	if(a=='z')return a;
	if(a=='#')return a;
	return '!';
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
			int p = k+lc[k]-1;
			if (i<=p){
				lc[i]=min(lc[2*k-i],p-i+1);
			}else if(def_char(ch[i])==ch[i]){
				lc[i]=1;}
			else lc[i]=0;
			while(check(ch[i+lc[i]],ch[i-lc[i]]))lc[i]++;
			if(i+lc[i]>k+lc[k])k=i;
			ma=max(ma,lc[i]-1);
		}
	}
	void debug(){
		puts(ch);
		for (int i=1;i<=N;i++){
			printf("lc[%d]=%d\n",i,lc[i]);
		}
	}
}Manch;
char ch[maxn];
int n;
void NO(){cout<<"No"<<endl;}
void solve()
{
	cin>>ch+1;
	n=strlen(ch+1);
	Manch.init(ch);
	Manch.manacher();
	int pre=-1;
	for(int i=2;i<=Manch.N;i+=2)
	{
		char D=def_char(Manch.ch[i]);
		if(D==Manch.ch[i])continue;
		if(D=='!')return NO();
		if(pre==-1){
			pre=i;
			continue;
		}
		if(Manch.ch[pre]!=D)continue;
		int l=pre;
		int r=i;
		int mid=(l+r)>>1;
		// cout<<l<<" "<<r<<" "<<mid<<" "<<Manch.lc[mid]<<endl;
		if(def_char(Manch.ch[mid])!=Manch.ch[mid])continue;
		if(mid-Manch.lc[mid]>l)continue;
		// cout<<"OK"<<endl;
		pre=-1;
	}
	if(pre==-1)cout<<"Yes"<<endl;
	else cout<<"No"<<endl;
}
signed main(){
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.in.txt","r",stdin);
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.out.txt","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	int __;cin>>__;
	while(__--)
		solve();
//  fclose(stdin);
//  fclose(stdout);
	return 0;
}
/*
onuuzx
zzzuzozns
snxuunz
sbbzzqq
uunznuzunn
*/