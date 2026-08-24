class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> prevs;
        vector<int> ans;
        for (int i = 0; i < nums.size(); i++) {
            if (prevs.count(target - nums[i])) {
                ans.push_back(prevs[target - nums[i]]);
                ans.push_back(i);
                break;
            }
            prevs[nums[i]] = i;
        }
        return (ans);
    }
};