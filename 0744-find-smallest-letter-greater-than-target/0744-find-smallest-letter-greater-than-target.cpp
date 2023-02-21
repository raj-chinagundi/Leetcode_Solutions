class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int n=letters.size();
        int start = 0, end = n - 1, mid;
        char res = '0';

        while (start <= end) {
            mid = start + (end - start) / 2;
            if (letters[mid] > target) {
                res = letters[mid];
                end = mid - 1;
            }
            else {
                start = mid + 1;
            }
        }
        return (res=='0')?letters[0]:res;
    }
};