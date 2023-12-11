#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10,mod=1e9+7;

set<int>s;
void solve(){
    int a,b;
    // cin>>a>>b;
    srand(time(0));
    a=rand();
    b=rand();
    while(a==b)b+=rand();
    if(a<b) swap(a,b);
    if(s.count(a-b)) {
        cout<<"1\n";
    }else{
        int cnt=a-b;
        for(int i=1;1ll*i*i<=cnt;i++){
            if(cnt%i==0){
                int a=i,b=cnt/i;
                if(a%2==b%2){
                    // cout<<2<<'\n';return;
                }
            }
        }
        for(int i=1;1ll*i*i<=cnt;i++){
            if(s.count(cnt-i*i)){
                // cout<<2<<'\n';return;
            } 
         }
        // cout<<min(3,cnt)<<'\n';
    }
}
/*
2
1 4
1 7
*/
int main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    for(int i=1;1ll*i*i<=1e9;i++){
        s.insert(i*i);
    }
        clock_t start, finish;
	start = clock();
    int t=1e3;
    // cin>>t;
    while(t--){
	/*******代码*******/
	solve();
	/****************/
	finish = clock();
    }
	cout << "the time cost is" <<\
	double(finish - start) / CLOCKS_PER_SEC;
    return 0;
}
