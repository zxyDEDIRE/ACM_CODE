/*
	嵌套变量重复
	特殊样例 0 1 2 n
	数组越界
	开long long
*/
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long
using ull=unsigned long long;
using ll=long long;
using pii=pair<int,int>;
const int dx[]={0,0,1,-1,1,-1,1,-1};
const int dy[]={1,-1,0,0,1,-1,-1,1};
const int mod=998244353;
const int inf=0x3f3f3f3f;
const int INF=1e9+7;
const int maxn=1e6+100;
struct node{
	int x,y;
	bool operator<(const node&a)const{
		return a.x<x;
	}
};
int p[maxn];
int n;
void solve()
{
	cin>>n;
	int a=0,b=0;
	for(int i=1;i<=n;i++)
	{
		cin>>p[i];
		if(p[i]&1)a++;
		else b++;
	}
	if(a>1&&b>1){
		cout<<"No"<<endl;
		return ;
	}
	if(a==1)
	{
		for(int i=1;i<=n;i++)
			p[i]++;
	}
	set<pii>s;
	vector<pii>v;
	
}
signed main(){
 // freopen("C:\\Users\\tob\\Desktop\\P4391_9.in.txt","r",stdin);
 // freopen("C:\\Users\\tob\\Desktop\\P4391_9.out.txt","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	int __;cin>>__;
	while(__--)
		solve();
//  fclose(stdin);
//  fclose(stdout);
	return 0;
}
/*

+6
7 9 11 13 15 8
+8
9 11 13 15 17 10
+14
15 17 19 21 23 16

1 3 5 7 9 2
2 4 6 8 1 3 5 7

1 3 5 7 9 11 13 15 17
4 10 16 22 28 
6 12 18 20 26 
8 18 28 38
2 8 14 

6+6x
4+6x
2+6x
=2+2x

2+16x
10+16x
->2+8x




1 3 5 7 2
2 4 6
1 3 5


2 8
4 8
6 8
8 8

8

2 



*/