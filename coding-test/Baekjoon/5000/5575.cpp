#include <iostream>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main()
{
    fast;
    int h_s, m_s, s_s;
    int h_e, m_e, s_e;
    int h, m ,s;

    for (int i = 0; i < 3; i++)
    {
        cin >> h_s >> m_s >> s_s >> h_e >> m_e >> s_e;
        if (s_e < s_s)
        {
            s = 60 + s_e - s_s;
            m_e--;
            if (m_e < 0)
            {
                m_e = 59;
                h_e--;
            }
        }
        else
            s = s_e - s_s;
        if (m_e < m_s)
        {
            m = 60 + m_e - m_s;
            h_e--;
        }
        else
            m = m_e - m_s;
        h = h_e - h_s;
        cout << h << ' ' << m << ' ' << s << '\n';
    }
}