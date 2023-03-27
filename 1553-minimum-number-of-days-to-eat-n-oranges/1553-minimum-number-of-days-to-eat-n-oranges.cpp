class Solution {
public:
    int inner(int n) {
        if (dp.find(n) != dp.end()) {
            return dp[n];
        }
        int result = INT_MAX;
		// from large partitions to small
        if (n % 3 == 0) result = min(result, inner(n/3));
        if (n % 2 == 0) result = min(result, inner(n/2));
		// we don't want to do this step as this is the most expensive 
		// we don't need to do this if number was divisible by both
        if (n % 3 != 0 || n% 2 != 0) result = min(result, inner(n-1));
        dp[n] = result + 1;
        return dp[n];
    }
public: 
    unordered_map<int, int> dp;
    int minDays(int n) {
        dp[0] = 0;
        dp[1] = 1;
        return inner(n);
    }
};