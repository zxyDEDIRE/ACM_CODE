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
#define nullptr 0
const int dx[]={0,0,1,-1,1,-1,1,-1};
const int dy[]={1,-1,0,0,1,-1,-1,1};
const int mod=998244353;
const int inf=0x3f3f3f3f;
const int INF=1e9+7;
const int maxn=300;
int n;
bool f(int x)
{
	int cnt=0;
	while(x)
		x/=10,cnt++;
	return cnt>=18;
}
void solve()
{
	cin>>n;
	double ans=1;
	for(int i=1;i<=n;i++)
	{
		ans*=2;
		if(f(ans))
			ans/=1000;
	}
	int temp=ans;
   	int  sum=0;
    while(temp)//计算总共多少位
    {
        temp/=10;
        sum++;
    }
    while(sum>10)//留下前十位
    {
        ans/=10;
        sum--;
    }
    int tmp=ans;
    cout<<tmp<<endl;
}
signed main(){
 // freopen("C:\\Users\\tob\\Desktop\\P4391_9.in.txt","r",stdin);
 // freopen("C:\\Users\\tob\\Desktop\\P4391_9.out.txt","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	// int __;cin>>__;
	// while(__--)
		solve();
//  fclose(stdin);
//  fclose(stdout);
	return 0;
}