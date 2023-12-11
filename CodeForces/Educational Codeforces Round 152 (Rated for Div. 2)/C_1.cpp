#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+100;
const int N=3e5+10;
const int INF=1e9;
using pii=pair<int,int>;
class A{
public:
	int n,m;
	string s;
	int l[N],r[N];
	int sum[N][2];
	unsigned long long ha[N];
	unsigned long long base=13331;
	unsigned long long p[N],o[N],z[N];
	void init(int n=N-10)
	{
		p[0]=1;
		for(int i=1;i<=n;i++)
		{
			z[i]=(z[i-1]*base+'0');
			o[i]=(o[i-1]*base+'1');
			p[i]=p[i-1]*base;
		}
	}
	int solve(int N,int M,string s1)
	{
		// cin>>n>>m;
		// cin>>s;
		n=N,m=M;
		s=s1;
		s="_"+s;
		for(int i=1;i<=n;i++)
		{
			ha[i]=(ha[i-1]*base+s[i]);
		}
		for(int i=1;i<=n;i++)
		{
			sum[i][0]=sum[i-1][0];
			sum[i][1]=sum[i-1][1];
			sum[i][s[i]-'0']++;
		}
		map<unsigned long long,bool>mp;
		int res=0;
		while(m--)
		{
			int l,r;
			cin>>l>>r;
			int oo=sum[r][1]-sum[l-1][1];
			int zz=sum[r][0]-sum[l-1][0];
			unsigned long long mid=(z[zz]*p[oo]+o[oo]);
			unsigned long long f=ha[l-1],bf=(ha[n]-(ha[r]*p[n-r]));
			unsigned long long ans=(f*p[n-(l-1)]+mid*p[n-r]+bf);
			if(mp.count(ans)==false) res++;
			mp[ans]=true;
		}
		return res;
	}
}a;
class B{
public:
	char ch[maxn];
	int a[maxn];
	int b[maxn];
	int n,m;
	int solve(int N,int M,string S)
	{
		cin>>n>>m;
		for(int i=0;i<S.size();i++)
			ch[i+1]=S[i];
		ch[S.size()+1]='\0';
		int fl=INF;
		for(int i=n;i>=1;i--)
		{
			if(ch[i]=='1')fl=i;
			a[i]=fl;
		}
		fl=-1;
		for(int i=1;i<=n;i++)
		{
			if(ch[i]=='0')fl=i;
			b[i]=fl;
		}
		set<pii>s;
		for(int i=1;i<=m;i++)
		{
			int l,r;
			cin>>l>>r;
			l=a[l];
			r=b[r];
			if(l>=r)l=-1,r=-1;
			s.insert({l,r});
		}
		return s.size();
	}
}b;
int main()
{
	srand(time(0));
	while(1)
	{
		int n,m;
		string ans;


		n=rand()%1000+1;
		m=rand()%1000+1;
		for(int i=1;i<=n;i++)
		{
			ans=ans+(char)(rand()%2+'0');
		}
	}
}