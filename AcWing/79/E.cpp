/*
	嵌套变量重复
	特殊样例 0 1 2 n
	数组越界
	开long long
*/
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
using ull=unsigned long long;
using ll=long long;
using pii=pair<int,int>;
const int dx[]={0,0,1,-1,1,-1,1,-1};
const int dy[]={1,-1,0,0,1,-1,-1,1};
const int mod=998244353;
const int inf=0x3f3f3f3f;
const int INF=1e9+7;
const int maxn=1e6+100;
void solve()
{
	int n=1e5;

	clock_t start, finish;
	start = clock();

	for(int i=1;i<=n;i++){
		int x;
		scanf("%d",&x);
		for(int j=2;j*j<=x;j++){
			
			while(x%j==0)
				x/=j;
		}
	}



	finish = clock();
	cout << "the time cost is" << double(finish - start) / CLOCKS_PER_SEC;
}
signed main(){
	freopen("C:\\Users\\tob\\Desktop\\a.txt","r",stdin);
	// freopen("C:\\Users\\tob\\Desktop\\b.txt","w",stdout);
	// ios::sync_with_stdio(false);
	// cin.tie(nullptr);cout.tie(nullptr);
	// int __;cin>>__;
	// while(__--)
	solve();
	fclose(stdin);
	// fclose(stdout);
	return 0;
}