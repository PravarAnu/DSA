// #include <iostream>
// using namespace std;

// void mergeSort(int a[], int low, int high);
// void merge(int a[], int lowLeft, int highLeft ,int highRight);
// void printArr(int a[], int size);

// int main(){
//     int n;
//     int a[] = {3,2,4,1,6,5,9,8,7};
//     n = sizeof(a)/sizeof(a[0]);

//     mergeSort(a,0,n-1);
//     printArr(a,n-1);

//     return 0;
// }

// void mergeSort(int a[], int low, int high){
//     if(low >= high){
//         return ;
//     }
//     else{
//         int mid = (low + high)/2;
//         mergeSort(a,low,mid);
//         mergeSort(a,mid+1,high);
//         merge(a,low,mid,high);
//     }
// }

// void merge(int a[], int lowLeft, int highLeft ,int highRight){
//     int lowRight,size;
//     int iLeft,iRight,iRes;
//     int *mergedArr;
//     int i,iArr;

//     lowRight = highLeft + 1;
//     size = highRight - lowLeft;
//     mergedArr = new int[size];

//     iLeft = lowLeft;
//     iRight = lowRight;
//     iRes = 0;

//     while(iLeft <= highLeft && iRight <= highRight){
//         if(a[iLeft]<a[iRight]){
//             mergedArr[iRes] = a[iLeft];
//             iLeft++;
//             iRes++;
//         }
//         else{
//             mergedArr[iRes] = a[iRight];
//             iRight++;
//             iRes++;
//         }
//     }

//     while(iLeft <= highLeft){
//         mergedArr[iRes] = a[iLeft];
//         iLeft++;
//         iRes++;
//     }
//     while(iRight <= highRight){
//         mergedArr[iRes] = a[iRight];
//         iRight++;
//         iRes++;
//     }

//     for(i=0,iArr=lowLeft;i<=size;i++,iArr++){
//         a[iArr] = mergedArr[i];
//     }

//     delete []mergedArr;
// }

// void printArr(int a[], int size){
//     for(int i=0; i<=size; i++){
//         cout<<a[i]<<" ";
//     }
// }

#include <iostream>
using namespace std;

void mergeTwoSortedArray(int a[], int low, int mid, int high)
{
    int iStart = low;
    int iEnd = mid;

    int jStart = mid + 1;
    int jEnd = high;

    int *mergeArr = new int[high - low + 1];
    int index = 0;

    while (iStart <= iEnd && jStart <= jEnd)
    {
        if (a[iStart] <= a[jStart])
        {
            // cout<<a[iStart]<<" ";
            mergeArr[index] = a[iStart];
            iStart++;
            index++;
        }
        else
        {
            // cout<<a[jStart]<<" ";
            mergeArr[index] = a[jStart];
            jStart++;
            index++;
        }
    }

    while (iStart <= iEnd)
    {
        // cout<<a[iStart]<<" ";
        mergeArr[index] = a[iStart];
        iStart++;
        index++;
    }

    while (jStart <= jEnd)
    {
        // cout<<a[jStart]<<" ";
        mergeArr[index] = a[jStart];
        jStart++;
        index++;
    }

    // cout<<endl;

    // for(int i=0; i<(high-low+1); i++){
    //   cout<<mergeArr[i]<<" ";
    // }
    int newIndex = 0;
    for (int i = low; i <= high; i++)
    {
        a[i] = mergeArr[newIndex];
        newIndex++;
    }
    delete[] mergeArr;
}

void mergeSort(int arr[], int l, int r)
{
    if (r > l)
    {
        int mid = l + (r - l) / 2;
        mergeSort(arr, l, mid);
        mergeSort(arr, mid + 1, r);
        mergeTwoSortedArray(arr, l, mid, r);
    }
}

int main()
{
    int arr[10] = {3, 2, 4, 1, 6, 5, 9, 8, 7, 6};

    mergeSort(arr, 0, 9);

    for (int i = 0; i < 10; i++)
    {
        cout << arr[i] << " ";
    }
    // mergeTwoSortedArray(arr, 0 , 3, 9);

    return 0;
}
