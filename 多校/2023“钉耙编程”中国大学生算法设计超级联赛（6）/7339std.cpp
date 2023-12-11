//知识点：点分治
/*
By:Luckyblock
*/
#include <map>
#include <queue>
#include <cctype>
#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
#define LL long long
#define pr std::pair
#define mp std::make_pair
#define AdmireVega pr <int, pr <int, int> >
const int kN = 1e5 + 10;
//=============================================================
int n, edgenum, head[kN], v[kN << 1], ne[kN << 1];
int root, sumsz, sz[kN], maxsz[kN];
char s[kN];
bool vis[kN];
LL ans;
AdmireVega dis[kN];
std::map <AdmireVega, int> exist;
std::vector <AdmireVega> tmp;
std::queue <AdmireVega> tag;
//=============================================================
inline int read() {
  int f = 1, w = 0;
  char ch = getchar();
  for (; !isdigit(ch); ch = getchar()) if (ch == '-') f = -1;
  for (; isdigit(ch); ch = getchar()) w = (w << 3) + (w << 1) + (ch ^ '0');
  return f * w;
}
void Chkmax(int &fir, int sec) {
  if (sec > fir) fir = sec;
}
void Chkmin(int &fir, int sec) {
  if (sec < fir) fir = sec;
}
void Add(int u_, int v_) {
  v[++ edgenum] = v_;
  ne[edgenum] = head[u_]; 
  head[u_] = edgenum;
}
void CalcSize(int u_, int fa_) { //求重心
  sz[u_] = 1, maxsz[u_] = 0;
  for (int i = head[u_]; i; i = ne[i]) {
    int v_ = v[i];
    if (v_ == fa_ || vis[v_]) continue;
    CalcSize(v_, u_);
    Chkmax(maxsz[u_], sz[v_]);
    sz[u_] += sz[v_];
  }
  Chkmax(maxsz[u_], sumsz - sz[u_]);
  if (maxsz[u_] < maxsz[root]) root = u_;
}
AdmireVega F(AdmireVega x_) {
  int a_ = x_.first, b_ = x_.second.first, c_ = x_.second.second;
  return mp(b_ - a_, mp(c_ - b_, a_ - c_));
}
void CalcDis(int u_, int fa_) { //求得各点到当前根的距离
  tmp.push_back(dis[u_]);
  int ua = dis[u_].first;
  int ub = dis[u_].second.first;
  int uc = dis[u_].second.second;
  for (int i = head[u_]; i; i = ne[i]) {
    int v_ = v[i];
    if (v_ == fa_ || vis[v_]) continue;
    if (s[v_] == 'a') dis[v_] = mp(ua + 1, mp(ub, uc));
    if (s[v_] == 'b') dis[v_] = mp(ua, mp(ub + 1, uc));
    if (s[v_] == 'c') dis[v_] = mp(ua, mp(ub, uc + 1));
    CalcDis(v_, u_);
  }
}
void Dfs(int u_, int fa_) {
  int ua = (s[u_] == 'a');
  int ub = (s[u_] == 'b');
  int uc = (s[u_] == 'c');
  exist[mp(0, mp(0, 0))] = 1;
  tag.push(mp(0, mp(0, 0)));
  vis[u_] = true; //标记已处理
  
  for (int i = head[u_]; i; i = ne[i]) { //处理链信息
    int v_ = v[i];
    if (v_ == fa_ || vis[v_]) continue;
    if (s[v_] == 'a') dis[v_] = mp(1, mp(0, 0));
    if (s[v_] == 'b') dis[v_] = mp(0, mp(1, 0));
    if (s[v_] == 'c') dis[v_] = mp(0, mp(0, 1));
    CalcDis(v_, u_);
    for (int j = 0, lim = tmp.size(); j < lim; ++ j) {
      int a_ = tmp[j].first;
      int b_ = tmp[j].second.first;
      int c_ = tmp[j].second.second;

      AdmireVega ayabe = F(mp(a_ + ua, mp(b_ + ub, c_ + uc)));
      a_ = ayabe.first;
      b_ = ayabe.second.first;
      c_ = ayabe.second.second;
      ans += exist[mp(-a_, mp(-b_, -c_))];
    }
    for (int j = 0, lim = tmp.size(); j < lim; ++ j) {
      AdmireVega ayabe = F(tmp[j]);
      tag.push(ayabe);
      if (!exist.count(ayabe)) exist[ayabe] = 1;
      else exist[ayabe] ++;
    }
    tmp.clear();
  }
  while (!tag.empty()) {
    exist[tag.front()] = 0;
    tag.pop();
  }

  for (int i = head[u_]; i; i = ne[i]) { //分治求解
    int v_ = v[i];
    if (v_ == fa_ || vis[v_]) continue;
    sumsz = sz[v_];
    root = 0, maxsz[root] = kN;
    CalcSize(v_, u_), CalcSize(root, 0), Dfs(root, 0);
  }
}
//=============================================================
int main() { 
  // freopen("1.txt", "r", stdin);
  n = read();
  scanf("%s", s + 1);
  for (int i = 1; i < n; ++ i) {
    int u_ = read(), v_ = read();
    Add(u_, v_), Add(v_, u_);
  }
  
  sumsz = n;
  root = 0, maxsz[root] = kN;
  CalcSize(1, 0), CalcSize(root, 0), Dfs(root, 0);
  printf("%lld\n", ans);
  return 0;
}
