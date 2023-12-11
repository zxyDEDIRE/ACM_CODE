
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
map<array<int,3>,array<int,3>>mp;
char ch[maxn];
int n;
void f(int &l,int &r,int &op)
{
	if(mp.count({l,r,op}))
	{
		auto [_l,_r,_op]=mp[{l,r,op}];
		l=_l;
		r=_r;
		op=_op;
		return ;
	}
	int _l=l;
	int _r=r;
	int _op=op;
	while(ch[l]!=ch[r]&&l<=r)
	{
		if(op==0)
		{
			if(ch[l]=='0')l++;
			else r--;
		}
		else
		{
			if(ch[l]=='1')l++;
			else r--;
		}
		op^=1;
	}
	mp[{_l,_r,_op}]={l,r,op};
}
int cnt=0;
int dfs(int l,int r,int op)
{
	if(l>r)return -1;
	else if(ch[l]==ch[r]&&(ch[l]-'0')!=op)return op^1;
	cout<<l<<" "<<r<<" "<<op<<endl;
	f(l,r,op);

	int f1=0,f2=0,f3=0;
	if(l+1<=r&&ch[l]==ch[l+1]&&ch[l]-'0'==op)
	{
		int T=dfs(l+1,r,op^1);
		if(T==op)return op;
	}
	if(r-1>=l&&ch[r-1]==ch[r]&&ch[r]-'0'==op)
	{
		int T=dfs(l,r-1,op^1);
		if(T==op)return op;
	}
	if(ch[l]-'0'==op)
		return dfs(l+1,r,op^1);
	else
		return dfs(l,r-1,op^1);
}
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>ch[i];
	// n=40;                         
	
	// for(int i=1;i<=n;i++){
		// if(rand()&1)ch[i]='1';
		// else ch[i]='0';
		// if(i&1)ch[i]='1';
		// else ch[i]='0';
	// }
	for(int i=1;i<=n;i++)
		cout<<ch[i];
	cout<<endl;
	int l=1,r=n,op=0;
	mp.clear();
	int T=dfs(l,r,op);
	// cout<<n<<endl;
	// for(int i=1;i<=n;i++)
	// 	cout<<ch[i];
	// cout<<endl;
	cout<<T<<endl;
}
signed main(){
	// int size(512<<20); // 512M
 //    __asm__ ( "movq %0, %%rsp\n"::"r"((char*)malloc(size)+size));
 // freopen("in.txt","r",stdin);
 // freopen("out.txt","w",stdout);
	// ios::sync_with_stdio(false);
	// cin.tie(nullptr);cout.tie(nullptr);
	clock_t start, finish;
	start = clock();


	srand(time(0));
	int __=1;
	// cin>>__;
	while(__--)
		solve();

	finish = clock();
	cout << "the time cost is" <<\
	double(finish - start) / CLOCKS_PER_SEC;
//  fclose(stdin);
//  fclose(stdout);
	// exit(0);
	return 0;
}
/*
9
011100010

4
0100
*/
