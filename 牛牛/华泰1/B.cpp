#include<bits/stdc++.h>
using namespace std;
const int maxn=4e6;
bool p[maxn];
int n;
int solve(int n)
{
	// cin>>n;
	p[6]=0;
	p[16]=1;
	p[26]=0;
	p[36]=1;
 
	for(int i=46;i<=n;i+=10)
	{
		int x=i-10;
		if(i%12==0)
		{
			int y=i/6;
			if(p[x]==1&&p[y]==1)p[i]=0;
			else p[i]=1;
		}
		else
		{
			if(p[x]==1)p[i]=0;
			else p[i]=1;
		}
	}
	int cnt=0;
	int m=n;
	while(m!=6){
		m-=10;
		cnt++;
	}
	int f1=1,f2=0;

	if(p[n]==0)f1=0;
	if(cnt&1)f2=1;

	if(f1==f2)return 1;
	else return 0;
}
int main()
{
	for(int i=16;;i+=10)
	{
		cout<<i<<endl;
		if(solve(i)==0){
			cout<<i<<endl;
			break;
		}
	}


	return 0;
}