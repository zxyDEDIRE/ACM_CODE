#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define endl "\n";
struct node{
	int op,x1,y1,x2,y2,r;
	char ch;
};
int n;
void solve()
{
	cin>>n;
	vector<node>p;

	auto f=[&](int x,int y)->void{
		int len=(int)p.size();
		for(int i=len-1;i>=0;i--)
		{
			auto l=p[i];
			if(l.op==0)
			{
				ll now=1ll*(x-l.x1)*(x-l.x1) + 1ll*(y-l.y1)*(y-l.y1);
				// cout<<now<<" "<<l.r*l.r<<endl;
				if(now<=1ll*l.r*l.r)
				{
					cout<<l.ch;
					return ;
				}
			}
			else
			{
				if(x>=l.x1&&x<=l.x2&&y>=l.y1&&y<=l.y2)
				{
					cout<<l.ch;
					return ;
				}
			}
		}
		cout<<".";
	};

	for(int i=1;i<=n;i++)
	{
		string op;
		cin>>op;
		if(op=="Circle")
		{
			node now;
			cin>>now.x1>>now.y1>>now.r>>now.ch;
			now.op=0;
			p.push_back(now);
		}
		else if(op=="Rectangle")
		{
			node now;
			cin>>now.x1>>now.y1>>now.x2>>now.y2>>now.ch;
			now.op=1;
			p.push_back(now);
		}
		else
		{
			int x1,y1,x2,y2;
			cin>>x1>>y1>>x2>>y2;
			for(int j=y2;j>=y1;j--)
			{
				for(int i=x1;i<=x2;i++)
					f(i,j);
				cout<<endl;
			}
		}
	}
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
		solve();
	return 0;
}
/*
7
Circle 0 0 5 *
Circle -2 2 1 @
Circle 2 2 1 @
Rectangle 0 -1 0 0 ^
Rectangle -2 -2 2 -2 _
Render -5 -5 5 5
Render -1 0 1 2

2
Circle 0 0 5 *
Render -1 -1 0 0

.....*.....
..*******..
.**@***@**.
.*@@@*@@@*.
.**@***@**.
*****^*****
.****^****.
.**_____**.
.*********.
..*******..
.....*.....
@*@
***
*^*

.....*.....
..*******..
.**@***@**.
.*@@@*@@@*.
.**@***@**.
*****^*****
.****^****.
.**_____**.
.*********.
..*******..
.....*.....
@*@
***
*^*


*/