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
const int dx[]={0,0,1,-1,1,-1,1,-1};
const int dy[]={1,-1,0,0,1,-1,-1,1};
const int mod=998244353;
const int inf=0x3f3f3f3f;
const int INF=1e9+7;
const int maxn=1e6+100;
struct KMP{
	int nxt[maxn];
	int ans[maxn];
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
	/* 循环周期 形如 acaca 中 ac 是一个合法周期 */
	void f()
	{
		for(int i=2;i<=len;i++)
			if(i%(i-nxt[i])==0&&nxt[i]){
				cout<<i<<" "<<i/(i-nxt[i])<<endl;
			}
	}
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
int n;
void solve()
{
	cin>>ch+1;
	kmp.init(ch);
	kmp.f();
}
signed main(){
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.in.txt","r",stdin);
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.out.txt","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	int cnt=0;
	while(cin>>n&&n){
		cout<<"Test case #"<<++cnt<<endl;
		solve();
		cout<<endl;
		// break;
	}
//  fclose(stdin);
//  fclose(stdout);
	return 0;
}