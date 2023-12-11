#include <bits/stdc++.h>

using i64 = std::int64_t;

namespace Geometry {
// using T = i64;
// constexpr T eps = 0;

using T = double;
constexpr T eps = 1E-10;

bool equal(const T &x, const T &y) { return abs(x - y) <= eps; }
int sgn(T x) { return (x > 0) - (x < 0); }
inline constexpr int type(T x, T y) {
    if (x == 0 and y == 0) return 0;
    if (y < 0 or (y == 0 and x > 0)) return -1;
    return 1;
}
struct Point {
    T x, y;
    constexpr Point(T _x = 0, T _y = 0) : x(_x), y(_y) {}
    constexpr Point operator+() const noexcept { return *this; }
    constexpr Point operator-() const noexcept { return Point(-x, -y); }
    constexpr Point operator+(const Point &p) const {
        return Point(x + p.x, y + p.y);
    }
    constexpr Point operator-(const Point &p) const {
        return Point(x - p.x, y - p.y);
    }
    constexpr Point &operator+=(const Point &p) {
        return x += p.x, y += p.y, *this;
    }
    constexpr Point &operator-=(const Point &p) {
        return x -= p.x, y -= p.y, *this;
    }
    constexpr T operator*(const Point &p) const { return x * p.x + y * p.y; }
    const Point operator/(T d) const { return Point(x / d, y / d); }
    constexpr Point &operator*=(const T &k) { return x *= k, y *= k, *this; }
    constexpr Point operator*(const T &k) { return Point(x * k, y * k); }
    constexpr bool operator==(const Point &r) const noexcept {
        return r.x == x and r.y == y;
    }
    constexpr bool operator!=(const Point &r) const noexcept {
        return !(*this == r);
    }
    constexpr T cross(const Point &r) const { return x * r.y - y * r.x; }
    constexpr T cross(Point a, Point b) const {
        return (a - *this).cross(b - *this);
    }
    constexpr bool operator<(const Point &r) const {
        return std::pair(x, y) < std::pair(r.x, r.y);
    }

    // 1 : left, 0 : same, -1 : right
    constexpr int toleft(const Point &r) const {
        auto t = cross(r);
        return t > eps ? 1 : t < -eps ? -1 : 0;
    }

    constexpr bool arg_cmp(const Point &r) const {
        int L = type(x, y), R = type(r.x, r.y);
        if (L != R) return L < R;

        T X = x * r.y, Y = r.x * y;
        if (X != Y) return X > Y;
        return x < r.x;
    }
};
bool arg_cmp(const Point &l, const Point &r) { return l.arg_cmp(r); }
std::ostream &operator<<(std::ostream &os, const Point &p) {
    return os << p.x << " " << p.y;
}
std::istream &operator>>(std::istream &is, Point &p) {
    is >> p.x >> p.y;
    return is;
}

struct Line {
    Point a, b;
    Line() = default;
    Line(Point a, Point b) : a(a), b(b) {}
    // ax + by = c
    Line(T A, T B, T C) {
        if (A == 0) {
            a = Point(0, C / B), b = Point(1, C / B);
        } else if (B == 0) {
            a = Point(C / A, 0), b = Point(C / A, 1);
        } else {
            a = Point(0, C / B), b = Point(C / A, 0);
        }
    }
    // 1 : left, 0 : same, -1 : right
    constexpr int toleft(const Point &r) const {
        auto t = (b - a).cross(r - a);
        return t > eps ? 1 : t < -eps ? -1 : 0;
    }

