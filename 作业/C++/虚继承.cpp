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


class A{
public:
	int num;
	virtual void f(){
		cout<<"A\n";
	}
};
class B1:public A{
public:
	void f() override{
		cout<<"B1\n";
	}
};
class B2:public A{
public:
	void f() override {
		cout<<"B2\n";
	}
};
class C:public B1, public B2{
public:
	void f() override {
		cout<<"C\n";
	}
};
void solve()
{
	shared_ptr<C> x = make_shared<C>();
	x->B1::num=1;
	x->B2::num=2;
	cout<<x->B1::num<<" "<<x->B2::num<<endl;
	x->B1::f();
}
signed main(){
 // freopen("data.in","r",stdin);
 // freopen("data.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
		solve();
	return 0;
}