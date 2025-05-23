#include <iostream>
#include <string>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
using namespace std;
using ll = long long;
#include <cmath>
bool should_pad(ll x, ll y, ll z) {
    long double log_val = y * log10l(x) - log10l(z);
    ll digits = floorl(log_val) + 1;
    return digits >= 4;
}

// 거듭제곱 모듈러 계산: (a^b) % mod
ll mod_pow(ll base, ll exp, ll mod) {
    ll result = 1;
    base %= mod;
    while (exp) {
        if (exp & 1) result = result * base % mod;
        base = base * base % mod;
        exp >>= 1;
    }
    return result;
}

int main() {
    fast;
    int T;
    cin >> T;

    while (T--) {
        ll x, y, z;
        cin >> x >> y >> z;

        ll mod1 = z * 1000LL;
        ll val_mod = mod_pow(x, y, mod1);
        ll int_part = (val_mod / z) % 1000;

        // int_part formatting
        string f = to_string(int_part);
       if (should_pad(x, y, z) && f.length() < 3) {
            f = string(3 - f.length(), '0') + f;
        }

        // 소수부 계산: (X^Y % Z) 시뮬레이션
        ll rem = mod_pow(x, y, z);
        string b = "";
        for (int i = 0; i < 3; ++i) {
            rem *= 10;
            b += to_string(rem / z);
            rem %= z;
        }
        cout << f << "." << b << '\n';
    }
    return 0;
}
