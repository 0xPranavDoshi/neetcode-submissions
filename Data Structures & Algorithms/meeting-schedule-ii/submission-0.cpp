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
        int n = intervals.size();

        vector<pair<int,int>> ints;

        for (Interval i : intervals) {
            ints.push_back({i.start, i.end});        
        }

        sort(ints.begin(), ints.end());

        int meeting_rooms = 0;
        unordered_map<int, int> lastEndTimes;

        for (int i = 0; i < n; i++) {
            int start_time = ints[i].first;
            int end_time = ints[i].second;

            int room_found = 0;
            for (const auto& [room, lastEndTime] : lastEndTimes) {                
                if (start_time >= lastEndTime) {
                    room_found = 1;
                    lastEndTimes[room] = end_time;
                    break;
                }
            }

            if (room_found == 0) {
                // Create new room.
                meeting_rooms++;
                lastEndTimes[meeting_rooms] = end_time;
            }
        }

        return meeting_rooms;
    }
};
