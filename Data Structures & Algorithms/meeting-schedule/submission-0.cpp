/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    bool canAttendMeetings(vector<Interval>& intervals) {
        int n = intervals.size();

        vector<pair<int, int>> ints;

        for (Interval i : intervals) {
            ints.push_back({i.start, i.end});
        }

        sort(ints.begin(), ints.end());

        for (int i = 1; i < n; i++) {
            if (ints[i].first < ints[i-1].second) {
                return false;
            }
        }

        return true;
    }
};
