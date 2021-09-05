class Solution {
	int n;
	vector<list<int>> AdjacencyList;
	vector<int> Size, nums, res;

    void DFS_SECOND(int Node, int par, int dpnums) {
		res[Node] = nums[Node] + dpnums + (n - Size[Node]);

		for (int child : AdjacencyList[Node]) {
			if (child != par)
				DFS_SECOND(child, Node, res[Node] - nums[child] - Size[child]);
		}
	}  

	void DFS_FIRST(int Node, int par) {

		for (int child : AdjacencyList[Node]) {
			if (child != par) {
				DFS_FIRST(child, Node);
				Size[Node] += Size[child];
				nums[Node] += nums[child] + Size[child];
			}
		}
		Size[Node]++;
	}

    
public:
	vector<int> sumOfDistancesInTree(int N, vector<vector<int>>& edges) {
		n = N;
		AdjacencyList.resize(n), Size.resize(n), nums.resize(n), res.resize(n);
		for (vector<int> &v : edges) {
			AdjacencyList[v[0]].push_back(v[1]);
			AdjacencyList[v[1]].push_back(v[0]);
		}
		DFS_FIRST(0, 0);
		DFS_SECOND(0, 0, 0);
		return res;
	}
};