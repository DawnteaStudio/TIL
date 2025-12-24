#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

static const unordered_map<char, string> CHAR_TO_MORSE = {
    {'A', ".-"},   {'B', "-..."}, {'C', "-.-."}, {'D', "-.."},  {'E', "."},
    {'F', "..-."}, {'G', "--."},  {'H', "...."}, {'I', ".."},   {'J', ".---"},
    {'K', "-.-"},  {'L', ".-.."}, {'M', "--"},   {'N', "-."},   {'O', "---"},
    {'P', ".--."}, {'Q', "--.-"}, {'R', ".-."},  {'S', "..."},  {'T', "-"},
    {'U', "..-"},  {'V', "...-"}, {'W', ".--"},  {'X', "-..-"}, {'Y', "-.--"},
    {'Z', "--.."},
    {'_', "..--"}, {'.', "---."}, {',', ".-.-"}, {'?', "----"},
};

static const unordered_map<string, char> MORSE_TO_CHAR = {
    {".-", 'A'},   {"-...", 'B'}, {"-.-.", 'C'}, {"-..", 'D'},  {".", 'E'},
    {"..-.", 'F'}, {"--.", 'G'},  {"....", 'H'}, {"..", 'I'},   {".---", 'J'},
    {"-.-", 'K'},  {".-..", 'L'}, {"--", 'M'},   {"-.", 'N'},   {"---", 'O'},
    {".--.", 'P'}, {"--.-", 'Q'}, {".-.", 'R'},  {"...", 'S'},  {"-", 'T'},
    {"..-", 'U'},  {"...-", 'V'}, {".--", 'W'},  {"-..-", 'X'}, {"-.--", 'Y'},
    {"--..", 'Z'},
    {"..--", '_'}, {"---.", '.'}, {".-.-", ','}, {"----", '?'},
};

int main()
{
	fast;
	int n;
	cin >> n;
	string tmp, decode_nums, res, mos;

	for (int i = 1; i <= n; i++) {
		decode_nums = "";
		res = "";
		mos = "";
		cin >> tmp;

		int len = tmp.length();
		for (int j = 0; j < len; j++) {
			mos += CHAR_TO_MORSE.at(tmp[j]);
			decode_nums += to_string(CHAR_TO_MORSE.at(tmp[j]).size());
		}
		reverse(decode_nums.begin(), decode_nums.end());
		int d_len = decode_nums.length();

		for (int j = 0; j < len; j++) {
			int cnt = decode_nums[j] - '0';
			res += MORSE_TO_CHAR.at(mos.substr(0, cnt));
			mos = mos.substr(cnt);
		}
		cout << i << ": " << res << '\n';
	}
}
