#include <bits/stdc++.h>
using namespace std;

int dp[101][1001][101];

int rec(vector<pair<int, int>> slots,
        int level,
        int time1,
        int skill,
        int count,
        int x,
        int k,
        int n)
{
    if(time1 == x && count == k)
    {
        return skill;
    }

    if(level == n || time1 > x || count > k)
    {
        return 0;
    }

    if(dp[level][time1][count] != -1)
    {
        return dp[level][time1][count];
    }

    int take =
    rec(slots,
        level + 1,
        time1 + slots[level].first,
        skill + slots[level].second,
        count + 1,
        x,
        k,
        n);

    int nottake =
    rec(slots,
        level + 1,
        time1,
        skill,
        count,
        x,
        k,
        n);

    if(take > nottake)
    {
        dp[level][time1][count] = take;
    }
    else
    {
        dp[level][time1][count] = nottake;
    }

    return dp[level][time1][count];
}

int main()
{
    vector<pair<int, int>> slots;

    int n;
    cin >> n;

    for(int i = 0; i < n; i++)
    {
        int t, s;
        cin >> t >> s;
        slots.push_back({t, s});
    }

    int x, k;
    cin >> x >> k;

    memset(dp, -1, sizeof(dp));

    cout << rec(slots, 0, 0, 0, 0, x, k, n);

    return 0;
}