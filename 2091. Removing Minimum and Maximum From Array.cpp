// C++ Solution

class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        // remove both from back or remove both from front or remove 1 from front other from back .
        int n=nums.size();
        int maxi = INT_MIN, mini= INT_MAX;
        int maxidx=-1, minidx=-1;
        for(int i=0;i<n;i++){
      if(maxi < nums[i]){
        maxidx=i;
        maxi=nums[i];
      }
      if(mini > nums[i]){
        minidx = i;
        mini=nums[i];
      }
        }
        cout<<minidx << " "<< maxidx<<"\n";
        int ans=n;
         ans = min(ans,max(minidx+1, maxidx+1));
        ans = min(ans, max(n-minidx, n-maxidx));
        ans = min(ans, minidx +1 + n - maxidx);
        ans = min(ans, maxidx + 1 + n - minidx);
        return ans;
    }
};
