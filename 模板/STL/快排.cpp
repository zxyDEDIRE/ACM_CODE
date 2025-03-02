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
// 注：四个数组的下标均从 0 开始。
int a[maxn];
int n;
int randint(int l, int r){ // 生成在 [l, r] 之间的随机数
	return rand() % (r - l + 1) + l;
}
void qsort(int l, int r){ // l 为左端点，r 为右端点
	if(l >= r){ // 如果长度为 0 就返回
		return;
	}
	int num = randint(l, r);
	vector<int>b,c,d;
	for(int i = l;i <= r;i++){
		if(a[i] < a[num])b.push_back(a[i]);
		else if(a[i] == a[num])c.push_back(a[i]);
		else d.push_back(a[i]);
	}
	int ind1 = int(b.size()),ind2=int(c.size()),ind3=int(d.size());
	for(int i=0;i<ind1;i++)a[i+l] = b[i];
		
	for(int i=0;i<ind2;i++)a[i+ind1+l] = c[i];
		
	for(int i=0;i<ind3;i++)a[i+ind1+ind2+l] = d[i];
		
	qsort(l, l+ind1-1);
	qsort(l+ind1+ind2, r);
}
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	qsort(1,n);
	for(int i=1;i<=n;i++)
		cout<<a[i]<<" ";
}
signed main(){
 // freopen("data.in","r",stdin);
 // freopen("data.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
		solve();
	return 0;
}