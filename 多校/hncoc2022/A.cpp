#include<bits/stdc++.h>
using namespace std;
int a[109];
int b[101];
int c[100];
int d[100];

void solve()
{
	memset(a,0,sizeof(a));
////	memset(b,0,sizeof(b));
	memset(c,0,sizeof(c));
	memset(d,0,sizeof(d));
	for(int i=1;i<=15;i++)
	{
		char x,y;
		int A,B,C,D;
		cin>>x>>y>>A>>B>>C>>D;
		if(A>B)a[x-'A']+=3;
		else if(A<B)a[y-'A']+=3;
		else a[x-'A']+=1,a[y-'A']+=1;
		
		if(C>D)a[x-'A']+=3;
		else if(C<D)a[y-'A']+=3;
		else a[x-'A']+=1,a[y-'A']+=1;
		
		c[x-'A']+=A+C;
		c[y-'A']+=B+D;
		
		d[x - 'A'] += B + D;
		d[y - 'A'] += A + C;
	}
	
	for(int i = 0; i <= 5; i ++){
		cout << a[i] << " " << c[i] - d[i] << " " << c[i] << "\n";
	}
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int __;cin>>__;
	while(__--)
		solve(); 
}
