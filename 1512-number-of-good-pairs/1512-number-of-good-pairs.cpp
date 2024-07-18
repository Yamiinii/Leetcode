class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        //no space
    int total_count = 0;
        int same_count = 0;
        int curr_num = -1;
        std::sort(nums.begin(),nums.end());
        
        for(int i = 0 ; i < nums.size(); i++){
            if(curr_num!=nums[i]){
                curr_num = nums[i];
                same_count = 0;
            }else{
                total_count += same_count + 1;
                same_count += 1;
            }
        }
        return total_count; 

        // best solution

//         unordered_map<int,int>umap;
//         for(auto num:nums){
//             umap[num] += 1;
//         }
//         int total_count = 0;
//         for(auto ans:umap){
//             total_count += (ans.second*(ans.second-1))/2;
//             //to choose from n identical items nc2 is the way i.e. n(n-1)/2
//         }
//         return total_count;
    }
};