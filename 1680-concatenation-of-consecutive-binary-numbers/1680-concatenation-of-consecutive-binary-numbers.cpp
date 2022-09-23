class Solution {
public:
    int concatenatedBinary(int n) {
        long sol=0, md = 1e9+7, length = 0;
        for (int i = 1; i <= n; ++i) {
            if ((i & (i - 1)) == 0) length++;
            sol = ((sol << length) + i) % md;
        }
        return sol;
    }
};