#include <bits/stdc++.h>
using namespace std;

const int N = 100;

int get(char num, char ch){
	if(ch == 'w'){
		return num - '1';
	}
	else if(ch == 'b'){
		return num - '1' + 9;
	}
	else if(ch == 's'){
		return num - '1' + 18;
	}
	else{
		return num - '1' + 27;
	}
}

string change(int num){
	string ans;
	if(num < 9) {
		ans = "w";
		ans=char(num +'1')+ans;
	}
	else if(num < 18){
		ans = "b";
		ans = char(num - 9 + '1') + ans;
	}
	else if(num < 27){
		ans = "s";
		ans = char(num - 18 + '1') + ans;
	}
	else {
		ans = "z";
		ans = char(num - 27 + '1') + ans;
	}
	return ans;
}

bool check1(vector<int>mp){
	for(int i=0;i<9;i++){
		if(mp[i]){
			mp[i]%=3;
			if(mp[i]){
				if(i+2>=9) return false;
				mp[i+1]-=mp[i];mp[i+2]-=mp[i];
				if(mp[i+1]<0||mp[i+2]<0) return false;
			}
		}
	}
	for(int i=9;i<18;i++){
		if(mp[i]){
			mp[i]%=3;
			if(mp[i]){
				if(i+2>=18) return false;
				mp[i+1]-=mp[i];mp[i+2]-=mp[i];
				if(mp[i+1]<0||mp[i+2]<0) return false;
			}
		}
	}
	for(int i=18;i<27;i++){
		if(mp[i]){
			mp[i]%=3;
			if(mp[i]){
				if(i+2>=27) return false;
				mp[i+1]-=mp[i];mp[i+2]-=mp[i];
				if(mp[i+1]<0||mp[i+2]<0) return false;
			}
		}
	}
	return true;
}
bool check(vector<int>mp)
{
	int s=-1;
	for(int i=27;i<34;i++){
		if(mp[i]%3==1){
			return false;
		} 
		else if(mp[i]%3==2){
			if(s==-1){
				s=i;
			}
			else{
				return false;
			}
		}
	}
	if(s!=-1){
		return check1(mp);
	}
	else{
		for(int i=0;i<27;i++){
			if(mp[i]>=2){
				mp[i]-=2;
				if(check1(mp)){
					return true;
				}
				mp[i]+=2;
			}
		}
	}
	return false;
}
/*
1
1b2b3b4b5b6b2s4s5s5s5s6s7s8s
*/
vector<int>ans[34];
void solve(){
	string s;
	cin >> s;
	vector<int>mp(34,0);
	for(int i = 0; i < 28; i += 2){
		mp[get(s[i], s[i + 1])] ++;
	}

	if(check(mp)){
		cout<<"Tsumo!\n";
		return;
	}

	int sum=0;
	for(int i = 0; i < 34; i ++){
		if(mp[i])
		{
			mp[i]--;
			int f=0;
			for(int j=0;j<34;j++)
			{
				if(i==j) continue;
				mp[j]++;
				if(check(mp))
				{
					f=1;
					ans[i].push_back(j);
				}
				mp[j]--;
			}
			if(f) sum++;
			mp[i]++;
		}
	}
	cout<<sum<<'\n';
	for(int i=0;i<34;i++){
		if((int)ans[i].size()){
			cout<<change(i)<<" ";
			for(auto v:ans[i]) cout<<change(v);
			cout<<'\n';
			ans[i].clear();
		}
	}
}

int main(){
	// cout << change(get('2', 's'));
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int t;
	cin >> t;
	while(t --){
		solve();
	}
	return 0;
}