class Solution{

    // arr: input array
    // n: size of array
    //Function to find the sum of contiguous subarray with maximum sum.
    int maxSubarraySum(int arr[], int n){
        
        // Your code here
        int local_max = arr[0];
        int global_max = arr[0];
        for(int i = 1; i<n; i++)
        {
            local_max = Math.max(arr[i], local_max + arr[i]);
            global_max = Math.max(global_max, local_max);
        }
        return global_max;
        
    }
    
}
