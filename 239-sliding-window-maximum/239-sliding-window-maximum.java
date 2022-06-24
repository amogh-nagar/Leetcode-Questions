class Solution {
    public int[] maxSlidingWindow(int[] nums, int k) {
        Deque<Integer> dq=new LinkedList<Integer>();
        List<Integer> res=new ArrayList<Integer>();
        for(int i=0;i<nums.length;i++){
           
            if(!dq.isEmpty() && i-k+1>dq.peekFirst()){
                dq.removeFirst();
            }
           
                while(!dq.isEmpty() && nums[dq.peekLast()]<nums[i]){
                    dq.removeLast();
                }
                dq.addLast(i);
            
            if(i>=k-1)
            res.add(nums[dq.peekFirst()]);
        }
        int[] arr = res.stream().mapToInt(i -> i).toArray();
        return arr;
    }
}