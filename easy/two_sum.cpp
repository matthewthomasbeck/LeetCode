class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

        unordered_map <int, int> seen; // hash map where number = its index
        
        for (int i = 0; i < nums.size(); i++) {

            int neededNum = target - nums[i]; // needed number is desired num - current num

            if (seen.count(neededNum)) { // has there been neededNum seen before?

                return {seen[neededNum], i}; // return index of current and needed num if so
            }

            seen[nums[i]] = i; // if not, store number and index for later
        }

        return {}; // return nothing if number never shows up
    }
};
