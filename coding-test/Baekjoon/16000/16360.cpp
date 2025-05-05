#include <iostream>
#include <string>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

string changeString(string str)
{
    int size = (int)str.size();
    string front = str.substr(0, size - 1);
    string back = str.substr(size - 1);

    if (back == "a") return front + "as";
    else if (back == "i" || back == "y") return front + "ios";
    else if (back == "l") return front + "les";
    else if (back == "n") return front + "anes";
    else if (back == "o") return front + "os";
    else if (back == "r") return front + "res";
    else if (back == "t") return front + "tas";
    else if (back == "u") return front + "us";
    else if (back == "v") return front + "ves";
    else if (back == "w") return front + "was";

    if (str.substr(size - 2) == "ne") {
        front = str.substr(0, size - 2);
        return front + "anes";
    }
    else return str + "us";
}

int main()
{
    fast;
    int n; cin >> n;

    string str;
    for (int i=0; i<n; i++) {
        cin >> str;
        cout << changeString(str) << '\n';
    }
    return (0);
}