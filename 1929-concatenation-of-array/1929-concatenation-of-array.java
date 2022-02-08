class Solution {
    public int[] getConcatenation(int[] nums) { 
        int l=nums.length;
        int[] t=new int[2*l];
        for(int i=0;i<l;i++){
            t[i]=nums[i];
        }
        for(int i=0;i<l;i++){
            t[i+l]=nums[i];
        }
        return t;
    }
}