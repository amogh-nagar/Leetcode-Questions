class Solution {
    vector<vector<int>> ans;

    void permute(vector<int> &nums, int index) {
        if (index == nums.size()) {
            ans.push_back(nums);
            return;
        }

        unordered_set<int> s;
        for (int i = index; i < nums.size(); i++) {
            if (s.find(nums[i]) != s.end())    continue;
            s.insert(nums[i]);
            swap(nums[index], nums[i]);
            permute(nums, index + 1);
            swap(nums[index], nums[i]);
        }
    }

public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        permute(nums, 0);
        return ans;
    }
};