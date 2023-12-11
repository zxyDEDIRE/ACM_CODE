/*
	嵌套变量重复 特殊样例 0 1 2 n 数组越界 开long long
	清空 建图别用vector
*/
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define pp(x) array<int,x>
using ull=unsigned long long;
using ll=long long;
using pii=pair<int,int>;
const int dx[]={0,0,1,-1,1,-1,1,-1};
const int dy[]={1,-1,0,0,1,-1,-1,1};
const int mod=998244353;
const int inf=0x3f3f3f3f;
const int INF=1e9+7;
const int maxn=1e6+100;
const int N=1e3+100;
bool vis[N][N];
bool M[N][N];
char mp[N][N];
int n;
int bfs(int sx,int sy)
{
	queue<pii>q;
	q.push({sx,sy});
	int ans=1;
	while(!q.empty())
	{
		auto [x,y]=q.front();q.pop();
		if(vis[x][y])continue;
		vis[x][y]=1;
		ans&=M[x][y];
		for(int i=0;i<4;i++)
		{
			int xx=x+dx[i];
			int yy=y+dy[i];
			if(mp[xx][yy]=='#')
				q.push({xx,yy});
		}
	}
	return ans;
}
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			cin>>mp[i][j];
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(mp[i][j]!='#')continue;
			for(int k=0;k<4;k++)
			{
				int x=i+dx[k];
				int y=j+dy[k];
				if(mp[x][y]=='.')M[i][j]=1;
			}
			// M[i][j]^=1;
		}
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(vis[i][j])continue;
			if(mp[i][j]=='.')continue;
			ans+=bfs(i,j);
		}
	}
	cout<<ans<<endl;
}
signed main(){
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.in.txt","r",stdin);
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.out.txt","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	// int __;cin>>__;
	// while(__--)
		solve();
//  fclose(stdin);
//  fclose(stdout);
	return 0;
}

这个项目的研究结论主要包括以下几点：

1.通过深入分析不同源网站的编写规则，记录编写特点，可以优化爬虫程序，提高效率，更好地爬取目标网站的信息。
2.使用IP代理池可以避免同一IP多次访问目标网站被封的问题，同时也可以减小IP被封的风险。
3.在进行数据可视化设计时，需要考虑数据本身的特性和呈现需求，选择合适的图表类型并进行布局和设计，使得界面能够直观地表达数据。
4.数据可视化技术的发展，可以为数据分析和决策带来更高效、更准确的帮助和便利，因此在日常工作和研究中应该积极探索和应用数据可视化技术。
总的来说，该项目的研究结论强调了对不同技术手段的综合应用和深入研究，以求更好地解决实际问题和提高工作效率。







在项目实施过程中，创新思维和创新实践的收获包括：

1.创新思维：在该项目中，我们需要不断地挑战传统思维和方法，挖掘新的思路、技术和工具。我们需要分析不同网站的编写规则，寻找合适的数据可视化方案，不断进行尝试和探索。这样的思维方式可以开拓创新领域和思路，为项目和工作带来新的突破点。

2.创新实践：在该项目中，我们需要通过实践来验证各种技术手段和解决方案，不断优化和提升项目的效果和价值。我们需要克服各种挑战和困难，尝试新的方法和工具，以此不断改进和提升项目。这样的实践方式可以帮助我们更好地理解问题，增强创新能力，推动技术进步。
总的来说，在创新思维和创新实践方面的收获，包括了对传统思维和方法的挑战和思考，对新的思路、技术和工具的发掘和创造，以及对实际问题的不断尝试和探索。这些收获都是宝贵的，可以激发创新灵感，推动技术进步，提高工作效率和质量。
