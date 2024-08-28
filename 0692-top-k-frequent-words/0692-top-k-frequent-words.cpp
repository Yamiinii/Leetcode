class Solution {
public:
    class compare{
        public:
      bool operator()(const pair<int,string>& a,const pair<int,string> &b)
      {
          if(a.first==b.first)
              return a.second>b.second;
          
          return a.first<b.first;
      }
    };
    
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string,int> mpp;
        vector<string>v;
        for(auto it:words)
        {
            mpp[it]++;
        }
        priority_queue<pair<int,string>,vector<pair<int,string>>,compare> pq;
        for(auto it:mpp)
        {
            pq.push({it.second,it.first});
        }
        while(k-- && !pq.empty())
        {
            v.push_back(pq.top().second);
            pq.pop();
        }
        return v;
    }
};