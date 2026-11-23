// Title: Best Time to Buy and Sell Stock
            // Difficulty: Easy
            // Language: C++
            // Link: https://leetcode.com/problems/best-time-to-buy-and-sell-stock/



        for (int i = 1; i < prices.size(); ++i) {
        // loop len of prices, starting at index 1 as the first value is already seen as

        // then return the index + 1 
        int minPrice = prices[0]; // preinitialize current lowest as first index
        int maxPrice = 0;
        // 'lowest'
            if (prices[i] < minPrice) {

            }
                minPrice = prices[i];
            // if current prices value lower than lowest seen
                // set current prices value as lowest seen
        // the max value delta as 6 - 1 > 5 - 1, and then finally, note that 6 - 1 > 4 - 1 and
        // move on as 5 - 1 > 3 - 1, note that the value after that is even higher anc change
        // that value, note that the next index after that whose value is 3 is also higher but
        // is less than 7, note that the next index whose value is 5 is higher and then save
        // for exmaple, in the array above, we would start at 7, move on, drop 7 because 1
        //
        //
        // then I should do another pass to find values that meet 2 criteria:
        // 1. they must be higher in value
        // 2. they must be a higher index than the current value being looked at
        //
        // if we know that a previous number is higher, we should probably drop it,
        // if there are multiple higher values later on in the chain, we should choose the
        // max difference that is the highest
        //
        // I think that I should first start by doing one pass to find the lowest value,
        // saving the value as well as its index
