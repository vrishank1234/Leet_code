class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int left = 0;  // Pointer for non-zero elements

        //iterating through the array using right pointer 
        for (int right = 0; right < nums.size(); ++right) {
            if (nums[right] != 0) {
                //swap non-zero element right with left 
                swap(nums[left], nums[right]);
                left++;  // Move the non-zero pointer forward
            }
        }
    }
};
