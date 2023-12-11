#include<bits/stdc++.h>
using namespace std;
const int N=5;
struct pp
{
	long long a,b,y;
}p[N];
bool cmp(pp x,pp y)
{
	return x.y<y.y;
}
bool check(int id,int id1)
{
	return p[id].y==p[id1].y;
}

void solve()
{
	for(int i=1;i<=2;i++)
	{
		cin>>p[i].a>>p[i].b>>p[i].y;
	}
	sort(p,p+3,cmp);
	if(check(0,1)&&check(1,2))
	{
		cout<<"Yes\n";return;
	}
	if(check(0,1))
	{
		long long l=max(p[0].a,p[1].a);
		long long r=min(p[0].b,p[1].b);
		if(l>r)
		{
			cout<<"No\n";
		}
		else{
			cout<<"Yes\n";
		}
		return;
	}
	if(check(1,2))
	{
		long long l=max(p[2].a,p[1].a);
		long long r=min(p[2].b,p[1].b);
		if(l>r)
		{
			cout<<"No\n";
		}
		else{
			cout<<"Yes\n";
		}
		return;
	}
	if(p[0].a!=p[1].b&&p[0].b!=p[1].a)
	{
		if((p[2].y)*(p[1].a-p[0].b)-((p[1].a-p[0].b)*p[0].y-(p[1].y-p[0].y)*p[0].b)<=((p[1].y-p[0].y))*p[2].b
		&&(p[1].y-p[0].y)*p[2].a<=(p[2].y)*(p[1].b-p[0].a)-((p[1].b-p[0].a)*p[0].y-(p[1].y-p[0].y)*p[0].a))
		{
			cout<<"Yes\n";
		}
		else{
			cout<<"No\n";
		}
	}
	else if(p[0].a==p[1].b)
	{
		if((p[2].y)*(p[1].a-p[0].b)-((p[1].a-p[0].b)*p[0].y-(p[1].y-p[0].y)*p[0].b)<=((p[1].y-p[0].y))*p[2].b
		&&p[2].a<=p[0].a)
		{
			cout<<"Yes\n";
		}
		else{
			cout<<"No\n";
		}
	}
	else if(p[0].b==p[1].a)
	{
		if(p[0].b<=p[2].b
		&&(p[1].y-p[0].y)*p[2].a<=(p[2].y)*(p[1].b-p[0].a)-((p[1].b-p[0].a)*p[0].y-(p[1].y-p[0].y)*p[0].a))
		{
			cout<<"Yes\n";
		}
		else{
			cout<<"No\n";
		}
	}
	
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	while(cin>>p[0].a>>p[0].b>>p[0].y)
	{
		solve();
	}
	return 0;
}
