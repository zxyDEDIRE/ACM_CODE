/*
	嵌套变量重复
	特殊样例 0 1 2 n
	数组越界
	开long long
*/
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define pp(x) array<int,x>
using ull=unsigned long long;
using ll=long long;
using pii=pair<int,int>;
const int dx[]={0,0,1,-1,1,-1,1,-1};
const int dy[]={1,-1,0,0,1,-1,-1,1};
const int mod=998244353;
const int inf=0x3f3f3f3f;
const int INF=1e9+7;
const int maxn=1e6+100;
struct node{
	int x,y;
	bool operator<(const node&a)const{
		return a.x>x;
	}
};
void solve()
{
	int n;
	vector<int>p;
	vector<pii>ans;
	cin>>n;
	p.resize(n);
	for(auto &i:p)
		cin>>i;
	int mi=*min_element(p.begin(),p.end());
	int ma=*max_element(p.begin(),p.end());
	int fl=min_element(p.begin(),p.end())-p.begin();
	if(mi==ma||n==1){cout<<0<<endl;return ;}
	else if(mi==1){cout<<-1<<endl;return ;}
	priority_queue<node>q;
	for(int i=0;i<n;i++)
		q.push({p[i],i});
	while(1)
	{
		auto [x,id_x]=q.top();q.pop();
		if(x==mi)break;
		ans.push_back({id_x,fl});
		p[id_x]=ceil(1.0*p[id_x]/mi);
		if(p[id_x]<mi){
			mi=p[id_x];
			fl=id_x;
		}
		q.push({p[id_x],id_x});
	}
	cout<<ans.size()<<endl;
	for(auto [x,y]:ans)
		cout<<x+1<<" "<<y+1<<endl;
	// for(auto i:p)
	// 	cout<<i<<" ";cout<<endl;

}
signed main(){
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.in.txt","r",stdin);
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.out.txt","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	int __;cin>>__;
	while(__--)
		solve();
//  fclose(stdin);
//  fclose(stdout);
	return 0;
}