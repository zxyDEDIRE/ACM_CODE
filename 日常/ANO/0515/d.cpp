#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
#define int long long
int n;
int a[300005];
struct poi
{
	int hp,id;
}s[300005];
bool cmp(poi a,poi b)
{
	return a.hp<b.hp;
}
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		s[i].hp=a[i];
		s[i].id=i;
	}
	if(n==1){
		cout<<a[1]<<endl;
		return;
	}
	int ans=0;
	ans+=a[1];
	sort(s+2,s+1+n,cmp);
	int he=1;
	int l=2,r=n;
	for(int i=1;i<=n;i++){
		cout<<s[i].hp<<" "<<s[i].id<<endl;
	}
	cout<<ans<<endl;
	while(1){
		//if(n==1)break;
		cout<<"&"<<l<<" "<<r<<endl;
		if(l>=r)break;
		if(l-r+1==he){
			cout<<"end"<<s[l].id<<" "<<s[r].id<<endl;
			break;
		}
		if(he>0){
			if(s[r].id<s[l].id){
				cout<<"pop"<<s[r].id<<" "<<s[r].hp<<endl;
				r--;
				he--;
				
			}
			else{
				cout<<"kill1 "<<s[l].id<<" "<<s[l].hp<<endl;
				l++;
				ans+=s[l].hp;
				he++;
				
			}
		}
		else{
			if(s[l].id<s[r].id){
				cout<<"kill2 "<<s[l].id<<" "<<s[l].hp<<endl;
				l++;
				he++;
				ans+=s[l].hp;
				
			}
			else {
				cout<<"kill3 "<<s[r].id<<" "<<s[r].hp<<endl;
				r--;
				he++;
				ans+=s[r].hp;
				
			}
		}
	}
	cout<<ans<<endl;
}
signed main()
{
	int __;
	//cin >> __;
	__=1;
	while (__--)
		solve();
}