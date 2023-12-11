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
char s[maxn];
int q,n;
void solve()
{
	scanf("%s",s+1);
	n=strlen(s+1);
	kmp.init(s);
	vector<int>v=kmp.periodic();
	int t=v[0];
	for(int i=v.size()-1;i>=0;i--)
	{
		if(i-1>=0)
			v[i]=max(v[i-1]+1,v[i]-t+1);
		else v[i]=v[i]-t+1;
	}
	scanf("%d",&q);
	while(q--)
	{
		int x;
		// cin>>x;
		scanf("%d",&x);
		int fl=upper_bound(v.begin(),v.end(),max(x,n-x+1))-v.begin()+1;
		// cout<<x<<" "<<fl<<" "<<v.size()-fl+1<<endl;
		// int len=v.size()-fl+1;
		// cout<<v.size()-fl+1<<endl;
		printf("%d\n",v.size()-fl+1);
	}	
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
ccpc
c#pc


#cacacacacac
a#acacacacac
ac#cacacacac
aca#acacacac
acac#cacacac
acaca#acacac
acacac#cacac
acacaca#acac
acacacac#cac
acacacaca#ac
acacacacac#c
acacacacaca#
*/