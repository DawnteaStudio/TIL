#include <iostream>
#include <vector>

using namespace std;

void change(vector<double> v) {
    for (double &elem : v)
        cin >> elem;
}

int main() {
    // Declare a vector of ten numbers
    std::vector<double> vec(4, 5);
    // Allow the user to populate the vector
    std::cout << "Please enter 10 numbers: ";

    // Print the vector's contents
    for (double elem : vec)
        std::cout << elem << '\n';
    change(vec);

    for (double elem : vec)
        cout << elem << '\n';    
    
}