#include <iostream>
#include <string>
#include <vector>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

void    make_deck(vector<string> &deck)
{
    string suit;
    vector<string> special = {"Jack", "Queen", "King", "Ace"};
    for (int i = 0; i < 4; i++)
    {
        switch (i)
        {
            case 0:
                suit = " of Clubs";
                break;
            case 1:
                suit = " of Diamonds";
                break;
            case 2:
                suit = " of Hearts";
                break;
            case 3:
                suit = " of Spades";
                break;          
            default:
                break;
        }
        for (int j = 2; j <= 10; j++)
            deck.push_back(to_string(j) + suit);
        for (int j = 0; j < 4; j++)
            deck.push_back(special[j] + suit);
    }
}

void    print_deck(vector<string> &deck, vector<int> &k)
{
    int input;
    string tmp;
    vector<bool> visited(52, false);
    for (int i = 0; i < 52; i++)
    {
        if (i != k[i] - 1 && visited[i] == false)
        {
            visited[k[i] - 1] = true;
            tmp = deck[i];
            deck[i] = deck[k[i] - 1];
            deck[k[i] - 1] = tmp;
        }
    }
    for (int i = 0; i < 52; i++)
        cout << deck[i] << '\n';
}

int main()
{
    fast;
    vector<string> deck;
    make_deck(deck);

    int n;
    cin >> n;
    vector<vector<int> > shuf(n, vector<int>(52));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 52; j++)
            cin >> shuf[i][j];
    }
    int k;
    for (int i = 0; cin >> k; i++)
    {
        if (i)
            cout << '\n';
        print_deck(deck, shuf[k - 1]);
    }
}
