#include<bits/stdc++.h>
using namespace std;

#define  ull unsigned long long

const int N = 1e6 + 10, SIZ = 1000000;
const ull mod=212370440130137957ll;
const ull base=131;
const ull prime=233317;
string p[N];
int nxt[N];
int n;
ull Hash1(int id, int x){
	ull val = 0;
	for(int i = 1; i <= x; i ++){
		val = val * 131 + (p[id][i] - 'a' + 1);
	}
	return val;
}

ull Hash2(int id, int x){
	ull val = 0;
	for(int i = 1; i <= x; i ++){
		val=(val*base+(ull)(p[id][i]))%mod+prime;
	}
	return val;
}

int loop(string &s)
{
	s=" "+s;
	int len=s.size()-1;
	
	nxt[1]=0;
	for(int i=2;i<=len;i++)
	{
		nxt[i]=nxt[i-1];
		while(s[nxt[i]+1]!=s[i]&&nxt[i])
			nxt[i]=nxt[nxt[i]];
		if(s[nxt[i]+1]==s[i])nxt[i]++;
	}
	int now=len,res;
	now=nxt[now];
	res=len-now;
	if(len%res)res=len;
	return res;
}

map<ull, int>mp1, mp2;
ull solve(){
	mp1.clear();
	mp2.clear();
	ull ans=0;
	for(int i=1;i<=n;i++)
	{
		int len=p[i].size();
		int x=loop(p[i]);
		ull now1 = Hash1(i, x);
		ull now2 = Hash2(i, x);
		ans += min(mp1[now1], mp2[now2]);
		mp1[now1] ++;
		mp2[now2] ++;
	}
	return ans;
//	cout<<ans<<"\n";
}
ull so()
{
	ull ans=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			if(p[i]+p[j]==p[j]+p[i])ans++;
		}
	}
	return ans;
}
 
int main()
{
//	ios::sync_with_stdio(0);
//	cin.tie(0);cout.tie(0);
	srand(time(0));
	while(true)
	{
		n=rand()%5+2;
		
		for(int i=1;i<=n;i++)
		{
			int m=rand()%10+1;
			p[i]="";
			for(int j=1;j<=m;j++)
			{
				p[i]=p[i]+(char)('a'+rand()%26);
			}
		}
		ull x=solve();
		ull y=so();
		if(x!=y){
			cout<<"NO"<<endl;
			cout<<n<<endl;
			for(int i=1;i<=n;i++)
			cout<<p[i]<<endl;
			cout<<x<<" "<<y<<endl;
			return 0;
		}
		else cout<<"Yes"<<endl;
	}
	return 0;
}
/*
11
aehtbbdcx
aerian
aiixmu
aqa
ajsxie
af
akeyl
aqmngdq
ayjyxngfn
av
auqsfo
*/


