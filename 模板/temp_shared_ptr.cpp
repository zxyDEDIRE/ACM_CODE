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


template<class T>
class mySharedPtr
{
private:
	T* _ptr;
	int* _pcount;
	mutex* _pmtx;
public:
	// 构造函数
	mySharedPtr(T* ptr):_ptr(ptr),_pcount(new int(1)),_pmtx(new mutex){}
	//拷贝构造
	mySharedPtr(const mySharedPtr<T>& sp):_ptr(sp._ptr),_pcount(sp.count),_pmtx(sp._pmtx){
		addCount();
	}

	//解除绑定
	void release(){
		_pmtx->lock();

		bool deleteflag = false;

		if(--(*_pcount)==0){
			cout<<"delete:"<<*_ptr<<endl;
			delete _ptr;
			delete _pcount;
			deleteflag=true;
		}

		_pmtx->unlock();
		if(deleteflag==true){
			delete _pmtx;
		}
	}
	//增加计数
	void addCount(){
		_pmtx->lock();
		++(*_pcount);
		_pmtx->unlock();
	}
	//显示计数
	void showCount(){
		cout<<(*_ptr)<<" "<<(*_pcount)<<endl;
	}


	//运算符重载
	mySharedPtr& operator=(const mySharedPtr<T>& sp);
	T& operator*();
	T* operator->();

	//析构函数
	~mySharedPtr(){
		release();
	}
};



void solve()
{
}
signed main(){
 // freopen("data.in","r",stdin);
 // freopen("data.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
		solve();
	return 0;
}