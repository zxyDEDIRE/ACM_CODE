#include<bits/stdc++.h>
using namespace std;
using ll=__int128;
ll p,q;
ll tp,tq;
pair<ll,ll>ans;
string s;
vector<int>v(10,0);
map<vector<int>,set<ll>>mp;
void dfs(int id,ll res){
	
	if(id==(int)s.size()) {
		if(res!=0&&res%tp==0){
			mp[v].insert(res);
		}
		return;
	}
	v[s[id]-'0']++;
	dfs(id+1,res);
	v[s[id]-'0']--;
	dfs(id+1,res*10ll+s[id]-'0');
}
/*

*/
map<vector<int>,set<ll>>mp1;
void dfs1(int id,ll res){
	
	if(id==(int)s.size()) {
		if(res!=0&&res%tq==0){
			mp1[v].insert(res);
		}
		return;
	}
	v[s[id]-'0']++;
	dfs1(id+1,res);
	v[s[id]-'0']--;
	dfs1(id+1,res*10ll+s[id]-'0');
}
inline void read(ll &x){
   ll s = 0, w = 1; char ch = getchar();
   while(ch < '0' || ch > '9'){ if(ch == '-') w = -1; ch = getchar(); }
   while(ch >= '0' && ch <= '9') s = s * 10ll + ch - '0', ch = getchar();
   x = s*w;
   return ;
}
void pr(ll x){
	if(x>=10) pr(x/10);
	putchar(x%10+'0');
}
ll gcd(ll a,ll b){
	return b?gcd(b,a%b):a;
}
void solve(){
	read(p);read(q);
	ll pp=p,qq=q;
	ll gc=gcd(p,q);
	tp=p/gc;tq=q/gc;
	ans.first=p;ans.second=q;
	for(int i=0;i<10;i++){
		v[i]=0;
	}
	mp.clear();mp1.clear();
	s="";
	while(p){
		s=s+char(p%10+'0');
		p/=10;
	}
	reverse(s.begin(),s.end());
	dfs(0,0);
	s="";
	while(q){
		s=s+char(q%10+'0');
		q/=10;
	}
	reverse(s.begin(),s.end());
	for(int i=0;i<10;i++){
		v[i]=0;
	}
	dfs1(0,0);
	for(auto &[x,y]:mp){
		for(auto &s:y){
			if(s>=ans.first) break;
			// pr(s);cout<<'\n';
			// pr(s/tq*tp);cout<<'\n';
			// cout<<"---\n";
			__int128 t=s/tp;
			t*=tq;
			if(t>qq) break;
			if(mp1[x].count(t)==true&&s<ans.first){
				ans={s,t};break;
			}
		}
	}
	pr(ans.first);putchar(' ');
	pr(ans.second);puts("");
}
/*
1
642 321
*/
int main(){
	ll t=1;
	read(t);
	while(t--){
		solve();
	}
	return 0;
}