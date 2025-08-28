#include <iostream>

#define MAX_T 1000000

using namespace std;

int n, m;
int pos_a[MAX_T + 1], pos_b[MAX_T + 1];

int main() {
    // 입력
    cin >> n >> m;
    
    // A가 매 초마다 서있는 위치를 기록
    int time_a = 1;
    for(int i = 0; i < n; i++) {
        int v, t;
        cin >> v >> t;
        
        while(t--) {
            pos_a[time_a] = pos_a[time_a - 1] + v;
            time_a++;
        }
    }
    
    // B가 매 초마다 서있는 위치를 기록
    int time_b = 1;
    for(int i = 0; i < m; i++) {
        int v, t;
        cin >> v >> t;
        
        while(t--) {
            pos_b[time_b] = pos_b[time_b - 1] + v;
            time_b++;
        }
    }
    
    // A와 B 중 더 앞서 있는 경우를 확인합니다.
    // A가 리더면 1, B가 리더면 2로 관리합니다.
    int leader = 0, ans = 0;
    for(int i = 1; i < time_a; i++) {
        if(pos_a[i] > pos_b[i]) {
            // 기존 리더가 B였다면
            // 답을 갱신합니다.
            if(leader == 2)
                ans++;
            
            // 리더를 A로 변경합니다.
            leader = 1; 
        }
        else if(pos_a[i] < pos_b[i]) {
            // 기존 리더가 A였다면
            // 답을 갱신합니다.
            if(leader == 1)
                ans++;
            
            // 리더를 B로 변경합니다.
            leader = 2; 
        }
    }
    
    cout << ans;
    return 0;
}
