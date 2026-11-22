class Solution {
public:
    long long maximumCoins(vector<vector<int>>& coins, int k) {

        /* step 0 initialize / preset all values */
        
        // sort the coin hotspots so they are mapped onto one 'coins' line
        // instead of using their fractured state
        sort(coins.begin(), coins.end());

        // find the total len of coins line now that it is sorted
        int lenCoins = coins.size();

        // make a pefix array to find total coins in each segment;
        // this helps us find the total amount of coins in each segment
        // without needing to loop, reads from pos L + 1 through R
        vector<long long> pref(lenCoins + 1, 0); // len of coins, 0 coins each pos

        for (int i = 0; i < lenCoins; i++) { // loop through entire len of coins

            // find length of coin filled segment
            // example: where coins[0] = [8, 10, 1], below would do:
            // lenSeg = 10 - 8 + 1 for a total length of the segment being
            // 3, counting pos 8 pos 9 pos 10 so length indeed 3
            long long lenSeg = long long coins[i][1] - coins[i][0] + 1;

            // find total coins in segment via len * coins per pos
            // example: where coins[0] = [8, 10, 1] and lenSeg = 3,
            // pref = 3 * 1, so values at pos 8 9 and 10 are filled with 3
            // without needing to brute force loop;
            // we would end up with (0,0,0,0,0,0,0,0,3,3,3)
            pref[i + 1] = pref[i] + lenSeg * coins[i][2];
        }

        // initialize answer as 0
        long long answer = 0;

        /* step 1 */
        
    }
};
