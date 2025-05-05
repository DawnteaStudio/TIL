#include <map>
#include <string>
#include <iostream>
using namespace std;

int ft_isnum(char c)
{
    if (c >= '0' && c <= '9')
        return (1);
    return (0);    
}

int find_key(map<int, string> pokemon, string value)
{
    int res;
    for(auto it = pokemon.begin(); it != pokemon.end();it++)
    {
        if (it->second == value)
        {
            res = it->first;
            return (res);
        }
    }
    return(0);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int pokemons, quiz;
    string name;
    map<int, string> pokemon;
	map<string, int> pokemon2;
    cin >> pokemons >> quiz;
    for (int i = 1; i <= pokemons; i++)
    {
        cin >> name;
        pokemon.insert(pair<int, string>(i, name));
        pokemon2.insert(pair<string, int>(name, i));
    }
    for (int i = 0; i < quiz; i++)
    {
        cin >> name;
        if (ft_isnum(name[0]) == 1)
            cout << pokemon[stoi(name)] << '\n';
        else
            cout << pokemon2[name] << '\n';
    }
}
