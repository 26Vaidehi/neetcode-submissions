class Solution {
public:
    set<vector<int>> result;
    void solve(vector<int>& nums, int i, vector<int>& temp){
        //base case
        if(i>=nums.size()){ //if index goes out of bounds
            result.insert(temp);
            return;
        }
        //take ith index element
        temp.push_back(nums[i]);
        solve(nums,i+1,temp);
        //not take ith index element
        temp.pop_back();
        solve(nums,i+1,temp);
        
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> temp;
        solve(nums,0,temp);
        return vector<vector<int>>(result.begin(), result.end());
    }
};
