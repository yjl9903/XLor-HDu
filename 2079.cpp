#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#define ms(a,b) memset(a,b,sizeof(a))
using namespace std;
typedef long long ll;
const int maxn = 100 + 5;

int n, k, a[maxn], b[maxn], c1[maxn], c2[maxn];

int main(){
    int T; cin >> T;
    while (T--){
        cin >> n >> k;
        for (int i = 0; i < k; i++) cin >> a[i] >> b[i];
        ms(c1, 0); ms(c2, 0); c1[0] = 1;
        for (int i = 0; i < k; i++){
            for (int j = 0; j <= a[i] * b[i] && j <= n; j += a[i]){
                for (int k = 0; k + j <= n; k++){
                    c2[k + j] += c1[k];
                }
            }
            for (int j = 0; j <= n; j++) c1[j] = c2[j], c2[j] = 0;
        }
        cout << c1[n] << endl;
    }
    return 0;
}