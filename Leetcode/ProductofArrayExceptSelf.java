class Solution {
    public int[] productExceptSelf(int[] nums) {
        int []prefix = new int[nums.length];
        int []suffix = new int[nums.length];
        int sumPrefix = 1;
        int sumSuffix = 1;

        for (int i = 0; i < nums.length; i++) {

            prefix[i] = sumPrefix;
            suffix[nums.length - i - 1] = sumSuffix;
            sumPrefix *= nums[i];
            sumSuffix *= nums[nums.length - i - 1];
        }
        for (int i = 0; i < nums.length; i++) {
            nums[i] = prefix[i] * suffix[i];
        }
        return nums;
    }
}