class Solution {
public:
    int compareVersion(string version1, string version2) {
        int n1 = version1.size(), n2 = version2.size();
        int i = 0, j = 0;
        while (i < n1 || j < n2) {
            int r1 = 0, r2 = 0;
            while (i < n1 && version1[i] != '.') {
                r1 = r1 * 10 - '0' + version1[i++];
            }
            while (j < n2 && version2[j] != '.') {
                r2 = r2 * 10 - '0' + version2[j++];
            }
            if (r1 < r2) return -1;
            if (r1 > r2) return 1;
            i++, j++;
        }
        return 0;
    }
};
