#include <iostream>
#include <vector>
#include <algorithm>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

struct Skill {
    int damage;
    int duration;
};

int main() {
    fast;

    int N, M;
    cin >> N >> M;

    vector<Skill> skills(N);

    for (int i = 0; i < N; i++) {
        cin >> skills[i].damage >> skills[i].duration;
    }

    sort(skills.begin(), skills.end(), [](const Skill& a, const Skill& b) {
        if (a.damage != b.damage) {
            return a.damage > b.damage;
        }
        return a.duration > b.duration;
    });

    int maxDamage = 0;
    int holdTime = 1e9;

    for (int i = 0; i < M; i++) {
        maxDamage += skills[i].damage;
        holdTime = min(holdTime, skills[i].duration);
    }

    cout << maxDamage << ' ' << holdTime << '\n';
}