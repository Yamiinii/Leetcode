class Solution {
    public int[] twoSum(int[] nums, int target) {
        int n=nums.length;
        Map<Integer,Integer> mpp=new HashMap<>();
        for(int i=0;i<n;i++)
        {
            int num1=nums[i];
            int num2=target-num1;

            if(mpp.containsKey(num2))
            return new int[] {i,mpp.get(num2)};

            mpp.put(num1,i);
        }

        return new int[] {-1,-1};
    }
}