class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq;
        for(auto & i : stones)
        {
            pq.push(i);
        }
        while(pq.size()>1)
        {
            auto x = pq.top();pq.pop();
            auto y = pq.top();pq.pop();
            pq.push(x-y);
        }
        return pq.top();
    }
};
