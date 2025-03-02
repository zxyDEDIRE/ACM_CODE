# J [小刻的画图写话](https://ac.nowcoder.com/acm/contest/72386/J)

出题人:buns out

考察点:码力,函数

> **宣传一下我的模板库：** 
>
> [Release ACM模板 · zxyDEDIRE/ACM-Code-Library (github.com)](https://github.com/zxyDEDIRE/ACM-Code-Library/releases/tag/QAQ)
>
> [zxyDEDIRE/ACM-Code-Library at QAQ (github.com)](https://github.com/zxyDEDIRE/ACM-Code-Library/tree/QAQ)
>
> 有LaTeX源码也有PDF版本



解法一：

最方便的解法就是函数递归，翻转操作就是传入的参数异或 $1$，由大的图形递归到小的图形。

首先传入的四个参数就是当前正方形的坐标,左上角 $(x1,y1)$ ,右下角 $(x2,y2)$ ，参数 $op$ 就是是否进行翻转操作。

~~~cpp
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
const int N=3111;
char mp[N][N];
int n;
void dfs(int x1,int y1,int x2,int y2,int op)
{
	if(x1==x2&&y1==y2){
		mp[x1][y1]=('0'+op);
		return ;
	}
	int mid_x=(x1+x2)>>1;
	int mid_y=(y1+y2)>>1;
	dfs(x1,y1,mid_x,mid_y,op);
	dfs(x1,mid_y+1,mid_x,y2,op^1);
	dfs(mid_x+1,y1,x2,mid_y,op^1);
	dfs(mid_x+1,mid_y+1,x2,y2,op);
}
void solve()
{
	cin>>n;
	n=(1ll<<n);
	dfs(1,1,n,n,1);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++)
			cout<<mp[i][j];
        cout<<endl;
	}
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
		solve();
	return 0;
}
/*

https://polygon.codeforces.com/plain-answer/answer-10.txt?testset=tests&index=10&session=e40d2be16baa1fbcac4ac4ce94a88eb0147bd4b7&ccid=1ea5ccabf3e3ad2d489fda4e0e37f208
https://dwz.cn/OwZR2vmA

*/
~~~

解法二：
先画出小图形再生成次大图形，代码较为麻烦。

~~~cpp
#include<bits/stdc++.h>
using namespace std;
const int N=5222;
int mp[N][N];
int n;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>n;
    mp[1][1]=1;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= (1 << (i - 1)); j++) {
            for (int k = 1; k <= (1 << (i - 1)); k++) {
                mp[j + (1 << (i - 1))][k + (1 << (i - 1))] = mp[j][k];
                mp[j][k + (1 << (i - 1))] = 1 - mp[j][k];
                mp[j + (1 << (i - 1))][k] = 1 - mp[j][k];
            }
        }
    }
    for(int i=1;i<=(1<<n);i++){
        for(int j=1;j<=(1<<n);j++)
            cout<<mp[i][j];
        cout<<endl;
    }
    return 0;
}
/*
*/
~~~

