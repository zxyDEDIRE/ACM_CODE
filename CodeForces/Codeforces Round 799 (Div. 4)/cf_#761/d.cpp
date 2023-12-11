/*
    嵌套变量重复
    特殊样例 0 1 2 n
    数组越界
    开long long
*/
#include<bits/stdc++.h>
#define int long long
using namespace std;
using ll=long long;
using pii=pair<int,int>;
const int maxn=1e6;
int F(int a,int b,int c)
{
	cout<<"? "<<a<<" "<<b<<" "<<c<<"\n";
	fflush(stdout);
	int fl;
	cin>>fl;
	fflush(stdout);
	return fl;
}
bitset<maxn>vis;
int p[maxn];
int n;
void solve()
{
	cin>>n;
	int a,b,c,d,e,f;
	vis.reset();
	int FA=0,FB=0;
	for(int i=1;i<=n/3;i++)
	{
		int fl=F(i*3-2,i*3-1,i*3);
		p[i]=fl;
		if(fl==0&&FA==0)
		{
			FA=1;
			vis[i]=1;
			a=i*3-2;
			b=i*3-1;
			c=i*3;
		}
		else if(fl==1&&FB==0)
		{
			FB=1;
			vis[i]=1;
			d=i*3-2;
			e=i*3-1;
			f=i*3;
		}
	}

	int g0=-1,g1=-1;

	int aa=-1,bb=-1,cc=-1,dd=-1,ee=-1,ff=-1;
	vector<int>A,B;
	int flag=0;
	int f1=F(a,b,e);
	int f2=F(a,b,f);
	if(f1==0&&f2==0)
	{
		A.push_back(a);
		A.push_back(b);
		g0=a;
		aa=0;
		bb=0;
	}
	else if(f1==1&&f2==0)
	{
		A.push_back(c);
		A.push_back(f);
		g0=c;
		cc=0;
		ee=1;
		ff=0;
		g1=e;
		int f3=F(g0,g1,d);
		if(f1==0)A.push_back(d);
		int f4=F(g0,g1,a);
		if(f4==0)A.push_back(a);
		else A.push_back(b);
	}
	else if(f1==0&&f2==1)
	{
		A.push_back(c);
		A.push_back(e);
		g0=c;
		cc=0;
		ee=0;
		ff=1;
		g1=f;
		f1=F(g0,g1,d);
		if(f1==0)A.push_back(d);
		int f4=F(g0,g1,a);
		if(f4==0)A.push_back(a);
		else A.push_back(b);
	}
	else if(f1==1&&f2==1)
	{
		A.push_back(c);
		g0=c;
		cc=0;
		ee=1;
		ff=1;
		g1=e;
		f1=F(g0,g1,d);
		if(f1==0)A.push_back(d);
		int f4=F(g0,g1,a);
		if(f4==0)A.push_back(a);
		else A.push_back(b);
	}

	if(g1==-1)//aa=0,bb=0
	{
		int f3=F(a,d,e);
		int f4=F(a,e,f);
		int f5=F(a,d,f);
		if(f3==1)g1=d,A.push_back(f);
		else if(f4==1)g1=e,A.push_back(d);
		else if(f5==1)g1=f,A.push_back(e);

		int f6=F(g0,g1,c);
		if(f6==0)A.push_back(c);
	}

	for(int i=1;i<=n/3;i++)
	{
		a=i*3-2;
		b=i*3-1;
		c=i*3;
		if(vis[i])continue;
		if(p[i]==1)
		{
			f1=F(a,b,g0);
			if(f1==1)
			{
				f2=F(g0,g1,c);
				if(f2==0)A.push_back(c);
			}
			else if(f1==0)
			{
				f2=F(g0,g1,a);
				if(f2==0)A.push_back(a);
				else A.push_back(b);
			}
		}
		else if(p[i]==0)
		{
			f1=F(a,b,g1);
			if(f1==1)
			{
				A.push_back(c);
				f2=F(g0,g1,a);
				if(f2==0)A.push_back(a);
				else A.push_back(b);
			}
			else if(f1==0)
			{
				A.push_back(a);
				A.push_back(b);
				f2=F(g0,g1,c);
				if(f2==0)A.push_back(c);
			}
		}
	}

	cout<<"! ";
	cout<<A.size()<<" ";
	for(auto i:A)
		cout<<i<<" ";
	cout<<"\n";


	
}
signed main(){
    int __;cin>>__;
    while(__--)
        solve();
    return 0;
}