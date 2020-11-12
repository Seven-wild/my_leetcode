class Solution {
public:
    int *next;
    void get_next(const string &p) {
        next = new int[p.length() + 1];
        int j = next[0] = -1;
        for (int i = 1; i < p.length(); i++) {
            while (p[i] != p[j + 1] && j >= 0) {
                j = next[j];
            }
            if (p[j + 1] == p[i]) {
                j++;
            }
            next[i] = j;
        }
    }
    int match(const string &p, const string &b) {
        if (p.length() == 0) return 0;
         for (int i = 0, j = -1; i < b.length(); i++) {
            while (b[i] != p[j + 1] && j >= 0) {
                j = next[j];
            }
            if (b[i] == p[j + 1]) {
                j++;
            }
            if (j == p.length() - 1) {
                return i - j; 
            }
        }
        return -1;
    }
    int strStr(string haystack, string needle) {
        get_next(needle);
        return match(needle, haystack);
    }
};
