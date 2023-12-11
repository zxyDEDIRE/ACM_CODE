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
struct KMP{
	int nxt[maxn];
	int len;
	void init(string s)
	{
		nxt[1]=0;
		len=s.size()-1;
		for(int i=2;i<=len;i++)
		{
			nxt[i]=nxt[i-1];
			while(s[nxt[i]+1]!=s[i]&&nxt[i])
				nxt[i]=nxt[nxt[i]];
			if(s[nxt[i]+1]==s[i])nxt[i]++;
		}
	}
	void kmp(string s,string t)
	{
		int lens=s.size()-1;
		int lent=t.size()-1;
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
		cout<<cnt<<endl;
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
// char s[maxn];
// char t[maxn];
string s,t;
void solve()
{
	cin>>s;
	cin>>t;
	s=" "+s;
	t=" "+t;
	kmp.init(s);
	kmp.kmp(t,s);
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