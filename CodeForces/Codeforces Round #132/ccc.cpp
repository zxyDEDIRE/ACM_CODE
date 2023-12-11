#define MOD 998244353

#include <iostream>
#include <vector>
#include <stdlib.h>
#include <queue>
#include <numeric>
#include <cmath>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <map>
#include <algorithm>
#include <stack>
#include <memory>




#define all(x) x.begin(),x.end()
#define int int64_t
#define IO_FAST std::ios_base::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);

template <class T=int>
std::vector<T> read_vector(size_t size) {
    std::vector<T> vector(size);
    for (auto& element : vector) {
        std::cin >> element;
    }
    return vector;
}

void YES(bool yes=true) {
    std::cout << (yes ? "YES\n" : "NO\n");
}

void NO() {
    std::cout << "NO\n";
}


#define mp(x, y) std::make_pair(x, y)


class range {
public:
    int start;
    int stop;
    class iterator {
    public:
        int i;
        iterator(int i) : i(i) {}
        iterator& operator++() {
            ++i;
            return *this;
        }
        int operator*() {
            return i;
        }
        bool operator!= (const iterator& other) {
            return i != other.i;
        }
    };

    range(int stop) : start(0), stop(stop) {}

    range(int start, int stop) : start(start), stop(stop) {}

    iterator begin() {
        return start;
    }

    iterator end() {
        return stop;
    }
};





template<typename T>
void print(const T& x) {
    std::cout << x << ' ';
}
template<typename T>
void println(const T& x) {
    std::cout << x << '\n';
}

template<typename T, typename U>
void print(const std::pair<T, U>& x) {
    std::cout << '(' << x.first << ',' << (x.second < 0 ? "": " ") << x.second << ") ";
}

template<typename T, typename U, typename V>
void print(const std::tuple<T, U, V>& x) {
    std::cout << '(' << std::get<0>(x) << ',' << std::get<1>(x) << ',' << std::get<2>(x) << ") ";
}



void println() {
    std::cout << '\n';
}

template <typename T>
void print(const std::vector<T>& a) {
    for (auto x : a) {
        print(x);
    }
}

template <typename T>
void println(const std::vector<T>& a) {
    for (auto x : a) {
        print(x);
    }
    std::cout << '\n';
}




#define read(x) int x;std::cin >> x;
#define read2(x, y) int x, y;std::cin >> x >> y;
#define read3(x, y, z) int x, y, z;std::cin >> x >> y >> z;

template <class Row>
class BaseGrid {
public:
    class iterator {
    public:
        BaseGrid<Row>* baseGrid;
        size_t i;
        size_t j;

        iterator(BaseGrid<Row>* baseGrid, size_t i, size_t j)
                : baseGrid(baseGrid), i(i), j(j)
        {}

        iterator& operator++() {
            if (j < (baseGrid->m) - 1) {
                j += 1;
            } else {
                i += 1;
                j = 0;
            }
            return *this;
        }
        bool operator!= (const iterator& other) {
            return i != other.i || j != other.j;
        }

        decltype(&(baseGrid->rows[0][0])) operator->() {
            return &(baseGrid->rows)[i][j];
        }

        decltype(baseGrid->rows[0][0])& operator* () {
            return (baseGrid->rows)[i][j];
        }

        iterator left() {
            if (i > 0) {
                return {baseGrid, i - 1, j};
            }
            return baseGrid->end();
        }

        iterator right() {
            if (i + 1 < baseGrid->n) {
                return {baseGrid, i + 1, j};
            }
        }

        explicit operator bool() {
            return *this != baseGrid->end();
        }
    };

    size_t n;
    size_t m;

    std::vector<Row> rows;
    BaseGrid(size_t n)
            : n(n), rows(n)
    {}

    BaseGrid(size_t n, size_t m)
            : n(n), m(m), rows(n, Row(m))
    {}

    BaseGrid(size_t n, Row row)
            : n(n), m(row.size()), rows(n, row)
    {}

    decltype(rows[0][0])& operator() (int i, int j) {
        return rows[i][j];
    }

    iterator begin() {
        return {this, 0, 0};
    }

