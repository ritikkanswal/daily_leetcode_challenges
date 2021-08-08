class Solution {
public:
    int minCut(string s) {
    int n,res;
    n = s.size();
    int i, j;

    vector<int> arr(n + 1, 0);
    for (int i = 0; i <= n; i++)
        arr[i] = i - 1;

    for (int z = 0; z < n; z++)
    {
        for (i = z, j = z;; i--, j++)
        {
            if (i >= 0 && j < n && s[i] == s[j])
                arr[j + 1] = min(arr[j + 1], arr[i] + 1);
            else
                break;
        }

        for (i = z - 1, j = z;; i--, j++)
        {
            if (i >= 0 && j < n && s[i] == s[j])
                arr[j + 1] = min(arr[j + 1], arr[i] + 1);
            else
                break;
        }
    }
        
    res = arr[n];
    return res;
    }
};