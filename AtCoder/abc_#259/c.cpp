/*
	嵌套变量是否相同
	特殊样例比如 0 1 2 n
	数组是否越界
	开long long
*/
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
using ll=long long;
using pii=pair<int,int>;
const int maxn=1e6;
string a,b;
vector<char>x,y;
vector<int>xx,yy;
void solve()
{
	cin>>a>>b;
	char ch;
	int len;

	ch=a[0];
	len=1;
	for(int i=2;i<a.size();i++)
	{
		if(a[i]==ch)len++;
		else
		{
			x.push_back(ch);
			xx.push_back(len);
			ch=a[i];
			len=1;
		}
	}
	x.push_back(ch);
	xx.push_back(len);

	ch=b[0];
	len=1;
	for(int i=2;i<b.size();i++)
	{
		if(b[i]==ch)len++;
		else
		{
			y.push_back(ch);
			yy.push_back(len);
			ch=b[i];
			len=1;
		}
	}
	y.push_back(ch);
	yy.push_back(len);
	// for(auto i:x)
	// 	cout<<i<<" ";cout<<endl;
	// for(auto i:y)
	// 	cout<<i<<" ";cout<<endl;
	// cout<<endl;
	if(x!=y||xx.size()!=yy.size()){
		cout<<"No"<<endl;
		return ;
	}
	for(int i=0;i<xx.size();i++)
	{
		if(xx[i]==yy[i])continue;
		else if(xx[i]>yy[i])
		{
			cout<<"No"<<endl;
			return ;
		}
		else if(xx[i]<yy[i]&&xx[i]==1)
		{
			cout<<"No"<<endl;
			return ;
		}
	}
	cout<<"Yes"<<endl;
}
int main()
{	
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	solve();
	return 0;
}