    iterator end() {
        return {this, n, 0};
    }

    Row& operator[](size_t i) {
        return rows[i];
    }
};


template <class T>
class Grid : public BaseGrid<std::vector<T>> {
public:
    Grid(size_t n, size_t m)
            : BaseGrid<std::vector<T>>(n, std::vector<T>(m))
    {}
};

template <>
class Grid <char> : public BaseGrid<std::string> {
public:
    Grid(size_t n)
            : BaseGrid(n)
    {}

    Grid(size_t n, std::istream& in)
            : BaseGrid(n)
    {
        for (size_t i = 0; i < n; ++i) {
            in >> rows[i];
        }
    }

    Grid(size_t n, size_t m, char value)
            : BaseGrid<std::string>(n, std::string(m, value))
    {}
};


namespace nt {
    int gcdExtended(int a, int b, int *x, int *y)
    {
        if (a == 0)
        {
            *x = 0;
            *y = 1;
            return b;
        }

        int x1, y1;
        int gcd = gcdExtended(b%a, a, &x1, &y1);

        *x = y1 - (b/a) * x1;
        *y = x1;

        return gcd;
    }
}

class rational {
public:
    int a, b;
    rational(): a(0), b(1) {}
    rational(int a, int b) : a(a), b(b) {}
    rational (const rational&) = default;

    rational operator=(int x) {
        a = x;
        b = 1;
        return *this;
    }

    rational operator=(const rational& other) {
        a = other.a;
        b = other.b;
        return *this;
    }

    rational operator+(const rational& other) const {
        rational sm;
        sm.a = a * other.b + b * other.a;
        sm.b = b * other.b;
        auto g = std::__gcd(abs(sm.a), abs(sm.b));
        sm.a /= g;
        sm.b /= g;
        return sm;
    }

    bool operator<(const rational& other) const {
        return a * other.b < other.a * b;
    }

    bool operator<=(const rational& other) const {
        return a * other.b <= other.a * b;
    }

    bool operator<=(int other) const {
         return a <= b * other;
    }
};


class mint {
public:
    int x;


    mint() : x(0) {}
    mint(int x) : x(x) {}
    mint(mint &other) : x(other.x) {}


    mint operator= (int other) {
        x = other;
        return *this;
    }

    bool operator == (const mint& other) {
        return x == other.x;
    }

    mint operator= (const mint& other) {
        x = other.x;
        return *this;
    }

    mint operator+(const mint& other) const {
        return (x + other.x) % MOD;
    }

    mint operator-(const mint& other) const {
        return (x + MOD - other.x) % MOD;
    }

    mint operator*(const mint& other) const {
        return (x * other.x) % MOD;
    }

    mint operator/(int denominator) {
        int f_mod;
        int f_denominator;
        nt::gcdExtended(denominator, MOD, &f_denominator, &f_mod);
        while (f_denominator < 0)
            f_denominator += MOD;
        return (f_denominator * x) % MOD;
    }

    mint operator/(const mint& denominator) {
        return (*this) / denominator.x;
    }

    mint operator^(unsigned long n) {
        mint a = x;
        mint res = 1;

        while (n > 0) {
            if (n & 1)
                res = res * a;
            n = n >> 1;
            a = a * a;
        }

        return res;
    }
};

template <typename T>
mint operator* (T x, const mint& y) {
    return mint(x) * y;
}

namespace nt {

    std::vector<mint> get_facts(int n) {
        std::vector<mint> fact(n);
        fact[0] = 1;
        fact[1] = 1;
        for (int i = 2; i < fact.size(); ++i) {
            fact[i] = (i * fact[i - 1]);
        }
        return fact;
    }

    std::map<int, int> get_canonical(int x, const std::vector<int>& sieve) {
        std::map<int, int> primes;

        while (x > 1) {
            const int& p = sieve[x];

            if (p > 1) {
                primes[p] += 1;
                x /= p;
            } else {
                primes[x] += 1;
                break;
            }
        }
        return primes;
    }

    std::map<int, int> get_canonical(int x, int* sieve) {
        std::map<int, int> primes;

        while (x > 1) {
            const int& p = sieve[x];

            if (p > 1) {
                primes[p] += 1;
                x /= p;
            } else {
                primes[x] += 1;
                break;
            }
        }
        return primes;
    }

