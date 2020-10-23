class Solution {
public:
    int findString(vector<string>& words, string s) {
        int left = 0, right = words.size() - 1;
        int mid = (left + right)/2;
        while (left <= right) {
            if (words[mid] == "") {
                mid++;
                if (mid > right) {
                    mid = (left + right)/2;
                    right = mid - 1;
                    mid = (left + right)/2;
                }
                continue;
            }
            if (words[mid] == s) {
                return mid;
            } else if (s > words[mid]) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
            mid = (left + right) /2;
        }
        return -1;
    }
};
