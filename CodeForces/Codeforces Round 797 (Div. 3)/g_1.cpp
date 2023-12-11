#include <bits/stdc++.h>
///#define int long long

using namespace std;

const int NMAX = 1e5 + 1;
const int INF = 2e9;

//ifstream fin( "div.in" );
//ofstream fout( "div.out" );

struct node {
    int minim;
    int l;
    int r;
    int lazy;
    int trains;
} aint[8 * NMAX + 1];

int v[NMAX + 1];
int initial[NMAX + 1];

void propag( int i ) {
    if ( aint[i].lazy != INF ) {
        aint[i * 2 + 1] = { aint[i].lazy, aint[i].lazy, aint[i].lazy, min( aint[i * 2 + 1].lazy, aint[i].lazy ), 1 };
        aint[i * 2 + 2] = { aint[i].lazy, aint[i].lazy, aint[i].lazy, min( aint[i * 2 + 1].lazy, aint[i].lazy ), 1 };
        aint[i].lazy = INF;
    }
}
void update( int st, int dr, int a, int b, int val, int i = 0 ) {
    propag( i );
    if ( st == a && dr == b ) {
        aint[i] = { val, val, val, min( val, aint[i].lazy ), 1 };
        return;
    }
    int mij = ( st + dr ) / 2;
    if ( b <= mij ) {
        update( st, mij, a, b, val, i * 2 + 1 );
    } else if ( a > mij ) {
        update( mij + 1, dr, a, b, val, i * 2 + 2 );
    } else {
        update( st, mij, a, mij, val, i * 2 + 1 );
        update( mij + 1, dr, mij + 1, b, val, i * 2 + 2 );
    }
    aint[i].minim = min( aint[i * 2 + 1].minim, aint[i * 2 + 2].minim );
    aint[i].trains = aint[i * 2 + 1].trains + aint[i * 2 + 2].trains - ( aint[i * 2 + 1].r == aint[i * 2 + 2].l );
    aint[i].l = aint[i * 2 + 1].l;
    aint[i].r = aint[i * 2 + 2].r;
}
int query( int st, int dr, int a, int b, int i = 0 ) {
    propag( i );
    if ( st == a && dr == b ) return aint[i].minim;
    int mij = ( st + dr ) / 2;
    if ( b <= mij ) return query( st, mij, a, b, i * 2 + 1 );
    if ( a > mij ) return query( mij + 1, dr, a, b, i * 2 + 2 );
    return min( query( st, mij, a, mij, i * 2 + 1 ),
                query( mij + 1, dr, mij + 1, b, i * 2 + 2 ) );

}
int max_node;

void build( int st, int dr, int i = 0 ) {
    if ( st == dr ) {
        aint[i] = { initial[st], initial[st], initial[dr], INF, 1 };
    } else {
        int mij = ( st + dr ) / 2;
        build( st, mij, i * 2 + 1 );
        build( mij + 1, dr, i * 2 + 2 );
        aint[i].minim = min( aint[i * 2 + 1].minim, aint[i * 2 + 2].minim );
        aint[i].trains = aint[i * 2 + 1].trains + aint[i * 2 + 2].trains - ( aint[i * 2 + 1].r == aint[i * 2 + 2].l );
        aint[i].l = aint[i * 2 + 1].l;
        aint[i].r = aint[i * 2 + 2].r;
        aint[i].lazy = INF;
    }
}
void solve() {
    int n, q, minim = INF;
    cin >> n >> q;
    for ( int i = 1; i <= n; i ++ ) {
        cin >> v[i];
        minim = min( minim, v[i] );
        initial[i] = minim;
    }
    build( 1, n );
    while ( q-- ) {
        int i, val;
        cin >> i >> val;
        v[i] -= val;
        if ( v[i] < query( 1, n, i, i ) ) {
            int st = i, dr = n + 1;
            while ( st < dr - 1 ) {
                int mij = ( st + dr ) / 2;
                if ( query( 1, n, i, mij ) >= v[i] )
                    st = mij;
                else {
                    dr = mij;
                }
            }
            update( 1, n, i, st, v[i] );
        }
        cout << aint[0].trains << ' ';
    }
    cout << '\n';
}

signed main() {
    ios_base::sync_with_stdio( false );
    cin.tie( NULL );
    int t = 1;
    cin >> t;
    while ( t-- ) solve();
}

