class Solution {
public:
    bool check(int level, int i, vector<int> col) {
        for (int j = 0; j < level; j++) {
            if (col[j] == i) {
                return false;
            }
            if (abs(col[j] - i) == abs(j - level)) {
                return false;
            }
        }
        return true;
    }

    string createPattern(int i, int n) {
        string str = "";

        for (int j = 1; j <= n; j++) {
            if (j == i)
                str += "Q";
            else
                str += ".";
        }
        return str;
    }

    void rec(int level,
             int n,
             vector<int> col,
             vector<vector<int>>& ans) {
        if (level == n) {
            ans.push_back(col);
            return;
        }
        for (int i = 1; i <= n; i++) {

            if (check(level, i, col)) {

                col[level] = i;

                rec(level + 1, n, col, ans);
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<int>> ans;
        vector<int> col(n, 0);
        rec(0, n, col, ans);
        vector<vector<string>> solutions;
        for (auto sol : ans) {
            vector<string> board;
            for (int i = 0; i < sol.size(); i++) {
                board.push_back(createPattern(sol[i], n));
            }
            solutions.push_back(board);
        }
        return solutions;
    }
};