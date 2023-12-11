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
	int n;
	cin>>n;n--;
	int j=2;
	int fl=2;
	while(n>=1)
	{
		n-=j;
		if(n<=0)
		{
			fl=1;
			break;
		}
		n-=j;
		if(n<=0)
		{
			fl=2;
			break;
		}
		j++;
	}
	if(fl==2)cout<<"Jane"<<endl;
	else cout<<"John"<<endl;
	
}
signed main(){
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.in.txt","r",stdin);
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.out.txt","w",stdout);
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
C\Users\tob\Desktop\test\QT\gcc-linaro-5.5.0-2017.10-x86_64_arm-linux-gnueabi.tar.xz
/mnt/c/Users/tob/Desktop/test/Qt/gcc-linaro-5.5.0-2017.10-x86_64_arm-linux-gnueabi.tar.xz
/mnt/c/Users/tob/Desktop/test/Qt/myln2.sh
*/