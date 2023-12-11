/*
	嵌套变量重复
	特殊样例 0 1 2 n
	数组越界
	开long long
*/
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
const int N=1111;
bool dp[N][N];
int n,c,a,b;
int solve(int n,int c,int a)
{
	// cin>>n>>c>>a;
	memset(dp,0,sizeof(dp));
	b=n-c-a;
	if(a>b)swap(a,b);
	dp[a][b]=1;


	int mi=a+b;
	for(int i=max(a,b);i>=1;i--)
	{
		if(i==c)continue;
		for(int x=0;x<=a;x++)
		{
			for(int y=0;y<=b;y++)
			{
				if(!dp[x][y])continue;
				if(x>=i)dp[x-i][y]|=dp[x][y],mi=min(mi,x+y-i);//,aa[x-i]=1;
				if(y>=i)dp[x][y-i]|=dp[x][y],mi=min(mi,x+y-i);//,bb[y-i]=1;
			}
		}
	}
	cout<<n<<" "<<c<<" "<<a<<endl;
	cout<<mi<<endl;
	return mi;
}
signed main(){
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.in.txt","r",stdin);
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.out.txt","w",stdout);
	// ios::sync_with_stdio(false);
	// cin.tie(nullptr);cout.tie(nullptr);
	// int __;cin>>__;
	// while(__--)
	clock_t start, finish;
	start = clock();
	int n=30;
	for(int i=1;i<=n;i++){
		for(int j=0;j<=n-i;j++){
			if(i==1&&j==1)continue;
			if(i==2&&j==2)continue;
			if(i==1&&j==28)continue;
			if(i==2&&j==26)continue;
			int x=solve(n,i,j);
			if(x!=0){
				cout<<i<<" "<<j<<endl;
				return 0;
			}
		}
		cout<<i<<endl;
	}
		finish = clock();
	cout << "the time cost is" <<\
	double(finish - start) / CLOCKS_PER_SEC;
//  fclose(stdin);
//  fclose(stdout);
	return 0;
}
/*
001100
00000
11111
00

000
111
000

0000
1111
0000

3 2 1
*/