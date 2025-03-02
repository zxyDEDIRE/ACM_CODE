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
int n,q;
void solve()
{
	cin>>q;
	multiset<int>sb;
	multiset<int,greater<int>>sa;
	int lena=0,lenb=0,len=0,mid=0;
	while(q--)
	{
		int op,x;
		cin>>op>>x;
		if(op==1)
		{
			len++;
			sa.insert(x);
			lena++;
		}
		else
		{
			len--;
			if(sa.find(x)!=sa.end()){
				lena--;
				sa.erase(sa.find(x));
			}
			else{
				lenb--;
				sb.erase(sb.find(x));
			}
		}
		mid=(len+1)>>1;
		while(sa.size()&&sb.size()&&*sa.begin()>*sb.begin()){
			lena--;
			lenb++;
			sb.insert(*sa.begin());
			sa.erase(sa.begin());
		}
		while(lena<mid)
		{
			sa.insert(*sb.begin());
			sb.erase(sb.begin());
			lena++;
			lenb--;
		}
		while(lenb>mid)
		{
			sb.insert(*sa.begin());
			sa.erase(sa.begin());
			lena--;
			lenb++;
		}
		cout<<*sa.begin()<<" "<<lena<<" "<<lenb<<endl;
	}

}
signed main(){
 // freopen("data.in","r",stdin);
 // freopen("data.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	// int __;cin>>__;
	// while(__--)
		solve();
	return 0;
}
/*
10 
1
2
3
4
5
6
7
8
9
10
*/