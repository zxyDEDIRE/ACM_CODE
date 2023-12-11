#include<bits/stdc++.h>
using namespace std;

const int N=3e5+10;
int n,m,k;
string s;
string l,r;
int id[N][10];
bool dfs(int tp,int nw)
{
	if(tp==m) return false;
	if(nw==-1) return true;
	for(int i=l[tp]-'0';i<=r[tp]-'0';i++)
	{
		if(id[nw][i]==-1) return true;
		if(dfs(tp+1,id[nw][i]+1)) return true;
	}
	return false;
}
void solve()
{
	cin>>s;
	int n=s.size();
	for(int i=0;i<=n;i++)
	{
		for(int j=0;j<10;j++)
		id[i][j]=-1;
	}
	for(int i=n-1;i>=0;i--)
	{
		for(int j=0;j<10;j++){
			id[i][j]=id[i+1][j];
		}
		id[i][s[i]-'0']=i;
	}
	cin>>m;
	cin>>l>>r;
	if(dfs(0,0)){
		cout<<"YES\n";
	}
	else{
		cout<<"NO\n";
	}
	
}

signed main(){
 freopen("C:\\Users\\tob\\Desktop\\in.txt","r",stdin);
 // freopen("C:\\Users\\tob\\Desktop\\in.txt","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	// int __;cin>>__;
	// while(__--)
		clock_t start, finish;
	start = clock();
	/*******代码*******/
	int __;cin>>__;
	while(__--)
	solve();
	/****************/
	finish = clock();
	cout << "the time cost is" <<\
	double(finish - start) / CLOCKS_PER_SEC;
 fclose(stdin);
 // fclose(stdout);
	return 0;
}