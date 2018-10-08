#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define ms(a,b) memset(a,b,sizeof(a))
using namespace std;
typedef long long ll;
const int maxn = 100000 + 5;
const ll inf = 1ll << 60;

int n;

int cmpd;
namespace kdt{
    int rt;
    struct node{
        int d[2], mx[2], mn[2], l, r; 
        int id;
        bool operator<(const node& b)const{
            if (d[cmpd] == b.d[cmpd]) return d[cmpd ^ 1] < b.d[cmpd ^ 1];
            return d[cmpd] < b.d[cmpd];
        }
    }tree[maxn];

    inline void pushup(int u, int v){
        node &a = tree[u], &b = tree[v];
        a.mx[0] = max(a.mx[0], b.mx[0]);
        a.mx[1] = max(a.mx[1], b.mx[1]);
        a.mn[0] = min(a.mn[0], b.mn[0]);
        a.mn[1] = min(a.mn[1], b.mn[1]);
    }
    inline int build(int l, int r, int k){
        int m = l + r >> 1; cmpd = k;
        nth_element(tree + l, tree + m, tree + r + 1);
        node& t = tree[m]; 
        t.l = t.r = 0;
        t.mx[0] = t.mn[0] = t.d[0];
        t.mx[1] = t.mn[1] = t.d[1];
        if (l != m){
            t.l = build(l, m - 1, k ^ 1);
            pushup(m, t.l);
        }
        if (r != m){
            t.r = build(m + 1, r, k ^ 1);
            pushup(m, t.r);
        }
        return m;
    }

    inline ll sqr(ll x){return x * x;} 
    inline ll distance(const node& a, ll x, ll y){
        x -= a.d[0]; y -= a.d[1];
        return x * x + y * y;
    }
    inline ll cal(const node& a, ll x, ll y){
        ll ans = 0;
        if (x < a.mn[0]) ans += sqr(a.mn[0] - x);
        if (x > a.mx[0]) ans += sqr(a.mx[0] - x);
        if (y < a.mn[1]) ans += sqr(a.mn[1] - y);
        if (y > a.mx[1]) ans += sqr(a.mx[1] - y);
        return ans;
    }

    ll ans, x, y;
    inline void query(int p){
        node& u = tree[p];
        ll d0 = distance(u, x, y), dl = inf, dr = inf;
        if (x == u.d[0] && y == u.d[1]) d0 = inf; //
        ans = min(ans, d0);
        if (u.l) dl = cal(tree[u.l], x, y);
        if (u.r) dr = cal(tree[u.r], x, y);
        if (dl < dr){
            if (dl < ans) query(u.l);
            if (dr < ans) query(u.r);
        }
        else {
            if (dr < ans) query(u.r);
            if (dl < ans) query(u.l);
        }
    }
}
using namespace kdt;

ll res[maxn];

int main(){
    int T; scanf("%d", &T);
    while (T--){
        scanf("%d", &n);
        for (int i = 1; i <= n; i++){
            scanf("%d%d", &tree[i].d[0], &tree[i].d[1]);
            tree[i].id = i;
        }
        rt = build(1, n, 0);
        for (int i = 1; i <= n; i++){
            ans = inf; x = tree[i].d[0]; y = tree[i].d[1];
            query(rt); res[tree[i].id] = ans;
        }
        for (int i = 1; i <= n; i++) printf("%lld\n", res[i]);
    }
    return 0;
}