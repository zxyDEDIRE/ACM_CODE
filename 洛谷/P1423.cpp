#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
const int maxn=1e6;
double x,y=2;
int main()
{
	cin>>x;
	int cnt=0;
	while(x>0)
	{
		cnt++;
		x-=y;
		y*=0.98;
	}
	cout<<cnt<<endl;
}