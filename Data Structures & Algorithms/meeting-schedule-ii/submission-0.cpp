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
        vector<int> starts;
        vector<int> ends;

        for(const auto& interval : intervals) {
            starts.push_back(interval.start);
            ends.push_back(interval.end);
        }

        sort(starts.begin(), starts.end());
        sort(ends.begin(), ends.end());

        int idx_s = 0;
        int idx_e = 0;

        int max_meetings = 0;
        int curr_meetings = 0;

        while(idx_s < starts.size() && idx_e < ends.size()) {
            if (starts[idx_s] < ends[idx_e]) {
                curr_meetings++;
                max_meetings = max(max_meetings, curr_meetings);
                idx_s++;
            }
            else {
                curr_meetings--;
                idx_e++;
            }
        }

        return max_meetings;
    }
};
