406. Queue Reconstruction by Height

Tc---> O(n ^ 2)

->Sort the people array according to ascending order of height (p[0])
-> If heights same sort acc to asc order of no of people having more or equal height (p[1])
-> Search the position to insert with thwe help of count

(TECHDOSE)


class Solution {
public:
    static bool comp(vector<int> &p1, vector<int> &p2) {
        if (p1 != p2)
            return p1[0] < p2[0];

        return p1[1] < p2[1];
    }
    vector<vector<int>> reconstructQueue(vector<vector<int>>& p) {
        sort(p.begin(), p.end(), comp);
        int n = p.size();
        vector<vector<int>> res(n, vector<int>(2, -1));

        int count = 0;
        for (int i = 0; i < n; i++) {
            count = p[i][1];
            for (int j = 0; j < n; j++) {
                if (res[j][0] == -1 and count == 0) {
                    res[j] = p[i];
                    break;
                }
                else if (res[j][0] == -1 or res[j][0] >= p[i][0])
                    count--;
            }
        }
        return res;
    }
};