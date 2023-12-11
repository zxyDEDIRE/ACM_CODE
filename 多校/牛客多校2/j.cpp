#include <bits/stdc++.h>
using namespace std;
#define int long long

typedef long long ll;
typedef pair<int,int> P;
double n,s[100005];
double a,b;
double ans=1e9+7,an;
void solve()
{
	cin>>n;
    for(int i=1;i<=n;i++)cin>>s[i];
    double k=0;
	double px=0,py=0;
	for(int i=1;i<=n;i++){
		px+=i;
		py+=s[i];
	}
	px/=n;
	py/=n;
	//cout<<px<<" "<<py<<endl;
	double sua=0,sub=0;
	for(int i=1;i<=n;i++){
		sua+=(i-px)*(s[i]-py);
		sub+=(i-px)*(i-px);
	}
	b=sua/sub;
	a=py-px*b;
	double ans=0;
	for(int i=1;i<=n;i++){
		a+=b;
		ans+=(s[i]-a)*(s[i]-a);
	}
	printf("%.8llf\n",ans);
}
signed main()
{
	int __=1;
	cin >> __;
	while (__--)
		solve();
}