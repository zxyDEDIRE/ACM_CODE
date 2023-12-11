/*
	嵌套变量重复
	特殊样例 0 1 2 n
	数组越界
	开long long
*/
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long
// using ull=unsigned long long;
// using ll=long long;
// using pii=pair<int,int>;
const int dx[]={0,0,1,-1,1,-1,1,-1};
const int dy[]={1,-1,0,0,1,-1,-1,1};
const int mod=998244353;
const int inf=0x3f3f3f3f;
const int INF=1e9+7;
const int maxn=1e6+100;

const int RES = 2000, N = 15;
const string operators = "+-*";
vector<string> ans;
string s;
int n,p[N];//用p记录运算符号，0为没有运算符。
 
bool compute(){
	deque<int> num,opt;
	for(int i = 0, sum = 0; i <= n; i++){
		if(p[i] || i == n){
			num.push_back(sum);		
			if(!opt.empty() && opt.back()== 3 && num.size() >= 2){
				int a = num.back(); num.pop_back();
				int b = num.back(); num.pop_back();
				num.push_back(a*b);
				opt.pop_back();
			}			
			if(i != n) opt.push_back(p[i]);
			sum = 0;
		}
		sum = sum*10+s[i]-'0';
	}
	while(!opt.empty()){
		int x = num.front(); num.pop_front();
		int y = num.front(); num.pop_front();
		if(opt.front() == 1)  num.push_front(x+y);
		else  num.push_front(x-y);
		opt.pop_front();
	}
	return RES == num.front();
}
 
void solve(int cur,int v){
	if(cur == n){
		if(compute()){
			string ss;
			for(int i = 0; i < n; i++){
				if(p[i]) ss.append(1,operators[p[i]-1]);
				ss.append(1,s[i]); 
			}
			ss.append(1,'=');
			ans.push_back(ss);			
		}
		return;
	}
	if(v || cur == 0) solve(cur+1,v*10+s[cur]-'0');	
	if(cur!= 0 ){
		for(int j = 1; j <= 3; j++ ){
			p[cur] = j;
			solve(cur+1,s[cur]-'0');
		}
		p[cur] = 0;
	}
}
void solve()
{
	cin>> s;
	n = s.length()-1;
	solve(0,0);
	if(!ans.size() || s == "2000="){
		cout<< "IMPOSSIBLE\n";
	}else{
		sort(ans.begin(),ans.end());
		for(int i = 0; i < ans.size(); i++)
			cout<< ans[i] << '\n';
	}
}
signed main(){
 // freopen("C:\\Users\\tob\\Desktop\\P4391_9.in.txt","r",stdin);
 // freopen("C:\\Users\\tob\\Desktop\\P4391_9.out.txt","w",stdout);
	// ios::sync_with_stdio(false);
	// cin.tie(nullptr);cout.tie(nullptr);
	// int __;cin>>__;
	// while(__--)
		solve();
//  fclose(stdin);
//  fclose(stdout);
	return 0;
}