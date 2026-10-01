class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        priority_queue<int> pq;
        vector<int> sc(26,0);
        for(auto & i : tasks)
        {
            sc[i-'A']++;
        } 
        for(int i=0;i<26;i++)
        {
            if(sc[i])
                pq.push(sc[i]);
        }
        // remaining_count, time
        queue<pair<int,int>> q;
        int time=0;
        while(!pq.empty() || !q.empty())
        {

            time++;
            if(!pq.empty())
            {
                int count = pq.top()-1;
                if(count>0)
                {
                    q.push({count,time+n});
                }
                pq.pop();
            }
            if(!q.empty() && q.front().second<=time)
            {
                pq.push(q.front().first);
                q.pop();
            }
        }
        return time;
    }
};
