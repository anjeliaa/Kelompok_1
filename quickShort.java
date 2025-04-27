public class quickShort {
  public static void swap(int arr[], int i, int j){
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
  }
  public static int partisi(int arr[], int low, int high){
    int pivot = arr[high];
    int i = low -1;
    for(int j = low; j < high; j++){
      if(arr[j]<=pivot){
        i++;
        swap(arr, i, j);
      }
    }
    swap(arr, i+1, high);
    return(i +1);
  }
  public static void sort(int arr[],int low,int high){
    if(low < high){
      int sort = partisi(arr, low, high);
      sort(arr, low, sort-1);
      sort(arr,sort+1, high);
    }
  }
  public static void main(String[] args) {
    int data[] = {2,1,5,7,4};
    int n = data.length;
    sort(data, 0, n-1);
    for (int i = 0; i < n; i++) {
      System.out.print(data[i] + " ");
  }
  }
}
