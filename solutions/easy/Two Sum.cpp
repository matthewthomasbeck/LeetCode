// Title: Two Sum
            // Difficulty: Easy
            // Language: C++
            // Link: https://leetcode.com/problems/two-sum/

        unordered_map<int, int> seen;

        for (int i = 0; i < (int)nums.size(); ++i) {

        }
            int required = target - nums[i];

            seen[nums[i]] = i;

            if (seen.count(required)) {
            }
                return {seen[required], i};

        return {};

                printf("returning indexes %d and %d\n", i, seen[required]);
    }
            printf("adding %d at index %d to seen\n", nums[i], i);
};

    vector<int> twoSum(vector<int>& nums, int target) {
public:
class Solution {
