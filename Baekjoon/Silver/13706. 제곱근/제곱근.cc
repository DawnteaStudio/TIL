#include <algorithm>
#include <cassert>
#include <iostream>
#include <string>
using namespace std;
inline string add(string const &a, string const &b) {
    if(max(a.size(), b.size()) <= 15) return to_string(stoll(a) + stoll(b));
    string res;
    decltype(res.size()) idx = 0;
    int c = 0;
    while(idx < a.size() && idx < b.size()) {
        int const x = c + (a[a.size() - 1 - idx] + b[b.size() - 1 - idx] - 2 * '0');
        res.push_back((char)(x % 10 + '0'));
        c = x / 10; idx++;
    }
    while(idx < a.size()) {
        int const x = c + (a[a.size() - 1 - idx] - '0');
        res.push_back((char)(x % 10 + '0'));
        c = x / 10; idx++;
    }
    while(idx < b.size()) {
        int const x = c + (b[b.size() - 1 - idx] - '0');
        res.push_back((char)(x % 10 + '0'));
        c = x / 10; idx++;
    }
    if(c) res.push_back('1');
    reverse(res.begin(), res.end());
    return res;
}
inline string sub(string const &a, string const &b) {
    if(b == "0") return a;
    string res;
    int c = 0;
    decltype(res.size()) idx = 0;
    while(idx < b.size()) {
        int x = a[a.size() - 1 - idx] - b[b.size() - 1 - idx] - c;
        if(x < 0) x += 10, c = 1;
        else c = 0;
        res.push_back((char)(x + '0'));
        idx++;
    }
    while(idx < a.size()) {
        int x = a[a.size() - 1 - idx] - '0' - c;
        if(x < 0) x += 10, c = 1;
        else c = 0;
        res.push_back((char)(x + '0'));
        idx++;
    } assert(!c);
    while(!res.empty() && res.back() == '0') res.pop_back();
    reverse(res.begin(), res.end());
    return res;
}
inline string clean(string const &s) {
    decltype(s.size()) idx = 0;
    while(idx < s.size() && s[idx] == '0') idx++;
    if(idx == s.size()) return "0";
    return s.substr(idx);
}
string mul(string const &a) {
    if(a.size() <= 8) return to_string(stoll(a) * stoll(a));
    auto const m = a.size() >> 1;
    string const a1 = a.substr(0, a.size() - m);
    string const a2 = clean(a.substr(a.size() - m));
    string const F = mul(a1);
    string const G = mul(a2);
    string const x = add(a1, a2);
    string const H = mul(x);
    return sub(add(F + string(m << 1, '0'), add(H + string(m, '0'), G)), add(F, G) + string(m, '0'));
}
inline string div2(string const &n) {
    if(n.size() < 15) return to_string(stoll(n) >> 1);
    string res;
    int c = ((n[0] - '0') & 1) * 10;
    if(n[0] != '1') res.push_back((char)(((n[0] - '0') >> 1) + '0'));
    for(decltype(n.size()) i = 1; i < n.size(); i++) {
        int const x = n[i] - '0' + c;
        res.push_back((char)((x >> 1) + '0'));
        c = (x & 1) * 10;
    } return res;
}
inline bool gt(string const &a, string const &b) {
    if(b.size() > a.size()) return true;
    if(b.size() < a.size()) return false;
    for(decltype(a.size()) i = 0; i < a.size(); i++) {
        if(a[i] < b[i]) return true;
        if(b[i] < a[i]) return false;
    } return false;
}
inline string sqrt(string const &n) {
    string l = "0";
    string r = (n.size() > 5 ? n.substr(0, n.size() / 2 + 1) : add(n, "1"));
    while(l != r) {
        string m = div2(add(l, r));
        string const m2 = mul(m);
        if(m2 == n) return m;
        if(gt(m2, n)) l = add(m, "1");
        else r = m;
    } return l;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    string n; cin >> n; cout << sqrt(n);
}