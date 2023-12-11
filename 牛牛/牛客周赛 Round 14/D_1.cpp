#include<bits/stdc++.h>
using namespace std;

long long ans=0;
void dfs(int id,char a,char b,char c){
	cout<<a<<" "<<b<<" "<<c<<endl;
	_sleep(400);
    if(a==c) {
        ans++;
    }
    if(id==0) return;
    for(char d='a';d<='z';d++){
        dfs(id-1,b,c,d);
    }
}
void solve(){
    int n;
    cin>>n;
    dfs(n,'1','2','3');
    cout<<ans<<'\n';
}

int main(){
    // ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t=1;
    while(t--){
        solve();
    }
    return 0;
}
