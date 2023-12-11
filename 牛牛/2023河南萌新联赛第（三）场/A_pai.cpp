/*
	嵌套变量重复 特殊样例 0 1 2 n 数组越界 开long long
	清空 建图别用vector
*/
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define pp(x) array<int,x>
using ull=unsigned long long;
using ll=long long;
using pii=pair<int,int>;
using pdd=pair<double,double>;
const int dx[]={0,0,1,-1,1,-1,1,-1};
const int dy[]={1,-1,0,0,1,-1,-1,1};
const int mod=998244353;
const int inf=0x3f3f3f3f;
const int INF=1e9+7;
const int maxn=1e6+100;
void solve()
{
	int n=6;
	int q=5;
	cout<<n<<" "<<q<<endl;
	srand(time(0));
	for(int i=1;i<=q;i++)
	{
		int op,l,r,w;
		op=rand()%2;
		if(op==0)
		{
			l=rand()%n+1;
			while(l>n)l=rand()%n+1;//,cout<<"A";
			r=rand()%n+l;  
			while(r>n||r<l)r=rand()%n+1;//,cout<<"B";
			w=rand();
			cout<<0<<" "<<l<<" "<<r<<" "<<w<<endl;
		}
		else
		{
			l=rand()%n+1;
			while(l>n)l=rand()%n+1;//,cout<<"A";
			r=rand()%n+l;
			while(r>n||r<l)r=rand()%n+1;//,cout<<"B";
			cout<<1<<" "<<l<<" "<<r<<endl;
		}
	}
}
signed main(){
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.in.txt","r",stdin);
 freopen("C:\\Users\\tob\\Desktop\\in.txt","w",stdout);
	// ios::sync_with_stdio(false);
	// cin.tie(nullptr);cout.tie(nullptr);
	// int __;cin>>__;
	// while(__--)
		solve();
//  fclose(stdin);
//  fclose(stdout);
	return 0;
}
/*
#!/bin/bash
./c.out
./a.out
echo "  "
./b.out   
*/