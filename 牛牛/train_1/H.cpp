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
const int dx[]={0,0,1,-1,1,-1,1,-1};
const int dy[]={1,-1,0,0,1,-1,-1,1};
const int mod=998244353;
const int inf=0x3f3f3f3f;
const int INF=1e9+7;
const int maxn=1e6+100;
struct node{
	int id;char ch,x;
};
vector<node>a,b;
int f(char a,int op)
{
	if(a>='2'&&a<='9')return a-'0';
	if(a=='T')return 10;
	if(a=='J')return 11;
	if(a=='Q')return 12;
	if(a=='K')return 13;
	if(a=='A'){
		if(op==1)return 14;
		if(op==0)return 1;
	}
	return 0;
}
bool c10(vector<node>&a)
{
	sort(a.begin(),a.end(),[&](node a,node b){
		return f(a.x,1)<f(b.x,1);
	});
	for(int i=1;i<5;i++)
		if(a[i].ch!=a[0].ch)return 0;
	cout<<"OK"<<endl;
	int now=10;
	for(int i=0;i<5;i++){
		if(f(a[i].x,1)!=now)return 0;
		now++;
	}
	return 1;
}
bool c9(vector<node>&a)
{
	sort(a.begin(),a.end(),[&](node a,node b){
		return f(a.x,0)<f(b.x,0);
	});
	for(int i=1;i<5;i++)
		if(a[i].ch!=a[0].ch)return 0;
	for(int i=1;i<5;i++)
		if(f(a[i].x,0)-f(a[i-1].x,0)!=1)return 0;
	return 1;
}
//有四张点数相同的牌
bool c8(vector<node>&a)
{
	sort(a.begin(),a.end(),[&](node a,node b){
		if(f(a.x,0)==f(b.x,0))return a.id>b.id;
		return f(a.x,0)<f(b.x,0);
	});
	map<int,int>mp;
	for(auto [id,ch,x]:a)
		mp[f(x,0)]++;
	int flag=-1;
	for(auto [x,y]:mp)
		if(y==4)
			flag=x;
	if(flag==-1)return 0;
	vector<node>b;
	for(int i=0;i<5;i++)
		if(f(a[i].x,0)==flag)
			b.push_back(a[i]);
	for(int i=0;i<5;i++)
		if(f(a[i].x,0)!=flag)
			b.push_back(a[i]);
	a=b;
	return 1;
}
bool c7(vector<node>&a)
{
	sort(a.begin(),a.end(),[&](node a,node b){
		if(f(a.x,0)==f(b.x,0))return a.id>b.id;
		return f(a.x,0)<f(b.x,0);
	});
	map<char,int>mp;
	for(auto [id,ch,x]:a)
		mp[x]++;
	char fa='0',fb='0';
	for(auto [x,y]:mp)
	{
		if(y==3)fa=x;
		if(y==2)fb=x;
	}
	if(fa=='0'||fb=='0')return 0;
	vector<node>b;
	for(int i=0;i<a.size();i++)
		if(a[i].x==fa)
			b.push_back(a[i]);
	for(int i=0;i<a.size();i++)
		if(a[i].x==fb)
			b.push_back(a[i]);
	a=b;
	return 1;
}
bool c6(vector<node>&a)
{
	sort(a.begin(),a.end(),[&](node a,node b){
		if(f(a.x,1)==f(b.x,1))return a.id>b.id;
		return f(a.x,1)>f(b.x,1);
	});
	for(int i=1;i<5;i++)
		if(a[i].ch!=a[0].ch)
			return 0;
	return 1;
}
bool c5(vector<node>&a)
{
	sort(a.begin(),a.end(),[&](node a,node b){
		if(f(a.x,1)==f(b.x,1))return a.id>b.id;
		return f(a.x,1)>f(b.x,1);
	});
	if(a[0].x=='2'&&a[1].x=='3'&&a[2].x=='4'&&a[3].x=='5'&&a[4].x=='A')
	{

	}
	for(int i=1;i<5;i++)
		if(f(a[i].x,))
}

void solve()
{
	for(int i=1;i<=5;i++){
		string str;cin>>str;
		a.push_back({i,str[0],str[1]});
	}
	for(int i=1;i<=5;i++){
		string str;cin>>str;
		b.push_back({i,str[0],str[1]});
	}

	// cout<<c10(a)<<endl;
	// cout<<c9(a)<<endl;
	// cout<<c8(a)<<endl;
	// cout<<c7(a)<<endl;
	cout<<c6(a)<<endl;
}
signed main(){
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.in.txt","r",stdin);
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.out.txt","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	// int __;cin>>__;
	// while(__--)
		solve();
//  fclose(stdin);
//  fclose(stdout);
	return 0;
}
/*
HT HJ HQ HK H9
HT HJ HQ HK H9


H9 H9 H9 HT HT
H9 H9 H9 HT HT
3,294.8
*/
/*
1. Dirb可以通过枚举目录或文件，来发现Web应用程序中隐蔽的目录或文件，从而帮助测试人员识别潜在的攻击面。
2. Shell反弹指的是攻击者可通过已攻入的服务器或内网，尝试利用已知或未知漏洞，将反弹Shell上传至Web服务器，从而获取服务器的控制权。
3. Sqlmap是一款自动化的SQL注入工具，可以帮助测试人员发现目标Web应用程序的SQL注入漏洞，并提供多种不同的攻击选项，以获取进一步信息或控制目标服务器。
4. Os-shell是指攻击者可通过已攻入的服务器运行操作系统原生的命令，从而获取服务器的控制权。

通过学习Dirb、反弹Shell、Sqlmap和Os-shell等相关技术，可以帮助我们更深入地了解Web应用程序的安全性，并提高测试人员对攻击者进行行动的识别和防御能力。

Sqlmap官方文档：https://github.com/sqlmapproject/sqlmap/wiki/Usage
《深入研究注入工具SqlMap内部结构和原理及其运行机制》：https://www.freebuf.com/sectool/321598.html
《sqlmap源码分析和学习》：https://blog.csdn.net/q20010619/article/details/122243790
《Sqlmap 内核分析 I: 基础流程》：https://zhuanlan.zhihu.com/p/43242220
Many websites online now have web application user input parameters that are not properly filtered, leading to SQL injection. Attackers can exploit this vulnerability to gain system privileges without logging in, or directly steal database content.
sc config MouseWithoutBordersSvc start=demand
sc config SLBSafe start=demand
sc config LenovoPcManagerService start=demand
sc config LenovoWindowsSecurityCenter start=demand
sc config LenovoServiceAS start=demand

*/