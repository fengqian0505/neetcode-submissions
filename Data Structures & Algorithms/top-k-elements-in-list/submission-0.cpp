class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> num_map; // num -> freq map

        for(auto num : nums) {
            num_map[num]++;
        }

        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        
        for(const auto& [num, freq] : num_map) {
            pq.push({freq, num});
            if (pq.size() > k) {
                pq.pop();
            }
        }

        vector<int> result;
        while(!pq.empty()) {
            result.push_back(pq.top().second);
            pq.pop();
        }

        return result;
    }
};