    friend std::ostream &operator<<(std::ostream &os, Line &ls) {
        return os << "{"
                  << "(" << ls.a.x << ", " << ls.a.y << "), (" << ls.b.x << ", "
                  << ls.b.y << ")}";
    }
};
std::istream &operator>>(std::istream &is, Line &p) { return is >> p.a >> p.b; }

struct Segment : Line {
    Segment() = default;
    Segment(Point a, Point b) : Line(a, b) {}
};

std::ostream &operator<<(std::ostream &os, Segment &p) {
    return os << p.a << " to " << p.b;
}
std::istream &operator>>(std::istream &is, Segment &p) {
    is >> p.a >> p.b;
    return is;
}

struct Circle {
    Point p;
    T r;
    Circle() = default;
    Circle(Point p, T r) : p(p), r(r) {}
};

using pt = Point;
using Points = std::vector<pt>;
using Polygon = Points;
T cross(const pt &x, const pt &y) { return x.x * y.y - x.y * y.x; }
T dot(const pt &x, const pt &y) { return x.x * y.x + x.y * y.y; }

T abs2(const pt &x) { return dot(x, x); }

int ccw(const Point &a, Point b, Point c) {
    b = b - a, c = c - a;
    if (cross(b, c) > 0) return +1;    // "COUNTER_CLOCKWISE"
    if (cross(b, c) < 0) return -1;    // "CLOCKWISE"
    if (dot(b, c) < 0) return +2;      // "ONLINE_BACK"
    if (abs2(b) < abs2(c)) return -2;  // "ONLINE_FRONT"
    return 0;                          // "ON_SEGMENT"
}

bool parallel(const Line &a, const Line &b) {
    return (cross(a.b - a.a, b.b - b.a) == 0);
}

bool orthogonal(const Line &a, const Line &b) {
    return (dot(a.a - a.b, b.a - b.b) == 0);
}

bool intersect(const Line &l, const Point &p) {
    return abs(ccw(l.a, l.b, p)) != 1;
}

bool intersect(const Line &l, const Line &m) { return !parallel(l, m); }

bool intersect(const Segment &s, const Point &p) {
    return ccw(s.a, s.b, p) == 0;
}

bool intersect(const Line &l, const Segment &s) {
    return cross(l.b - l.a, s.a - l.a) * cross(l.b - l.a, s.b - l.a) <= 0;
}

bool intersect(const Segment &s, const Segment &t) {
    return ccw(s.a, s.b, t.a) * ccw(s.a, s.b, t.b) <= 0 &&
           ccw(t.a, t.b, s.a) * ccw(t.a, t.b, s.b) <= 0;
}

bool onSegment(Point s, Point e, Point p) {
    return p.cross(s, e) == 0 && dot((s - p), (e - p)) <= 0;
}
std::vector<Point> segInter(const Segment &sa, const Segment &sb) {
    auto a = sa.a, b = sa.b;
    auto c = sb.a, d = sb.b;
    auto oa = c.cross(d, a), ob = c.cross(d, b), oc = a.cross(b, c),
         od = a.cross(b, d);
    if (sgn(oa) * sgn(ob) < 0 && sgn(oc) * sgn(od) < 0)
        return {(a * ob - b * oa) / (ob - oa)};
    std::set<Point> s;
    if (onSegment(c, d, a)) s.insert(a);
    if (onSegment(c, d, b)) s.insert(b);
    if (onSegment(a, b, c)) s.insert(c);
    if (onSegment(a, b, d)) s.insert(d);
    return {begin(s), end(s)};
}

bool intersect(const Polygon &ps, const Polygon &qs) {
    int pl = size(ps), ql = size(qs), i = 0, j = 0;
    while ((i < pl or j < ql) and (i < 2 * pl) and (j < 2 * ql)) {
        auto ps0 = ps[(i + pl - 1) % pl], ps1 = ps[i % pl];
        auto qs0 = qs[(j + ql - 1) % ql], qs1 = qs[j % ql];
        if (intersect(Segment(ps0, ps1), Segment(qs0, qs1))) return true;
        Point a = ps1 - ps0;
        Point b = qs1 - qs0;
        T v = cross(a, b);
        T va = cross(qs1 - qs0, ps1 - qs0);
        T vb = cross(ps1 - ps0, qs1 - ps0);

        if (!v and va < 0 and vb < 0) return false;
        if (!v and !va and !vb) {
            i += 1;
        } else if (v >= 0) {
            if (vb > 0)
                i += 1;
            else
                j += 1;
        } else {
            if (va > 0)
                j += 1;
            else
                i += 1;
        }
    }
    return false;
}

T norm(const Point &p) { return p.x * p.x + p.y * p.y; }
Point projection(const Segment &l, const Point &p) {
    T t = dot(p - l.a, l.a - l.b) / norm(l.a - l.b);
    return l.a + (l.a - l.b) * t;
}

Point crossPoint(const Line &l, const Line &m) {
    T A = cross(l.b - l.a, m.b - m.a);
    T B = cross(l.b - l.a, l.b - m.a);
    if (A == 0 and B == 0) return m.a;
    return m.a + (m.b - m.a) * (B / A);
}

Point crossPoint(const Segment &l, const Segment &m) {
    return crossPoint(Line(l), Line(m));
}

bool isConvex(const Points &p) {
    int n = (int)p.size();
    for (int i = 0; i < n; i++) {
        if (ccw(p[(i + n - 1) % n], p[i], p[(i + 1) % n]) == -1) return false;
    }
    return true;
}

Points convexHull(Points p) {
    int n = p.size(), k = 0;
    if (n <= 2) return p;
    std::sort(begin(p), end(p),
              [](pt x, pt y) { return (x.x != y.x ? x.x < y.x : x.y < y.y); });
    Points ch(2 * n);
    for (int i = 0; i < n; ch[k++] = p[i++]) {
        while (k >= 2 && cross(ch[k - 1] - ch[k - 2], p[i] - ch[k - 1]) <= 0)
            --k;
    }
    for (int i = n - 2, t = k + 1; i >= 0; ch[k++] = p[i--]) {
        while (k >= t && cross(ch[k - 1] - ch[k - 2], p[i] - ch[k - 1]) <= 0)
            --k;
    }
    ch.resize(k - 1);
    return ch;
}

T area2(const Points &p) {
    T res = 0;
    for (int i = 0; i < (int)p.size(); i++) {
        res += cross(p[i], p[i == int(size(p)) - 1 ? 0 : i + 1]);
    }
    return res;
}

enum { _OUT, _ON, _IN };

int containsHullPoint(const Polygon &Q, const Point &p) {
    // Brute Force : O(|Q|)
    bool in = false;
    for (int i = 0; i < Q.size(); i++) {
        Point a = Q[i] - p, b = Q[(i + 1) % Q.size()] - p;
        if (a.y > b.y) std::swap(a, b);
        if (a.y <= 0 && 0 < b.y && cross(a, b) < 0) in = !in;
        if (cross(a, b) == 0 && dot(a, b) <= 0) return _ON;
    }
    return in ? _IN : _OUT;
}

Polygon minkowskiSum(const Polygon &P, const Polygon &Q) {
    std::vector<Segment> e1(P.size()), e2(Q.size()), ed(P.size() + Q.size());
    const auto cmp = [](const Segment &u, const Segment &v) {
        return (u.b - u.a).arg_cmp(v.b - v.a);
    };
    for (int i = 0; i < int(P.size()); i++)
        e1[i] = {P[i], P[(i + 1) % P.size()]};
    for (int i = 0; i < int(Q.size()); i++)
        e2[i] = {Q[i], Q[(i + 1) % Q.size()]};
    std::rotate(begin(e1), std::min_element(begin(e1), end(e1), cmp), end(e1));
    std::rotate(begin(e2), std::min_element(begin(e2), end(e2), cmp), end(e2));
    std::merge(begin(e1), end(e1), begin(e2), end(e2), begin(ed), cmp);
    const auto check = [](const Points &res, const Point &u) {
        const auto back1 = res.back(), back2 = *prev(end(res), 2);
        return equal(cross(back1 - back2, u - back2), eps) and
               dot(back1 - back2, u - back1) >= -eps;
    };
    auto u = e1[0].a + e2[0].a;
    Points res{u};
    res.reserve(P.size() + Q.size());
    for (const auto &v : ed) {
        u = u + v.b - v.a;
        while (int(size(res)) >= 2 and check(res, u)) res.pop_back();
        res.emplace_back(u);
    }
    if (res.size() and check(res, res[0])) res.pop_back();
    return res;
}

// -1 : on, 0 : out, 1 : in
// O(log(n))
int containsHullPointFast(const Polygon &p, const Point &a) {
    // Binary Search O(log|P|)
    if (p.size() == 1) return a == p[0] ? -1 : 0;
    if (p.size() == 2) return intersect(Segment(p[0], p[1]), a);
    if (a == p[0]) return -1;
    if ((p[1] - p[0]).toleft(a - p[0]) == -1 ||
        (p.back() - p[0]).toleft(a - p[0]) == 1)
        return 0;
    const auto cmp = [&](const Point &u, const Point &v) {
        return (u - p[0]).toleft(v - p[0]) == 1;
    };
    const size_t i = lower_bound(p.begin() + 1, p.end(), a, cmp) - p.begin();
    if (i == 1) return intersect(Segment(p[0], p[i]), a) ? -1 : 0;
    if (i == p.size() - 1 && intersect(Segment(p[0], p[i]), a)) return -1;
    if (intersect(Segment(p[i - 1], p[i]), a)) return -1;
    return (p[i] - p[i - 1]).toleft(a - p[i - 1]) > 0;
}

Points halfplaneIntersection(std::vector<Line> L, const T inf = 1e9) {
    Point box[4] = {Point(inf, inf), Point(-inf, inf), Point(-inf, -inf),
                    Point(inf, -inf)};
    for (int i = 0; i < 4; i++) {
        L.emplace_back(box[i], box[(i + 1) % 4]);
    }
    std::sort(begin(L), end(L), [](const Line &l, const Line &r) {
        return (l.b - l.a).arg_cmp(r.b - r.a);
    });
    std::deque<Line> dq;
    int len = 0;
    auto check = [](const Line &a, const Line &b, const Line &c) {
        return a.toleft(crossPoint(b, c)) == -1;
    };
    for (int i = 0; i < (int)L.size(); i++) {
        while (dq.size() > 1 and check(L[i], *(end(dq) - 2), *(end(dq) - 1)))
            dq.pop_back();
        while (dq.size() > 1 and check(L[i], dq[0], dq[1])) dq.pop_front();
        // dump(L[i], si(dq));

        if (dq.size() and
            equal(cross(L[i].b - L[i].a, dq.back().b - dq.back().a), 0)) {
            if (dot(L[i].b - L[i].a, dq.back().b - dq.back().a) < eps)
                return {};
            if (L[i].toleft(dq.back().a) == -1)
                dq.pop_back();
            else
                continue;
        }
        dq.emplace_back(L[i]);
    }

    while (dq.size() > 2 and check(dq[0], *(end(dq) - 2), *(end(dq) - 1)))
        dq.pop_back();
    while (dq.size() > 2 and check(dq.back(), dq[0], dq[1])) dq.pop_front();
    if ((int)size(dq) < 3) return {};
    Polygon ret(dq.size());
    for (int i = 0; i < (int)dq.size(); i++)
        ret[i] = crossPoint(dq[i], dq[(i + 1) % dq.size()]);

    return ret;
}
}  // namespace Geometry

