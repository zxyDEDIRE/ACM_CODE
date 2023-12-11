#include<bits/stdc++.h>
using namespace std;
using int64 = long long;
int n,C;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin>>n>>C;
	vector<int64>p(C+1);
	for(int i=1;i<=n;i++){
		int a,b,c;
		cin>>a>>b>>c;
		p[a]=max(p[a],1ll*c*b);
	}


	for(int i=1;i<=C;i++)
		for(int j=i*2;j<=C;j+=i)
			p[j]=max(p[j],p[i]*(j/i));


	for(int i=1;i<=C;i++)
		p[i]=max(p[i],p[i-1]);
	int m;
	cin>>m;
	for(int i=1;i<=m;i++)
	{
		int64 d,h;
		cin>>d>>h;
		int fl=upper_bound(p.begin(),p.end(),d*h)-p.begin();
		if(fl>C)cout<<-1<<" ";
		else cout<<fl<<" ";
	}
}