#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define pp(x) array<int,x>
using ull=unsigned long long;
using ll=long long;
using pii=pair<int,int>;
using pdd=pair<double,double>;
const int dx[]={0,0,1,-1,1,-1,1,-1};
const int dy[]={1,-1,0,0,1,-1,-1,1};
const int mod=998244353;
const int inf=0x3f3f3f3f;
const int INF=1e9+7;
const int maxn=1e6+100;
void solve()
{

}
signed main(){
	vector<int>p;
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		int x;
		scanf("%d",&x);
		p.push_back(x);
	}
	sort(p.begin(),p.end());
	int ans=0;
	for(int i=0;i<n;i+=2)
	{
		ans+=p[i+1]-p[i];
	}
	printf("%d",ans);


	return 0;
}
/*
你遇到的问题是因为在Kotlin中，Java的Arrays.sort()方法并不能直接在Kotlin中使用。Kotlin有自己的排序方法，你只需要对数组使用.sorted()函数就可以实现排序。

你的代码应该修改为：

kotlin
复制
fun main() {    val p = IntArray(100) // 根据输入最大值n动态分配数组长度    
var n: Int   
 val scanner = Scanner(System.in)    
 scanner.nextInt() // 读取第一个输入n   
  for (i in 1..n) {       
   val x = scanner.nextInt()      
     p[i] = x    
     }   
      p.sorted() // 使用Kotlin的sorted()函数排序   
       var ans = 0    
       for (i in 0 until n by 2) {        
       ans += p[i + 1] - p[i]   
        }    
       println(ans) // 输出结果到控制台}

这样，你的代码应该可以正常运行。如果你有其他关于Kotlin编程的问题，欢迎继续提问。
*/