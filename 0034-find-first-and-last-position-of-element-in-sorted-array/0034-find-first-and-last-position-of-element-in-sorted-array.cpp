class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> result(2, -1);
        result[0] = findIndex(nums, target, true);
        result[1] = findIndex(nums, target, false);
        return result;
    }

private:
    int findIndex(vector<int>& nums, int target, bool leftB) {
        int left = 0, right = nums.size() - 1;
        int index = -1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] > target || (leftB && nums[mid] == target)) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
            if (nums[mid] == target) index = mid;
        }
        return index;
    }
};