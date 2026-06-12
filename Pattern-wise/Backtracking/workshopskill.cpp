#include <bits/stdc++.h>
using namespace std;
int time1 = 0;
int maxskill = 0;
int skill = 0;
void rec(vector<pair<int, int>> slots, int level, int x, int count, int k, int n) {
	if(time1 == x && count==k) {
		if(skill > maxskill) {
			maxskill = skill;
		}
		return;
	}
	if(level==n || time1 > x || count > k) {
		return;
	}
	time1 += slots[level].first;
	skill += slots[level].second;
	count++;
	rec(slots, level + 1, x, count + 1, k, n);
    time1 -= slots[level].first;
    skill -= slots[level].second;
    rec(slots, level + 1, x, count, k, n);
}

int main()
{
	vector<pair<int, int>> slots;
	int n;
	cin >> n;
	for(int i=0; i<n; i++) {
		int t, s;
		cin >> t >> s;
		pair<int, int> slot = {t, s};
		slots.push_back(slot);
	}
	int x, k;
	cin >> x >> k;
	rec(slots, 0, x, 0, k, n);
	cout << maxskill << endl;

	return 0;
}

/* 
VG Dada's code ->
#include <bits/stdc++.h>
using namespace std;

int n;
int t[1001];
int s[1001];
int x, k;

int taken[1001];

bool check(int level)
{
    int timetaken = 0;
    int itemtaken = 0;

    for(int i = 0; i < level; i++)
    {
        if(taken[i])
        {
            timetaken += t[i];
            itemtaken++;
        }
    }

    // Assume we take current workshop
    timetaken += t[level];
    itemtaken++;

    if(timetaken <= x && itemtaken <= k)
    {
        return true;
    }

    return false;
}

int rec(int level)
{
    // Base case
    if(level == n)
    {
        return 0;
    }

    // Choice 1: don't take
    int ans = rec(level + 1);

    // Choice 2: take
    if(check(level))
    {
        // place change
        taken[level] = 1;

        // move
        ans = max(ans,
                  s[level] + rec(level + 1));

        // revert
        taken[level] = 0;
    }

    return ans;
}

int main()
{
    cin >> n;

    for(int i = 0; i < n; i++)
    {
        cin >> t[i] >> s[i];
    }

    cin >> x >> k;

    cout << rec(0) << endl;
}

*/