class Solution {
public:
    long long maximumCoins(vector<vector<int>>& coins, int k) {

        /* STEP 0 initialize / preset all values */
        
        // sort the coin hotspots so they are mapped onto one 'coins' line
        // instead of using their fractured state
        sort(coins.begin(), coins.end());

        // find the total len of coins line now that it is sorted
        int lenCoins = coins.size();

        // make a pefix array to find total coins in each segment;
        // this helps us find the total amount of coins in each segment
        // without needing to loop, reads from pos L + 1 through R
        //
        // IMPORTANT: we use long long for all of the values because an int would
        // be WAYYYY too small in the case that we have billions of values
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
            // we would end up with (0,3) at end of loop
            //
            // IMPORTANT: we end up with a leading 0; we multiply instead of
            // visiting each bag to get the total coins in a segment
            // THIS IS THE IMPORTANT PART because it means we can save time
            // by using what we know about the first bag in a segment to then
            // understand the rest in the segment
            //
            // pref ends up being [0, 6, 14, 17]
            pref[i + 1] = pref[i] + lenSeg * coins[i][2];
        }

        // initialize answer as 0
        long long answer = 0;

        /* STEP 1 construct a rolling window starting left */
        
        // we now know the total coins in all segments from the previous loop
        // now we need to decide which window of len k captures as many coins as
        // possible

        // this is the current index of the segment that is to the left of our
        // travelling window (of length k)
        int left = 0;

        // preinitialize a right variablestarting from 0, keep looping while
        // right is less than the total length of the coin line; we use ++right
        // because if we did right++, we would have to make a copy of the old value
        // of right and then add 1 to it, wereas ++right just adds 1 to the right
        // we already have
        for (int right = 0; right < lenCoins; ++right) {

            // what this basically does is it finds the end of the window (we use
            // long long because values could be in the billions) in a coins segment
            // by looking at the termanating value of that segment.
            // for example, if coins[0] = [8, 10, 1] then windowEnd = 10
            long long windowEnd = coins[right][1];

            // using the example above, we then take the windowEnd value of 10 and
            // find the start of the segment by doing 10 - k (in this case, k = 4)
            // + 1 to then give us a a starting position of the window on the coins
            // line at 7; the window would then encompass positions 7, 8, 9, and 10,
            // 4 positions in total
            long long windowStart = windowEnd - k + 1;

            // this while loop is meant to drop every segment that ends before the
            // window starts; it looks at the start of the window and if the
            // terminating value of the segment to the left is less than the start
            // segment of our window, the segment is then dropped and we move on to
            // the next segment
            while (left <= right && coins[left][1] < windowStart)

                // this adds 1 to left while the conditions above are true so that we
                // can move to the next valid segment
                ++left;

            // preinitialize the current sum of the coins in the window as 0
            long long currentSum = 0;

            // this is be beginning point of the window
            long long from = max(windowStart, (long long)coins[left][0]);

            // this is the end point of the window
            long long to = coins[left][1];

            // calculate the current sum of coins between the beginning and end points
            currentSum += (to - from + 1) * (long long)coins[left][2];

            // TODO
            if (left + 1 <= right)

                // TODO
                currentSum += pref[right + 1] - pref[left + 1];

            // if the currentSum is greater than the previous answer, let answer be
            // the currentSum
            answer = max(answer, currentSum);
        }

        // dont forget to return
        return answer;
    }
};
