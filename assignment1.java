//shell sort in java

import java.util.Scanner;
public class ShellSort {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        System.out.println("Enter the size of array:");
        int size = scanner.nextInt();

        int[] arr = new int[size];

        System.out.println("Enter the elements to sort:");
        for(int i=0; i<size; i++){
            arr[i] = scanner.nextInt();
        }
        ShellSort(arr);
        System.out.println("Array after sort:");
        for(int i=0; i<size; i++){
            System.out.print(arr[i] + " ");
        }
    scanner.close();
}

public static void shellSort(int[] arr){
    int n = arr.length;
    for(int gap = n/2 ; gap > 0 ; gap/=2){
        for(int i=gap ; i<n ; i++){
            int temp = arr[i];
            int j;
            for(j=i;j>=gap && arr[j-gap]>temp; j-=gap){
                arr[j] = arr[j-gap];
            }
            arr[j] = temp;
        }
    }
}
}

