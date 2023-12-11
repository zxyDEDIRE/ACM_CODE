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
const int N=3e5+10;
class A{
public:
	char ch[maxn];
	int a[maxn];
	int b[maxn];
	int n,m;
	int solve()
	{
		cin>>n>>m>>ch+1;
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
			// cout<<"l r "<<l<<" "<<r<<endl;
		}
		// cout<<s.size()<<endl;
		return s.size();
	}
};
class B{
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
	int solve()
	{
		cin>>n>>m;
		cin>>s;
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
		// cout<<res<<'\n';
		return res;
	}

};
signed main(){
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.in.txt","r",stdin);
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.out.txt","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	


	
//  fclose(stdin);
//  fclose(stdout);
	return 0;
}
/*
yuan

*/