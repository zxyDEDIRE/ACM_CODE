#include <iostream>
#include <vector>
using namespace std;

const int N = 105;

int n, m;
char g[N][N];

struct Frog {
    vector<pair<int, int>> body;  // 青蛙身体的坐标集合
    vector<pair<int, int>> legs;  // 青蛙腿部的坐标集合
};

bool inFrog(vector<pair<int, int>>& coords, int x, int y) {
    for (auto& p : coords) {
        if (p.first == x && p.second == y) {
            return true;
        }
    }
    return false;
}

bool inAnyFrog(vector<Frog>& frogs, int x, int y) {
    for (auto& frog : frogs) {
        if (inFrog(frog.body, x, y) || inFrog(frog.legs, x, y)) {
            return true;
        }
    }
    return false;
}

bool isEye(int x, int y) {
    return g[x][y] == '@' && g[x - 1][y] == '.' && g[x][y - 1] == '.' && g[x][y + 1] == '.' && g[x + 1][y] == '.';
}

bool isFrog(vector<pair<int, int>>& body, vector<pair<int, int>>& legs) {
    // 0. 青蛙的身体必须是一个横跨中心的3*3方格
    if (body.size() != 9) {
        return false;
    }
    bool transverse = false;
    for (int i = 0; i < 9; i++) {
        if (body[i].first == body[4].first) {
            transverse = true;
            break;
        }
    }
    if (!transverse) {
        return false;
    }
    // 1. 青蛙的眼睛必须是两个相互对称的"@"字符
    int cntAt = 0;
    bool symmetric = false;
    for (int i = 0; i < 9; i++) {
        int x = body[i].first, y = body[i].second;
        if (g[x][y] == '@') {
            cntAt++;
            if (inFrog(body, 2 * body[4].first - x, 2 * body[4].second - y)) {
                symmetric = true;
            }
        }
    }
    if (cntAt != 2 || !symmetric) {
        return false;
    }
    // 2. 青蛙的腿部必须是两个分别相对的、中心坐标在同一点的肢体
    if (legs.size() != 8) {
        return false;
    }
    vector<pair<int, int>> leftLegs, rightLegs;
    for (int i = 0; i < 8; i++) {
        int x = legs[i].first, y = legs[i].second;
        if (!inFrog(body, x, y)) {
            return false;
        }
        if (y < body[4].second && x != body[4].first) {
            leftLegs.push_back(legs[i]);
        }
        if (y > body[4].second && x != body[4].first) {
            rightLegs.push_back(legs[i]);
        }
    }
    if (leftLegs.size() != 4 || rightLegs.size() != 4) {
        return false;
    }
    bool pairedLeg = false;
    for (int i = 0; i < 4; i++) {
        if (inFrog(leftLegs, 2 * body[4].first - rightLegs[i].first, 2 * body[4].second - rightLegs[i].second)) {
            pairedLeg = true;
        }
    }
    if (!pairedLeg) {
        return false;
    }
    return true;
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> g[i][j];
        }
    }
    int ans = 0;
    vector<Frog> frogs;
    for (int i = 2; i < n; i++) { // 从第二行开始，因为青蛙必须有完整的身体
        for (int j = 2; j < m; j++) { // 同理，从第二列开始
            if (g[i][j] == '.' && !inAnyFrog(frogs, i, j)) { // 只搜索空白区域，并且不在已发现的青蛙内部
                int cntEye = 0, cntLeg = 0;
                vector<pair<int, int>> body, legs;
                for (int x = i - 1; x <= i + 1; x++) {
                    for (int y = j - 1; y <= j + 1; y++) {
                        if (isEye(x, y)) {
                            cntEye++;
                        }
                        if (g[x][y] == '(') { // 左腿
                            legs.push_back({x, y});
                        } else if (g[x][y] == ')') { // 右腿
                            legs.push_back({x, y});
                        } else if (g[x][y] == '@') { // 身体
                            body.push_back({x, y});
                        }
                    }
                }
                if (cntEye != 2) { // 必须恰好有两个眼睛
                    continue;
                }
                if (!isFrog(body, legs)) { // 必须符合青蛙的身体构造规则
                    continue;
                }
                ans++;
                frogs.push_back({body, legs}); // 将新发现的青蛙加入集合
            }
        }
    }
    cout << ans << endl;
    return 0;
}
