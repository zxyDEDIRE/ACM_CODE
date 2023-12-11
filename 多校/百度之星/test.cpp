#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int maxn=1e6+100;


int main()
{
	set<int>a;
	auto x= a.lower_bound(2);
	if(x==a.begin())cout<<"SDF"<<endl;
	else cout<<"SSDF"<<endl;
	cout<<*x<<endl;
	x--;
	if(x==a.begin())cout<<"SDF"<<endl;
	cout<<*x<<endl;
}