using namespace Geometry;

void solve() {
    std::cout << std::fixed << std::setprecision(10);

    Point lb, rt;

    std::cin >> lb >> rt;
    std::vector<Line> cur;

    cur.push_back({lb, {rt.x, lb.y}});
    cur.push_back({{rt.x, lb.y}, rt});
    cur.push_back({rt, {lb.x, rt.y}});
    cur.push_back({{lb.x, rt.y}, lb});

    Segment a, b;
    std::cin >> a >> b;
    if (a.b < a.a) std::swap(a.a, a.b);
    if (b.b < b.a) std::swap(b.a, b.b);

    auto inter = segInter(a, b);

    if (inter.size() == 0) {
        std::cout << 0.0 << '\n';
        return;
    }

    if (inter.size() == 1) {
        auto interPoint = inter[0];
        Point t1, t2;

        int judgeCnt1 = 0, judgeCnt2 = 0;
        if (interPoint == a.a) {
            t1 = a.b;
            judgeCnt1++;
        }
        if (interPoint == a.b) {
            t1 = a.a;
            judgeCnt1++;
        }

        if (interPoint == b.a) {
            t2 = b.b;
            judgeCnt2++;
        }
        if (interPoint == b.b) {
            t2 = b.a;
            judgeCnt2++;
        }

        if ((judgeCnt1 == 0) || (judgeCnt2 == 0)) {
            std::cout << 0.0 << '\n';
            return;
        }

        auto rotate = [](const Point &a) -> Point { return {-a.y, a.x}; };
        Line r1(interPoint, rotate(t1 - interPoint) + interPoint);
        Line r2(interPoint, rotate(t2 - interPoint) + interPoint);
        cur.push_back(r1);
        cur.push_back(r2);

        auto hull = halfplaneIntersection(cur);
        auto sum = area2(hull) / 2.0;

        std::cout << sum << '\n';
        return;
    }

    if (inter.size() == 2) {
        auto interPointa = inter[0];
        auto interPointb = inter[1];
        if (a.a == b.a && a.b == b.b) {
            auto hull = halfplaneIntersection(cur);

            auto sum = area2(hull) / 2.0;
            std::cout << sum << '\n';
            return;
        }
        auto solveOnePoint = [&cur](Point x, Point y) -> void {
            auto rotate = [](const Point &a) -> Point { return {a.y, -a.x}; };
            Line r(x, rotate(y - x) + x);
            cur.push_back(r);
            auto hull = halfplaneIntersection(cur);
            auto sum = area2(hull) / 2.0;

            std::cout << sum << '\n';
            return;
        };
        if (a.a == b.a && (a.b == interPointa || a.b == interPointb)) {
            solveOnePoint(a.b, a.a);
            return;
        }
        if (a.a == b.a && (b.b == interPointa || b.b == interPointb)) {
            solveOnePoint(b.b, a.a);
            return;
        }
        if (a.b == b.b && (a.a == interPointa || a.a == interPointb)) {
            solveOnePoint(a.a, a.b);
            return;
        }
        if (a.b == b.b && (b.a == interPointa || b.a == interPointb)) {
            solveOnePoint(b.a, a.b);
            return;
        }

        auto rotate = [](const Point &a) -> Point { return {a.y, -a.x}; };
        Line r1(interPointa, rotate(interPointb - interPointa) + interPointa);
        Line r2(interPointb, rotate(interPointa - interPointb) + interPointb);
        cur.push_back(r1);
        cur.push_back(r2);
        auto hull = halfplaneIntersection(cur);
        auto sum = area2(hull) / 2.0;

        std::cout << sum << '\n';
        return;
    }

    return;
}
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int T;
    std::cin >> T;

    while (T--) {
        solve();
    }

    return 0;
}