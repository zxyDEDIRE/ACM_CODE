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
const int maxn=2e6+100;
int Get_Min(string &p,int n)
{
	int i=0,j=1,k=0;
	while(i<n&&j<n&&k<n)
	{
		if(p[(i+k)%n]==p[(j+k)%n])k++;
		else
		{
			if(p[(i+k)%n]>p[(j+k)%n])i=i+k+1;
			else j=j+k+1;
			if(i==j)i++;
			k=0;
		}
	}
	return min(i,j);
}
int Get_Max(string &p,int n)
{
	int i=0,j=1,k=0;
	while(i<n&&j<n&&k<n)
	{
		if(p[(i+k)%n]==p[(j+k)%n])k++;
		else
		{
			if(p[(i+k)%n]<p[(j+k)%n])i=i+k+1;
			else j=j+k+1;
			if(i==j)i++;
			k=0;
		}
	}
	return min(i,j);
}
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
	/* 循环周期 形如 acaca 中 ac 是一个合法周期 */
	vector<int> periodic()
	{
		vector<int>ret;
		int now=len;
		while(now)
		{
			now=nxt[now];
			ret.push_back(len-now);
		}
		return ret;
	}
	/* 循环节 形如 acac 中ac、acac是循环节，aca不是*/
	vector<int> periodic_loop()
	{
		vector<int>ret;
		for(auto i:periodic())
		{
			if(len%i==0)
				ret.push_back(i);
		}
		return ret;
	}
	void debug(){
		for (int i=0;i<=len;i++){
			printf("[debug] nxt[%d]=%d\n",i,nxt[i]);
		}
	}
}kmp;
char ch[maxn];
char s[maxn];
char t[maxn];
string str;
int n;
void solve()
{
	while(cin>>str)
	{
		n=str.size();
		int tmp_mi=Get_Min(str,n);
		int tmp_ma=Get_Max(str,n);
		int ans_mi;
		int ans_ma;
		for(int i=1;i<=n;i++)
		{
			s[i]=str[(i-1+tmp_mi)%n];
			t[i]=str[(i-1+tmp_ma)%n];
			ch[i]=ch[i+n]=str[i-1];
		}
		s[n+1]=t[n+1]=ch[n+n+1]='\0';
		kmp.init(s);
		ans_mi=kmp.kmp(ch,s)-(tmp_mi==0);

		kmp.init(t);
		ans_ma=kmp.kmp(ch,t)-(tmp_ma==0);


		cout<<tmp_mi+1<<" "<<ans_mi<<" "<<tmp_ma+1<<" "<<ans_ma<<endl;
	}
	
}
signed main(){
 // freopen("data.in","r",stdin);
 // freopen("data.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
		solve();
	return 0;
}