// C++ Solution

class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n = nums.size();
     //   stack<int> st;
        unordered_set<int> st;
        vector<pair<int,int>> vec;
        for(int i=0;i<n;i++){
            vec.push_back({nums[i],i});
        }
        sort(vec.begin(), vec.end());
        for(int i = 0; i < n; i++){
            if(st.find(i) != st.end()) continue;
            set<int> hlp;
            int j=i;
            hlp.insert(vec[i].second);
             st.insert(i);
            while(i+1<n && vec[i+1].first <= vec[i].first + limit){
                i++;
                st.insert(i);
                hlp.insert(vec[i].second);
            }
            for(auto it:hlp){
              nums[it] = vec[j++].first;
            }
        }
    return nums;
    }
};
