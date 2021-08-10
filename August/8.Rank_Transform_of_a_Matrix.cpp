class Solution
{
public:
    int fun(int i, vector<int> &root)
    {
        if (root[i] == i)
            return i;
        return root[i] = fun(root[i], root);
    }
    vector<vector<int>> matrixRankTransform(vector<vector<int>> &matrix)
    {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<int> rankk(n + m, 0);
        map<int, vector<pair<int, int>>> element;
        vector<vector<int>> result(n, vector<int>(m));
        vector<int> current;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
                element[matrix[i][j]].push_back(make_pair(i, j));
        }

        for (auto iterator_ : element)
        {
            vector<int> root(n + m, 0);
            for (int i = 0; i < root.size(); i++)
            {
                root[i] = i;
            }
            for (auto it : iterator_.second)
            {
                int i = it.first;
                int j = it.second;
                int root_x = fun(i, root);
                int root_y = fun(j + n, root);
                root[root_x] = root_y;
                rankk[root_y] = max(rankk[root_x], rankk[root_y]);
            }
            current = rankk;
            for (auto it : iterator_.second)
            {
                int i = it.first;
                int j = it.second;
                int r = fun(i, root);
                result[i][j] = 1 + rankk[r];
                current[j + n] = rankk[r] + 1;
                current[i] = rankk[r] + 1;
            }
            swap(rankk, current);
        }
        return result;
    }
};