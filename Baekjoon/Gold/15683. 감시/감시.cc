#include <iostream>
#include <vector>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int N, M, cnt, ans;
int arr[8][8] = {-1};
vector<pair<int, int>> cctv;

void    check_all_cctv(int arr[8][8], vector<pair<int, int>> v, int depth);

void    arr_clear(int tmp[][8], int arr[][8])
{
	for (int i = 0; i < N; i++)
    {
		for (int j = 0; j < M; j++)
			tmp[i][j] = arr[i][j];
	}
}

void    up(int arr[8][8], int y, int x)
{
    if (y - 1 < 0)
        return ;
    for (int i = y - 1; i >= 0; i--)
    {
        if (arr[i][x] == 6)
            break;
        if (arr[i][x] == 0)
            arr[i][x] = 7;
    }
}

void    down(int arr[8][8], int y, int x)
{
    if (y + 1 >= N)
        return ;
    for (int i = y + 1; i < N; i++)
    {
        if (arr[i][x] == 6)
            break;
        if (arr[i][x] == 0)
            arr[i][x] = 7;
    }
}

void    left(int arr[8][8], int y, int x)
{
    if (x - 1 < 0)
        return ;    
    for (int i = x - 1; i >= 0; i--)
    {
        if (arr[y][i] == 6)
            break;
        if (arr[y][i] == 0)
            arr[y][i] = 7;
    }
}

void    right(int arr[8][8], int y, int x)
{
    if (x + 1 >= M)
        return ;
    for (int i = x + 1; i < M; i++)
    {
        if (arr[y][i] == 6)
            break;
        if (arr[y][i] == 0)
            arr[y][i] = 7;
    }
}

void    cctv_1(int arr[8][8], int y, int x, int depth)
{
    int tmp[8][8];
    arr_clear(tmp, arr);
    up(tmp, y, x);
    check_all_cctv(tmp, cctv, depth+1);

    arr_clear(tmp, arr);
    down(tmp, y, x);
    check_all_cctv(tmp, cctv, depth+1);

    arr_clear(tmp, arr);
    left(tmp, y, x);
    check_all_cctv(tmp, cctv, depth+1);

    arr_clear(tmp, arr);
    right(tmp, y, x);
    check_all_cctv(tmp, cctv, depth+1);
}

void    cctv_2(int arr[8][8], int y, int x, int depth)
{
    int tmp[8][8];

    arr_clear(tmp, arr);
    up(tmp, y, x);
    down(tmp, y, x);
    check_all_cctv(tmp, cctv, depth+1);

    arr_clear(tmp, arr);
    left(tmp, y, x);
    right(tmp, y, x);
    check_all_cctv(tmp, cctv, depth+1);
}

void    cctv_3(int arr[8][8], int y, int x, int depth)
{
    int tmp[8][8];

    arr_clear(tmp, arr);
    up(tmp, y, x);
    right(tmp, y, x);
    check_all_cctv(tmp, cctv, depth+1);

    arr_clear(tmp, arr);
    right(tmp, y, x);
    down(tmp, y, x);
    check_all_cctv(tmp, cctv, depth+1);

    arr_clear(tmp, arr);
    down(tmp, y, x);
    left(tmp, y, x);
    check_all_cctv(tmp, cctv, depth+1);

    arr_clear(tmp, arr);
    left(tmp, y, x);
    up(tmp, y, x);
    check_all_cctv(tmp, cctv, depth+1);
}

void    cctv_4(int arr[8][8], int y, int x, int depth)
{
    int tmp[8][8];

    arr_clear(tmp, arr);
    left(tmp, y, x);
    up(tmp, y, x);
    right(tmp, y, x);
    check_all_cctv(tmp, cctv, depth+1);

    arr_clear(tmp, arr);
    up(tmp, y, x);
    right(tmp, y, x);
    down(tmp, y, x);
    check_all_cctv(tmp, cctv, depth+1);

    arr_clear(tmp, arr);
    right(tmp, y, x);
    down(tmp, y, x);
    left(tmp, y, x);
    check_all_cctv(tmp, cctv, depth+1);

    arr_clear(tmp, arr);
    down(tmp, y, x);
    left(tmp, y, x);
    up(tmp, y, x);
    check_all_cctv(tmp, cctv, depth+1);
}

void    cctv_5(int arr[8][8], int y, int x, int depth)
{
    int tmp[8][8];

    arr_clear(tmp, arr);
    up(tmp, y, x);
    down(tmp, y, x);
    left(tmp, y, x);
    right(tmp, y, x);
    check_all_cctv(tmp, cctv, depth+1);
}

void    check_all_cctv(int arr[8][8], vector<pair<int, int>> v, int depth)
{
    int cctv;
    int tmp = 0;
    
    if (depth == cnt)
    {
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < M; j++)
            {
                if (arr[i][j] == 0)
                    tmp++;
            }
        }
        if (ans > tmp)
            ans = tmp;
        return ;
    }

    int cctv_y = v[depth].first;
    int cctv_x = v[depth].second;

    cctv = arr[cctv_y][cctv_x];
    switch (cctv)
    {
        case 1:
            cctv_1(arr, cctv_y, cctv_x, depth);
            break;
        case 2:
            cctv_2(arr, cctv_y, cctv_x, depth);
            break;
        case 3:
            cctv_3(arr, cctv_y, cctv_x, depth);
            break;
        case 4:
            cctv_4(arr, cctv_y, cctv_x, depth);
            break;
        case 5:
            cctv_5(arr, cctv_y, cctv_x, depth);
            break;            
        default:
            break;
        }
}

int main()
{
    fast;
    cin >> N >> M;
    ans = N * M;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> arr[i][j];
            if (arr[i][j] > 0  && arr[i][j] < 6)
            {
                cctv.push_back({i, j});
                cnt++;
            }
        }
    }
    check_all_cctv(arr, cctv, 0);
    cout << ans;
}