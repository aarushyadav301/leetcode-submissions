using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        int lastWorkingMiddle = nums.size() - 1;

        while (left <= right) {
            int middle = (left + right + 1) / 2;

            if (nums[middle] < nums[nums.size() - 1]) {
                lastWorkingMiddle = middle;
                right = middle - 1;
            }
            else {
                left = middle + 1;
            }
        }

        lastWorkingMiddle--;

        auto l = lower_bound(nums.begin(), nums.begin() + lastWorkingMiddle + 1, target);
        auto r = lower_bound(nums.begin() + lastWorkingMiddle + 1, nums.end(), target);
        size_t l_dist = distance(nums.begin(), l);
        size_t r_dist = distance(nums.begin(), r);
        
        if (l_dist < nums.size() && nums[l_dist] == target) {
            return (l_dist);
        }
        if (r_dist < nums.size() && nums[r_dist] == target) {
            return (r_dist);
        }
        return (-1);
    }
};