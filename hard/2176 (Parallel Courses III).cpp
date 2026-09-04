#include <unordered_set>
#include <queue>

class Solution {
public:
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        vector<vector<int>> adjacency(n);
        vector<int> inDegree(n);
        queue<int> queue;

        for (int i = 0; i < relations.size(); i++) {
            int f = relations[i][0] - 1;
            int s = relations[i][1] - 1;
            inDegree[s]++;
            adjacency[f].push_back(s);
        }

        vector<int> maxTime(n);

        for (int i = 0; i < n; i++) {
            if (!inDegree[i]) {
                queue.push(i);
                maxTime[i] = time[i];
            }
        }

        while (!queue.empty()) {
            int curNode = queue.front();
            queue.pop();

            vector<int> children = adjacency[curNode];
            for (int i = 0; i < children.size(); i++) {
                inDegree[children[i]]--;
                maxTime[children[i]] = max(maxTime[children[i]], maxTime[curNode] + time[children[i]]);
                if (!inDegree[children[i]]) {
                    queue.push(children[i]);
                }
            }
        }

        int longest = 0;
        for (int i = 0; i < n; i++) {
            longest = max(longest, maxTime[i]);
        }

        return (longest);
    }
};