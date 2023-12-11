#include<bits/stdc++.h>
using namespace std;

const int N=3e6+10;
int n,q;
int p;
map<pair<pair<int,int>,long long>,int>mp[2];
int top;
map<long long,int>mpp[N][2]; 
vector<long long>tr[N];
vector<long long>gcc;
const int M=5e4+10;
long long B[M];
vector<pair<int,long long>>v[M];
void insert(int idd,int gc)
{
	int id=0,ip=0;
	for(int i=(int)v[idd].size()-1;i>=0;i--)
	{
		int f=v[idd][i].first;
		long long val=v[idd][i].second;
		if(mp[f].count({{id,gc},val})==false) mp[f][{{id,gc},val}]=++p;
		if(mpp[id][f].count(gc)==false) mpp[id][f][gc]=++top;
		ip=mpp[id][f][gc];
		tr[ip].push_back(val);
		id=mp[f][{{id,gc},val}];
	}
}
int qr(int idd,int gc)
{
	int id=0,ip=0;
	for(int i=(int)v[idd].size()-1;i>=0;i--)
	{
		int f=v[idd][i].first;
		long long val=v[idd][i].second;
		if(mpp[id][f].count(gc)==false) return 0;
		ip=mpp[id][f][gc];
		if(i==0) break;
		if(mp[f].count({{id,gc},val})==false) return 0;
		id=mp[f][{{id,gc},val}];
	}
	int t=lower_bound(tr[ip].begin(),tr[ip].end(),v[idd][0].second)-tr[ip].begin();
	return tr[ip].size()-t;
}
void solve()
{
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		long long a,b;
		cin>>a>>b;
		while(a)
		{
			int f=0;
			long long cnt=0;
			if(a>=b)
			{
				f=0;
				cnt=a/b;
				a=a-cnt*b;
			}
			else{
				f=1;
				cnt=b/a;
				b=b-cnt*a;
				if(b==0) {
			    	b+=a;cnt--;
				}
			}
			v[i].push_back({f,cnt});
		}		
		B[i]=b;
		gcc.push_back(b);
	}
	sort(gcc.begin(),gcc.end());
	gcc.erase(unique(gcc.begin(),gcc.end()),gcc.end());
	for(int i=1;i<=n;i++)
	{
		int t=lower_bound(gcc.begin(),gcc.end(),B[i])-gcc.begin();
		insert(i,t);
	}
	for(int i=1;i<=top;i++) sort(tr[i].begin(),tr[i].end());
	while(q--)
	{
		long long a,b;
		cin>>a>>b;
		v[0].clear();
		while(a)
		{
			int f=0;
			long long cnt=0;
			if(a>=b)
			{
				f=0;
				cnt=a/b;
				a=a-cnt*b;
			}
			else{
				f=1;
				cnt=b/a;
				b=b-cnt*a;
				if(b==0) {
					b+=a;
					cnt--;
				}
			}
			v[0].push_back({f,cnt});
		}
		int t=lower_bound(gcc.begin(),gcc.end(),b)-gcc.begin();
		if(t==gcc.size()||gcc[t]!=b)
		{
			cout<<0<<'\n';continue;
		}
		cout<<qr(0,t)<<'\n';
	}
	mp[0].clear();mp[1].clear();
	for(int i=0;i<=p;i++) mpp[i][0].clear(),mpp[i][1].clear();
	for(int i=1;i<=top;i++) tr[i].clear();
	gcc.clear();
	for(int i=1;i<=n;i++) v[i].clear();
	p=0;top=0;
}
/*
*/
int main()
{
	freopen("C:\\Users\\tob\\Desktop\\in.txt","r",stdin);
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int t=1;
	cin>>t;
	while(t--)
	{
		solve();
	 } 
	return 0;
} 
/*
3
5 2
4 3
2 1
8 3
9 3
1 6
3 6
10 1

5 2
10 9
7 8
9 9
7 5
8 10
3 5
2 1

5 2
8 9
1 4
8 9
1 1
3 6
6 8
1 2
*/