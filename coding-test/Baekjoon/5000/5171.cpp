#include <iostream>
#include <vector>
#include <string>
#include <climits>

#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

string readFingerprint() {
    string line, s;
    s.reserve(25);
    for (int i = 0; i < 5; i++) {
        cin >> line;
        s += line;
    }
    return s;
}

int distance25(const string& a, const string& b) {
    int d = 0;
    for (int i = 0; i < 25; i++) {
        if (a[i] != b[i]) d++;
    }
    return d;
}

int main() {
    fast;

    int n, K;
    cin >> n >> K;

    vector<string> db(n);
    for (int i = 0; i < n; i++) {
        db[i] = readFingerprint();
    }

    for (int caseNo = 1; caseNo <= K; caseNo++) {
        string crime = readFingerprint();

        int best = INT_MAX;
        vector<int> ans;

        for (int i = 0; i < n; i++) {
            int d = distance25(crime, db[i]);

            if (d < best) {
                best = d;
                ans.clear();
                ans.push_back(i + 1);
            } else if (d == best) {
                ans.push_back(i + 1);
            }
        }

        cout << "Data Set " << caseNo << ":\n";
        for (int i = 0; i < (int)ans.size(); i++) {
            if (i) cout << ' ';
            cout << ans[i];
        }
        cout << "\n\n";
    }

    return 0;
}
