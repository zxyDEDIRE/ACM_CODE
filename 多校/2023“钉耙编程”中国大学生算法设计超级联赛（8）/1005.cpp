#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
using namespace std;

const int N=3010;
int n;
string s;
int f[N][N][2];
int dfs(int l,int r,int op){
	if(~f[l][r][op]) return f[l][r][op];
	if(l==r&&s[l]-'0'==op) {
		return f[l][r][op]=2;
	}
	else if(l==r&&s[l]-'0'!=op) {
        // cout<<s<<" "<<op<<'\n';
		return f[l][r][op]=(op^1);
	}
	int ff=op^1;
	int t=0;
	int nu=0;
	if(s[l]-'0'==op){
		nu++;
		int p=dfs(l+1,r,op^1);
		if(p==op)ff=op;
		else if(p==2) t++;
	}
	if(s[r]-'0'==op){
		nu++;
		int p=dfs(l,r-1,op^1);
		if(p==op) ff=op;
		else if(p==2) t++; 
	}
	if((nu==t&&nu)||(ff==((op^1))&&t)) ff=2;
	return f[l][r][op]=ff;
}
void solve(){
	cin>>n;
	s="_"+s;
    // cin>>s;
    // s="_"+s;
	for(int i=1;i<=n;i++)
	{
		for(int p=0;p<(1<<i);p++){
			s="_";
			int cnt_0=0;
			int cnt_1=0;
			for(int k=0;k<i;k++){
				if((p>>k)&1) s+='1',cnt_1++;
				else s+='0',cnt_0++;
			}
			// if(s[1]==s[i])continue;
			// if(cnt_0!=cnt_1+1)continue;
			for(int j=1;j<=i;j++){
				for(int k=1;k<=i;k++){
					f[j][k][0]=f[j][k][1]=-1;
				}
			}
			int t=dfs(1,i,0);
			if(t==2) t=-1;
			cout<<s<<" "<<t<<'\n';
		}
	}
}
/*
*/
int main(){
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	memset(f,-1,sizeof f);
	int t=1;
    // cin>>t;
	while(t--){
		solve();
	}
	return 0;
}
