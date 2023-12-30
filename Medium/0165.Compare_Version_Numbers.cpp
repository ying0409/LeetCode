class Solution {
public:
    int compareVersion(string version1, string version2) {
        int v1_now = 0;
        int v2_now = 0;
        while(version1[v1_now] != '\0' || version2[v2_now] != '\0') {
            int v1 = 0;
            int v2 = 0;
            while(version1[v1_now] != '.' && version1[v1_now] != '\0') {
                v1 *= 10;
                v1 += version1[v1_now] - '0';
                v1_now ++;
            }
            if(version1[v1_now] != '\0') v1_now ++;
            while(version2[v2_now] != '.' && version2[v2_now] != '\0') {
                v2 *= 10;
                v2 += version2[v2_now] - '0';
                v2_now ++;
            }
            if(version2[v2_now] != '\0') v2_now ++;
            if(v1 > v2) return 1;
            else if(v1 < v2) return -1;
        }
        return 0;
    }
};