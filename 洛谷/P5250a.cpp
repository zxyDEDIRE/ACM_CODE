#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
const int maxn=1e6;
int main()
{
	int n;
	set<ll>s;
	cin>>n;
	while(n--)
	{
		ll x,y;
		cin>>x>>y;
		if(x==1)
		{
			if(s.count(y))cout<<"Already Exist"<<endl;
			else s.insert(y);
		}
		else if(x==2)
		{
			if(s.count(y)){
				cout<<y<<endl;
				s.erase(y);
			}
			else if(s.empty()){
				cout<<"Empty"<<endl;
			}
			else
			{
				s.insert(y);
				auto it=s.find(y);
				if(it==s.begin())
				{
					it++;
					cout<<*it<<endl;
					s.erase(*it);
				}
				else if(it==s.end())
				{
					it--;
					cout<<*it<<endl;
					s.erase(*it);
				}
				else
				{
					auto is=it;
					it++;
					is--;
					ll b=*it;
					ll a=*is;
					if(abs(a-y)<=abs(b-y))
					{
						s.erase(a);
						cout<<a<<endl;
					}
					else
					{
						s.erase(b);
						cout<<b<<endl;
					}
				}
			}
			s.erase(y);
		}
	}
}