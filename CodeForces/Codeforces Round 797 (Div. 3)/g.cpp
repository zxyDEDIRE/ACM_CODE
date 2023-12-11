#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
const int maxn=1e6;
__int128 read() {
    __int128 s = 0, f = 0;
    char ch = getchar();
    while (!isdigit(ch)) f |= (ch == '-'), ch = getchar();
    while (isdigit(ch)) s = s * 10 + (ch ^ 48), ch = getchar();
    return f ? -s : s;
}
inline void write(__int128 x){
	if(x<0){
    	putchar('-');
		x=-x;
	}
    if(x>9)write(x/10);
    putchar(x%10+'0');
}  
void solve()
{

	cout<<"是否是"<<endl;
	__int128 a;
	// a=read();
	// write(a);
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    solve();
    return 0;
}