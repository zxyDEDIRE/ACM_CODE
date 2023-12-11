#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
const int maxn=1e6;
void solve()
{
	for(int i=1;i<=10;i++)
	{
		for(int aa=1;aa<=100;aa++)
			for(int bb=1;bb<=100;bb++){
				if(aa*bb==i*i){
					cout<<aa<<" "<<bb<<endl;
				}
			}
	}
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    solve();
    return 0;
}