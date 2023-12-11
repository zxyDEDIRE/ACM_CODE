#include<bits/stdc++.h>
using namespace std;
int main()
{
	int a,b,c,d;
	int t=0;
	while(1)
	{
	//	if(t!=0)cout<<"\n";
	//	t++;
		cin>>a>>b>>c>>d;
		if(a==b&&b==c&&c==d&&d==0)break;
		string x,y;
		x+=(char)(a+'0');
		x+=(char)(b+'0');
		x+=(char)(c+'0');
		x+=(char)(d+'0');
		sort(x.begin(),x.end());
		y=x;
		do{
			if(y[0]=='0'){
				y=x;
				continue;
			}
			if(x!=y)
			cout<<y<<" ";
			if(y[0]!=x[0])cout<<"\n";
			y=x;
		}
		while(next_permutation(x.begin(),x.end()));
		cout<<y<<endl;
		cout<<endl;
	}
}