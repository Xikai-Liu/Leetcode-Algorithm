class Solution {
public:
    vector< vector<int> > threeSum(vector<int>& nums) {

        vector< vector<int> > output;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i++) {
            if (i != 0 && nums[i] == nums[i - 1]) continue;
            set<int> seen;
            for (int j = i + 1; j < nums.size(); j++) {
                if (seen.count(-nums[i] - nums[j])) {
                    output.push_back({nums[i], nums[j], -nums[i] - nums[j]});
                    while ((j + 1 < nums.size())&&(nums[j+1]==nums[j])) j++;
                }
                seen.insert(nums[j]);
            }
        }
        return output;
    }
};