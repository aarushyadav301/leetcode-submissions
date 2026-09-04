/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
#include <vector>
#include <queue>
#include <iostream>
#include <cmath>
using namespace std;
class Solution {
public:
    int minDiffInBST(TreeNode* root) {
        vector <int> values = {};
        queue <TreeNode*> que = {};
        que.push(root);

        //cout << que.size() << endl;

        while (que.empty() == false) {
            TreeNode* cur = que.front();
            //cout << cur->val << endl;
            que.pop();
            values.push_back(cur->val);

            //cout << cur->left << " " << cur->right << endl;

            if (cur->left != nullptr) {
                que.push(cur->left);
            }
            if (cur->right != nullptr) {
                que.push(cur->right);
            }
        }

        //cout << values.size() << endl;

        sort(values.begin(), values.end());
        int answer = INT_MAX;

        for (int i = 1; i < values.size(); i++) {
            //cout << values[i] << endl;
            answer = min(answer, values[i] - values[i - 1]);
        }

        return (answer);
    }
};