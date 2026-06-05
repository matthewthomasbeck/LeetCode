class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {

        unordered_map<int, int> seen; // make storage hash map to put numbers
        
        for (int i = 0; i < nums.size(); i++) { // loop through nums

            if (seen.count(nums[i])) { // if num has been seen before

                return true; // return true that number has been seen
            }

            seen[nums[i]] = i; // add number to the hash map
        }

        return false; // return false if not seen
    }
};
