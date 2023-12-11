#include<bits/stdc++.h>
using namespace std;
#define endl "\n";
using pii=pair<int,int>;
const int maxn=1e6+100;
class DSU{
public:
	vector<int>f,num;
	DSU(){}
	void init(int n){
		f.resize(n+1);
		iota(f.begin(),f.end(),0);
	}
	int find(int r){
		return f[r]=f[r]==r?f[r]:find(f[r]);
	}
	bool same(int x,int y){
		return find(x)==find(y);
	}
	void merge(int x,int y){
		int fa=find(x);
		int fb=find(y);
		if(fa!=fb)
			f[fa]=fb;
	}
}dsu;
struct node{
	int x,y,id;
};
vector<node>p[maxn];
vector<pii>a[maxn];
int n,m,k,tot;
void NO(){cout<<"NO\n";}

void solve()
{
	cin>>n>>m>>k;
	if(n==1){cout<<"YES\n";return ;}
	if(n>=2&& m>2*k+2)return NO();
	for(int i=1;i<=k;i++){
		int x1,y1,y;
		cin>>x1>>y1>>y;
		a[y].push_back({x1,y1});
	}

	for(int i=1;i<=m;i++)
	{
		auto &li=a[i];
		sort(li.begin(),li.end());
		int l=1;
		for(int j=0;j<(int)li.size();j++)
		{
			if(li[j].first>l)
				p[i].push_back({l,li[j].first-1,++tot});
			l=li[j].second+1;
		}
		if(l<=n)p[i].push_back({l,n,++tot});
	}
	dsu.init(tot);
	for(int x=1;x<m;x++)
	{
		int lens=p[x].size();
		int lent=p[x+1].size();
		int j=0;
		for(int i=0;i<lens;i++)
		{
			auto [l,r,id]=p[x][i];
			while(j<lent)
			{
				auto [_l,_r,_id]=p[x+1][j];
				int l1=max(_l,l);
				int r1=min(_r,r);
				if(r1-l1+1>=2)return NO();
				if(l1==r1)
				{
					if(dsu.same(id,_id))return NO();
					dsu.merge(id,_id);
				}
				if(_r>r)break;
				j++;
			}
		}
	}
	int cnt=0;
	for(int i=1;i<=tot;i++)
		if(dsu.find(i)==i)
			cnt++;
	if(cnt>1)return NO();
	cout<<"YES\n";
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
		solve();
	return 0;
}
/*
5 3 2
2 5 1
1 4 3

5 3 1
2 4 2

2 4 2
2 2 1
1 1 4

3 2 2
1 1 1
1 1 2

4 2 2
1 3 1
2 4 2

4 2 2
3 4 1
1 1 2

111111
100011
101011
101001
101101
100001


6 6 8
1 6 1
1 1 2
1 1 3
3 5 3
1 1 4
5 5 4
1 4 5
1 6 6

5 5 4
2 4 2
2 4 3
2 4 4
1 3 5

7 5 7
3 6 1
1 1 2
4 6 2
1 2 3
5 6 3
1 3 4
6 6 4


7 5 7
3 6 1
1 1 2
4 4 2
1 2 3
6 6 3
1 3 4
5 6 4

1 6 2
1 1 1
1 1 6


3 3 4
1 3 1
1 1 2
3 3 2
1 3 3

2 4 2
1 2 3
1 2 4


1 6 2
1 1 4
1 1 2

1 6 2
1 1 1
1 1 2

111111111111111
110111111111111
000111111111111
110001111111111
111101111111111
110001111111111
000111111111111
110111111111111
110111111111111
111111111111111



00011
11000
11110
11000
00011
11011
11011


*/