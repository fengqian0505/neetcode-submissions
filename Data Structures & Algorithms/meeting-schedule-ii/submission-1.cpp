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
    static bool cmp(pair<int, int> e1, pair<int, int> e2) {
        if (e1.first == e2.first) {
            return e1.second < e2.second;
        }
        else {
            return e1.first < e2.first;
        }
    }

    int minMeetingRooms(vector<Interval>& intervals) {
        vector<pair<int, int>> events;
        for(const auto& interval : intervals) {
            events.push_back({interval.start, 1});
            events.push_back({interval.end, -1});
        }

        sort(events.begin(), events.end(), cmp);

        int max_meetings = 0;
        int curr_meetings = 0;
        for(const auto& e : events) {
            curr_meetings += e.second;
            max_meetings = max(max_meetings, curr_meetings);
        }

        return max_meetings;
    }
};
