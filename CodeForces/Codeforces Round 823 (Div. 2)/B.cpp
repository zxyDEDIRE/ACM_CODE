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
struct node{
	ll x,y;
}p[maxn];
int n;
struct SaDown{
	//退火系数
	#define down 0.996
	double ansx,answ;
	//评估函数
	double energy(double x){
		double ans=0;
		for(int i=1;i<=n;i++){
			// cout<<fabs(x-1.0*p[i].x)+p[i].y<<" "<<fabs(x-1.0*p[i].x)<<" "<<p[i].y<<endl;
			ans=max(ans,fabs(x-1.0*p[i].x)+p[i].y);
		}
		return ans;
	}
	void sa()
	{
		double t=3000;
		while(t>1e-15)
		{
			double ex=ansx+(rand()*2-RAND_MAX)*t;
			double ew=energy(ex);
			double de=ew-answ; 
			if(answ>ew)
			{
				ansx=ex;
				answ=ew;
			}
			else if(exp(-de/t)*RAND_MAX>rand())
			{
				ansx=ex;
			}
			t*=down;
		}
	}
	void doit(){
		//退火次数
		for(int i=1;i<=10;i++)
			sa();
	}
}sa;
void solve()
{
	cin>>n;
	// srand(time(0));
	for(int i=1;i<=n;i++){
		scanf("%lld",&p[i].x);
		sa.ansx+=p[i].x;
	}
	for(int i=1;i<=n;i++)
		scanf("%lld",&p[i].y);
	sa.ansx/=n;
	sa.answ=sa.energy(sa.ansx);
	sa.doit();
	// cout<<sa.energy(1)<<endl;
	// cout<<sa.energy(sa.ansx)<<" "<<sa.energy(2.01043)<<" "<<sa.ansx<<endl;
	cout<<sa.ansx<<endl;
	// printf("%.6lf\n",sa.ansx);
}
signed main(){
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.in.txt","r",stdin);
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.out.txt","w",stdout);
	// ios::sync_with_stdio(false);
	// cin.tie(nullptr);cout.tie(nullptr);
	int __;cin>>__;
	while(__--)
		solve();
//  fclose(stdin);
//  fclose(stdout);
	return 0;
}
/*
3
1 2 3
4 1 2

1+4
0+1
1+2

需求分析：

根据项目的问题描述，可以得到以下的需求：

检测功能：智能居家控制系统需要具备室内温度、湿度、光照强度、海拔、气压、可燃气体浓度的检测功能，可以通过传感器实现。

控制功能：智能居家控制系统需要具备电器的开关控制功能，包括窗帘、空调、电灯、电视等家电，可以通过继电器等器件实现。

数据上传功能：智能居家控制系统需要定期将测得的参数值和电器的开关状态和开关时间等信息上传到云平台保存，以实现远程监控和数据分析。

控制界面：智能居家控制系统需要提供一个控制界面，可以通过该界面实现电器的遥控控制、参数查询和历史数据查看等功能，最好使用拥有图形界面软件开发经验人员进行开发。

安全性：智能居家控制系统需要具有良好的安全性，包括防止恶意攻击、保障用户隐私等，可以采用加密技术、访问控制和防火墙等措施来实现。

系统稳定性：智能居家控制系统需要具有良好的稳定性，可以通过软件设计和硬件选型等方式来实现。

兼容性：智能居家控制系统需要能够兼容多种家电设备，并能够支持多种平台和接口协议。

综上所述，智能居家控制系统需要具备检测和控制功能、数据上传功能、控制界面、安全性、系统稳定性和兼容性等要求。在开发过程中，需要考虑多种因素，包括软件设计、硬件选型、安全措施等。

word count: 478, token estimate: 1223
*/