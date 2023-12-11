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
char ch_1[maxn];
char ch_2[maxn];
char t[maxn];
int n,m,fl;
struct KMP{
	int nxt[maxn];
	int len;
	void init(char *s)
	{
		nxt[1]=0;
		len=strlen(s+1);
		for(int i=2;i<=len;i++)
		{
			nxt[i]=nxt[i-1];
			while(s[nxt[i]+1]!=s[i]&&nxt[i])
				nxt[i]=nxt[nxt[i]];
			if(s[nxt[i]+1]==s[i])nxt[i]++;
		}
	}
	int kmp(char *s,char *t)
	{
		int lens=strlen(s+1);
		int lent=strlen(t+1);
		int cnt=0;
		for(int i=0,j=0;i<lens;i++)
		{
			while(j&&s[i+1]!=t[j+1])j=nxt[j];
			if(s[i+1]==t[j+1])j++;
			if(j==lent)
			{
				cnt++;
				j=nxt[j];
			}
		}
		return cnt;
	}
	void debug(){
		for (int i=0;i<=len;i++){
			printf("[debug] nxt[%d]=%d\n",i,nxt[i]);
		}
	}
}kmp;
void solve()
{
	// cin>>n>>t+1;
	m=strlen(t+1);
	fl=0;
	for(int i=2;i<=m;i++)
		if(t[i]!=t[1])fl=1;
	if(fl==0)
	{
		for(int i=1;i<=n;i++)
			ch_1[i]=(t[1]^1);
		ch_1[n+1]='\0';
		// cout<<ch+1<<endl;
		return ;
	}
	int len=n+m+m;
	for(int i=1;i<=len;i++)
	{
		ch_1[i]=t[m];
		ch_2[i]=(t[m]^1);
	}
	for(int i=1;i<=m;i++)
	{
		ch_1[i]=t[i];
		ch_1[i+len-m]=t[i];
		ch_2[i]=t[i];
		ch_2[i+len-m]=t[i];
	}
	ch_1[len+1]='\0';
	ch_2[len+1]='\0';

	kmp.init(t);
	int cnt_1=kmp.kmp(ch_1,t);
	int cnt_2=kmp.kmp(ch_2,t);
	if(cnt_1>2&&cnt_2>2){
		cout<<"SDFSDFSF"<<endl;
		cout<<cnt_1<<" "<<cnt_2<<endl;
		cout<<n<<" "<<m<<endl;
		cout<<t<<endl;
		cout<<-1<<endl;
		exit(0);
		return ;
	}
	else cout<<"OK"<<endl;

}
signed main(){
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.in.txt","r",stdin);
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.out.txt","w",stdout);
	// ios::sync_with_stdio(false);
	// cin.tie(nullptr);cout.tie(nullptr);
	srand(time(0));
	while(1)
	{
		n=rand()%14+1;
		m=rand()%20+1;
		for(int i=1;i<=m;i++)
			t[i]='0'+rand()%2;
		t[m+1]='\0';
		t[0]=')';
		solve();
	}
//  fclose(stdin);
//  fclose(stdout);
	return 0;
}
/*
101xxxxxx
xxxxxx101

101000101

0011111111001
1011111111101

010100101
1
0100010



*/