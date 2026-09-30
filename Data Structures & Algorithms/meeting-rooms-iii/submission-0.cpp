class Solution {
public:
    struct Room {
        int lastEndTime = 0;
        int meetings = 0;
    };

    int findNextFreeRoom(map<int, Room>& rooms) {
        int lowest_free_time = rooms[0].lastEndTime;
        int i = 0;

        for (auto& [idx, room] : rooms) {
            if (room.lastEndTime < lowest_free_time) {
                i = idx;
                lowest_free_time = room.lastEndTime;
            }
        }

        return i;
    }

    void addToRoom(int start, int end, map<int, Room>& rooms) {        
        for (auto& [idx, room] : rooms) {
            if (start >= room.lastEndTime) {                
                room.lastEndTime = end;
                room.meetings++;
                return;                
            }
        }
        
        int roomIdx = findNextFreeRoom(rooms);
        int duration = end - start;
        rooms[roomIdx].lastEndTime += duration;
        rooms[roomIdx].meetings++;
        return;
    }

    int mostBooked(int n, vector<vector<int>>& meetings) {
        sort(meetings.begin(), meetings.end(), [](vector<int> a, vector<int>b) {
            return a[0] < b[0];
        });

        map<int, Room> rooms;

        for (int i = 0; i < n; i++) {
            rooms[i] = {0, 0};
        }        

        for (vector<int> meeting : meetings) {
            int start = meeting[0];
            int end = meeting[1];

            addToRoom(start, end, rooms);
        }

        int most_booked_idx = 0;
        int number_of_meetings = 0;
        for (auto& [idx, room] : rooms) {
            if (room.meetings > number_of_meetings) {
                most_booked_idx = idx;
                number_of_meetings = room.meetings;
            }
        }

        return most_booked_idx;
    }
};