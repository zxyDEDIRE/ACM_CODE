/*
	嵌套变量重复
	特殊样例 0 1 2 n
	数组越界
	开long long
*/
#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
const int inf=0x3f3f3f3f;
const int INF=1e9+7;
const int maxn=1e6;
int l,r,h,b;
int n;
int get(int x,int y,int a,int b)
{
	cout<<"? "<<x<<" "<<y<<" "<<a<<" "<<b<<endl;
	int res;
	cin>>res;
	return res;
}
void f()
{
	while(l!=r)
	{
		int mid=(l+r)>>1;
		int res=get(l,mid,1,n);
		if(res==mid-l+1)l=mid+1;
		else r=mid;
	}
}
void F()
{
	while(b!=h)
	{
		int mid=(b+h)>>1;
		int res=get(1,n,b,mid);
		if(res==mid-b+1)b=mid+1;
		else h=mid;
	}
}
void solve()
{
	cin>>n;
	l=1,r=n;
	b=1,h=n;
	f();
	F();
	cout<<"! "<<l<<" "<<h<<endl;
}
signed main(){
 // freopen("C:\\Users\\tob\\Desktop\\P4391_9.in.txt","r",stdin);
 // freopen("C:\\Users\\tob\\Desktop\\P4391_9.out.txt","w",stdout);
	// ios::sync_with_stdio(false);
	// cin.tie(nullptr);cout.tie(nullptr);
		solve();
//  fclose(stdin);
//  fclose(stdout);
	return 0;
}
/*
0 0 1
1 0 0 
0 0 0
*/