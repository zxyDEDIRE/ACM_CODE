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
	multiset<int,greater<int>>sa;
	multiset<int>sb;
	int lena=0,lenb=0;
	void insert(int x){
		sa.insert(x);
		lena++;
		bal();
	}
	void bal(){
		while(sa.size()&&sb.size()&&*sa.begin()>*sb.begin()){
			sb.insert(*sa.begin());
			sa.erase(sa.begin());
			lena--;
			lenb++;
		}
	}
	void out(int x){
		while(lena<x){
			sa.insert(*sb.begin());
			sb.erase(sb.begin());
			lena++;
			lenb--;
		}
		cout<<*sa.begin()<<" ";
	}
}sa,sb;
int n;
void solve()
{
	cin>>n;
	int len=0,lena=0,lenb=0;
	while(n--)
	{
		int x;
		cin>>x;
		len++;
		int mid_1=ceil(1.0*len/3);
		int mid_2=ceil(2.0*len/3);
		sa.insert(x);
		sb.insert(x);
		sa.out(mid_1);
		sb.out(mid_2);
		// cout<<" "<<mid_1<<" "<<mid_2<<endl;
		cout<<endl;
	}
}
signed main(){
 // freopen("data.in","r",stdin);
 // freopen("data.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
		solve();
	return 0;
}
/*
10
1
2
3
1
5
6
7
8
9
10
*/