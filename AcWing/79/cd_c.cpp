#include <bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(0);cout.tie(0);
#define int long long
typedef long long ll;
typedef pair<int,int> P;
const int N=1e6+7;
const int INF=0x3f3f3f3f3f3f3f3f;
const int mod=998244353;
vector<int>pri;
int vi[N];
void init()
{
	for(int i=2;i<1e5;i++){
		if(vi[i])continue;
		pri.push_back(i);
		for(int j=2;j*i<1e5;j++){
			vi[i*j]=1;
		}
	}
}
set<int>se;
void solve()
{
	int n;
	cin>>n;
	se.clear();
	int fl=0;
	while(n--){
		int x;
		// cin>>x;
		scanf("%lld",&x);
		for(int i=0;i<pri.size();i++){
			if(pri[i]*pri[i]>x)break;
			if(x%pri[i]==0){
				if(se.count(pri[i]))fl=1;
				else se.insert(pri[i]);
			}
			while(x%pri[i]==0)
				x/=pri[i];
		}
		if(se.count(x))fl=1;
		else se.insert(x);
	}
	cout<<(fl?"YES":"NO")<<endl;
}
signed main()
{
	freopen("C:\\Users\\tob\\Desktop\\a.txt","r",stdin);
	clock_t start, finish;
	start = clock();
	IOS
	init();
	int __=1;
	// cin >> __;
	while (__--)
		solve();
	finish = clock();
	cout << "the time cost is" << double(finish - start) / CLOCKS_PER_SEC;
	fclose(stdin);
}