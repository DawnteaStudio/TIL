#include <iostream>
#include <string>

int main() {
    int t;
    std::cin >> t;

    while (t--) {
        int a;
        std::string b;
        std::cin >> a >> b;

        int sum = 0;
        for (char digit : b) {
            sum += digit - '0';
        }

        std::cout << a * sum << '\n';
    }
}