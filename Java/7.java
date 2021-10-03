/*
Cyclically rotate an array by one

Given an array, rotate the array by one position in clock-wise direction.
*/
import java.util.Arrays;
public class Main
{
	public static void rotate(int arr[], int n)
    {
        int x=arr[n-1]; 
        for(int i=n-1; i>0; i--) 
            arr[i]=arr[i-1];  
        arr[0]=x; 
    }
	public static void main(String[] args) {
		int n=5;
		int[] arr = new int[] {1, 2, 3, 4, 5};
		rotate(arr,n);
		System.out.println(Arrays.toString(arr));
	}
}
