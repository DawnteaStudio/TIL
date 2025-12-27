#include <iostream>
#include <unordered_map>
#include <string>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    const std::unordered_map<int, std::string> mp = {
        {1995, "ITMO"},
        {1996, "SPbSU"},
        {1997, "SPbSU"},
        {1998, "ITMO"},
        {1999, "ITMO"},
        {2000, "SPbSU"},
        {2001, "ITMO"},
        {2002, "ITMO"},
        {2003, "ITMO"},
        {2004, "ITMO"},
        {2005, "ITMO"},
        {2006, "PetrSU, ITMO"},
        {2007, "SPbSU"},
        {2008, "SPbSU"},
        {2009, "ITMO"},
        {2010, "ITMO"},
        {2011, "ITMO"},
        {2012, "ITMO"},
        {2013, "SPbSU"},
        {2014, "ITMO"},
        {2015, "ITMO"},
        {2016, "ITMO"},
        {2017, "ITMO"},
        {2018, "SPbSU"},
        {2019, "ITMO"},
    };

    int year;
    while (std::cin >> year) {
        auto it = mp.find(year);
        if (it != mp.end()) std::cout << it->second << "\n";
        else std::cout << "Unknown\n";
    }
}
