#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
const int maxn=1e6;
int p[maxn];
set<int>s;
int n,x,y;
int main()
{
	cin>>n;
	while(n--)
	{
		int x,y;
		cin>>x>>y;
		if(x==1)
		{
			int a=s.size();
			s.insert(y);
			int b=s.size();
			if(a==b)cout<<"Already Exist"<<endl;
		}
		else
		{
			if(s.empty()){
				cout<<"Empty"<<endl;
				continue;
			}
			if(s.count(y))
			{
				cout<<y<<endl;
				s.erase(y);
			}
			else
			{
				s.insert(y);
				auto x=s.find(y);
				x--;
				int a=*x;
				if(s.count(a)==0)a=0;
				x++;x++;
				int b=*x;
				if(s.count(b)==0)b=0;
				if(a&&b)
				{
					if(abs(a-y)<=abs(b-y))
					{
						cout<<a<<endl;
						s.erase(a);
					}
					else
					{
						cout<<b<<endl;
						s.erase(b);
					}
				}
				else if(a&&!b)
				{
					cout<<a<<endl;
						s.erase(a);
				}
				else
				{
					cout<<b<<endl;
						s.erase(b);
				}
				s.erase(y);
			}
		}
	}
}