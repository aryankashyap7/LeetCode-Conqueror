class Solution {

  public int pivotIndex(int[] nums) {
    int left_sum = 0;
    int right_sum = 0;
    int flag = 0;
    int val = 0;
    for (int i = 0; i < nums.length; i++) {
      for (int j = 0; j < i; j++) {
        left_sum += nums[j];
      }
      for (int k = i+1; k < nums.length; k++) {
        right_sum += nums[k];
      }
      if (left_sum == right_sum) {
        val = i;
        flag = 1;
        break;
      }
        
        // System.out.println(right_sum+" "+left_sum);
        left_sum=0;
        right_sum=0;
    }
    if (flag != 0) {
      return val;
    } else {
      return -1;
    }
  }
}
