#include <iostream>
#include <string>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main() {
	fast;
    
    string tmp;
    while (true) {
        int a = 0, b = 0;
        cin >> tmp;
        if (tmp == "#")
            break;
        int len = tmp.length();

        int s_a = 0, s_b = 0;
		
		for (int i = 0; i < len; i++) {
			if (tmp[i] == 'A')
				s_a++;
			else
				s_b++;

			if ((s_a >= 4 || s_b >= 4) && abs(s_a - s_b) >= 2) {
				if (s_a > s_b)
					a++;
				else
					b++;
				s_a = s_b = 0;
			}
		}

		cout << "A " << a << " B " << b << '\n';
	}
}
