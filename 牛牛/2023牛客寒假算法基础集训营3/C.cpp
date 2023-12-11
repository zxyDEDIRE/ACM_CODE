/*
	嵌套变量重复
	特殊样例 0 1 2 n
	数组越界
	开long long
*/
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define pp(x) array<int,x>
using ull=unsigned long long;
using ll=long long;
using pii=pair<int,int>;
const int dx[]={0,0,1,-1,1,-1,1,-1};
const int dy[]={1,-1,0,0,1,-1,-1,1};
const int mod=998244353;
const int inf=0x3f3f3f3f;
const int INF=1e9+7;
const int maxn=1e6+100;
int p[maxn];
int n;
void solve()
{
	int n;
	scanf("%d",&n);
	if(n<=3||n==7){printf("-1");return ;}
	//a为四个一组的组数 b为五个一组的组数 c为六个一组的组数
	int a=0,b=0,c=0,t=1;
	if(n%4==0)a=n/4;
	else if(n%4==1)a=(n/4)-1,b=1;
	else if(n%4==2)a=(n/4)-1,c=1;
	else if(n%4==3)a=(n/4)-2,b=1,c=1;
	while(a||b||c)
	{
		if(a){
			printf("%d %d %d %d ",t+2,t+3,t,t+1);
			t+=4;a--;
		}
		else if(b){
			printf("%d %d %d %d %d ",t+2,t+3,t+4,t,t+1);
			t+=5;b--;
		}
		else if(c){
			printf("%d %d %d %d %d %d ",t+3,t+4,t+5,t,t+1,t+2);
			t+=6;c--;
		}
	}
}
signed main(){
 // freopen("C:\\Users\\tob\\Desktop\\P4391_9.in.txt","r",stdin);
 // freopen("C:\\Users\\tob\\Desktop\\P4391_9.out.txt","w",stdout);
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
4
5
6

%4 -0 44444
%4 -1 44445
%4 -2 44446
%4 -3 44456

1 2 3 4 5 6 7 8 9
3 4 1 2 7 8 9 5 6

1 2 3 4 5 6 7  8  9 10 11
3 4 5 1 2 9 10 11 6 7  8\


1 2 3 4   5 6 7 8 9
3 4 1 2   7 8 9 5 6


1 2 3 4    5 6 7  8 9 10
3 4 1 2    8 9 10 5 6 7
*/