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
    int minMeetingRooms(vector<Interval>& intervals) {
        sort(intervals.begin(), intervals.end(), [](Interval a, Interval b) {
            return a.start < b.start;
        });

        priority_queue<int, vector<int>, greater<int>> rooms;     
        rooms.push(INT_MAX);

        for (Interval i : intervals) {
            if (i.start < rooms.top()) {
                rooms.push(i.end);
            } else {
                rooms.pop();
                rooms.push(i.end);
            }
        }

        return rooms.size() - 1;
    }
};