    std::map<int, int> get_canonical(int x) {

        std::map<int, int> primes;

        for (int d = 2; d * d <= x; ++d) {
            while (x % d == 0) {
                x /= d;
                primes[d] += 1;
            }
        }

        if (x > 1) {
            primes[x] = 1;
        }
        return primes;
    }

    std::vector<int> get_divisors(int x, const std::map<int, int>& canonical) {

        std::vector<int> k(canonical.size(), 0);
        std::vector<int> primals(canonical.size(), 1);
        std::vector<std::pair<int, int>> powers(canonical.begin(), canonical.end());
        //for (auto& [p, l] : canonical) {
        //    powers.emplace_back(p, l);
        //}
        for (int i = 0; i < canonical.size(); ++i) {
            for (int j = 0; j < powers[i].second; ++j) {
                primals[i] *= powers[i].first;
            }
        }

        int number_of_divisors = 1;
        for (auto& [p, k] : powers) {
            number_of_divisors *= (1 + k);
        }

        std::vector<int> divisors(number_of_divisors);

        int divisor = 1;
        for (int i = 0; i < number_of_divisors; ++i) {

            divisors[i] = divisor;

            for (int j = 0; j < k.size(); ++j) {
                if (k[j] < powers[j].second) {
                    k[j] += 1;
                    divisor *= powers[j].first;
                    break;
                } else {
                    k[j] = 0;
                    divisor /= primals[j];
                }
            }
        }

        return divisors;
    }

    std::vector<int> get_divisors(int x, const std::vector<int>& sieve) {
        return get_divisors(x, get_canonical(x, sieve));
    }

    std::vector<int> get_divisors(int x, int* sieve) {
        return get_divisors(x, get_canonical(x, sieve));
    }

    std::vector<int> get_divisors(int x) {
        return get_divisors(x, get_canonical(x));
    }


    std::vector<int> sieve2(int N) {
        std::vector<int> primes(N+5, -1);
        for (int p = 2; p < primes.size(); ++p) {
            if (primes[p] == -1) {
                for (int i = p + p; i < primes.size(); i += p) {
                    if (primes[i] == -1) {
                        primes[i] = p;
                    }
                }
            }
        }
        return primes;
    }

    int* sieve(int N) {
        int MX = N - 1;
        //std::vector<int> s(MX+5, 0);
        int* s = new int[MX+5];
        for (int i = 0; i < MX+5; ++i)
            s[i] = 0;

        std::vector<int> primes;
        for(int i = 2; i <= MX; i++) {
            if(!s[i]) { s[i] = -1; primes.push_back(i); }
            for(int j : primes) {
                if(i * j > MX) break;
                s[i * j] = j;
                if(i % j == 0) break;
            }
        }
        return s;
    }





    template <typename T>
    int gcd(T x, T y) {
        uint64_t xx = x;
        uint64_t yy = y;
        return std::__gcd(xx, yy);
    }


}



using namespace std;
struct Solver {
void solve() {
    int t = 1;
    std::cin >> t;
    while (t--) solve_one();
}

void solve_one() {
    string s; cin >> s;
    s[0] = '('; s.back() = ')';

    int n = s.size() / 2;

    auto c = std::count(s.begin(), s.end(), ')');
    auto o = std::count(s.begin(), s.end(), '(');
    auto q = 2 * n - o - c;

    auto to_open = n - o;
    auto to_close = n - c;

    if (to_open == 0 or to_close == 0) {
        return YES();
    }

    auto repl = string(to_open - 1, '(') + ")(" + string(to_close - 1, ')');

    int t = 0;
    for (auto& x : s) {
        if (x == '?') {
            x = repl[t++];
        }
    }

    int p = 0;
    for (auto x : s) {
        if (x == '(') {
            p += 1;
        } else {
            p -= 1;
        }
        if (p < 0) {
            return YES();
        }
    }

    return NO();
    
}
};
#undef int

int main() {
    IO_FAST
    Solver().solve();
    return 0;
}