#include<bits/stdc++.h>
using namespace std;

int c[5];

void solve()
{
	srand(time(0));
	long long s=0;
	for(int i=0;i<4;i++)
	{
		cin>>c[i];s+=c[i];
	}
	if(s<=1||s==c[0]+c[3])
	{
		cout<<"Horse";return;
	}
	if(!c[0])
	{
		if(c[1]==0) cout<<"Horse";
		else{
			if(c[2]==0){
				if(c[1]%3==2)cout<<"Rabbit";
				else cout<<"Horse";
			}
			else{
				if(c[1]%3==0) cout<<"Horse";
				else cout<<"Rabbit";
			}
		}
	}
	else {
		int t=rand()%2;
		if(t) cout<<"Rabbit";
		else cout<<"Horse";
	}
}

int main()
{
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int t=1;
	cin>>t;
	for(int i=1;i<=t;i++)
	{
		cout<<"Case #"<<i<<": ";
		solve();
		if(i!=t) cout<<'\n';
	}
	return 0;
}