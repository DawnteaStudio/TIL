#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

struct Event {
    int start;
    int end;
};

int toMinutes(const string& t) {
    int hour = (t[0] - '0') * 10 + (t[1] - '0');
    int minute = (t[3] - '0') * 10 + (t[4] - '0');
    return hour * 60 + minute;
}

bool cmp(const Event& a, const Event& b) {
    if (a.start == b.start) return a.end < b.end;
    return a.start < b.start;
}


int main() {
    fast;

    while (true) {
        int N;
        cin >> N;

        if (N == 0)
			break;

        vector<Event> events;

        for (int i = 0; i < N; i++) {
            string s;
            cin >> s;

            string startStr = s.substr(0, 5);
            string endStr = s.substr(6, 5);

            int start = toMinutes(startStr);
            int end = toMinutes(endStr);

            events.push_back({start, end});
        }

        sort(events.begin(), events.end(), cmp);

        bool conflict = false;
        for (int i = 1; i < N; i++) {
            if (events[i].start < events[i - 1].end) {
                conflict = true;
                break;
            }
        }

        if (conflict) cout << "conflict\n";
        else cout << "no conflict\n";
    }
}
