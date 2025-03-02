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

namespace A{
	// 动态分配内存
	void solve(){
		string *p1 = new string;
		string *p2 = new string("sdf");
		string *p3 = new string({"aaa"});
		cout<<*p1<<"\n"<<*p2<<"\n"<<*p3<<endl;

		string str="str";
		auto *p4 = new auto(str);
		cout<<*p4<<endl;

		const int *pc1 = new const int(1024);
	}
}
namespace B{
	// delete
	void solve(){
		int i, *pi1 = &i, *pi2 = nullptr;
		double *pd = new double(33), *pd2 = pd;
		// delete i; //w 不是指针
		// delete pi1;  //w 指向局部变量
		delete pd;  // ac
		delete pd2;  // w 指向内存已经被释放
		delete pi2;  // ac 释放空指针
	}
}


signed main(){
 // freopen("data.in","r",stdin);
 // freopen("data.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
		// solve();
	// A::solve();
	B::solve();
	return 0;
}