#include "basicSort.cpp"

class AdvancedSort : public Basic_Sort{
    public :
        AdvancedSort(int size);
        ~AdvancedSort(){};
        void mergeSort();
        void quickSort();
        // method for merge sort
    private :
        void merge(int left, int right);
        void mergeSort(int left, int right);

        // method for quick sort
        int partition(int left, int right);;
        void quickSort(int left, int right);
};
AdvancedSort::AdvancedSort(int size)
:Basic_Sort(size)
{
    int *p = getArray_address();
    cout << "@@ check array @@" << endl;
#if 0
    for(int i=0; i<getArrSize(); i++)
        cout << p[i] << ' ';
    cout << endl;
#endif
}
void AdvancedSort::mergeSort(int left, int right){
    if(left >= right)
        return;
    int mid = (left + right) /2;
    mergeSort(left, mid);
    mergeSort(mid+1, right);
    merge(left, right);
}
void AdvancedSort::merge(int left, int right){
    int *arrayAddress = getArray_address();
    int mid = (left + right) / 2;
    int left_buffer[mid-left + 1];
    int right_buffer[right - mid];
    int i, j, k=left;
    for(i=left, j=0; i<=mid; i++, j++)
        left_buffer[j] = arrayAddress[i];
    for(i=mid+1, j=0; i<=right; i++, j++)
        right_buffer[j] = arrayAddress[i];
    
    for(i=0, j=0; i < mid - left + 1 && j < right - mid ; ){
        if(left_buffer[i] < right_buffer[j])
            arrayAddress[k++] = left_buffer[i++];
        else
            arrayAddress[k++] = right_buffer[j++]; 
    }
    if(i >= mid - left +1)
        while(j < right - mid)
            arrayAddress[k++] = right_buffer[j++];
    else if(j >= right - mid)
        while(i < mid - left + 1)
            arrayAddress[k++] = left_buffer[i++];
}
void AdvancedSort::mergeSort(){
    cout << "@@ merge sort @@" << endl;
    mergeSort(0, getArrSize() - 1);
}

// @@ Code for Quick-Sort
int AdvancedSort::partition(int left, int right){
    int *arr = getArray_address();
    int p = arr[right];
#if 0
    for(int k=left; k<=right; k++)
        cout << arr[k] << ' ';
    cout << endl;
#endif
    int i = left, j = right - 1;
    while(i <= j){
        while(i <= right && arr[i] < p) i++;
        while(j >= left && arr[j] >= p) j--;
        if(i < j)   swap(&arr[i], &arr[j]);
    }
    swap(&arr[right], &arr[i]);
    return i;
}
void AdvancedSort::quickSort(int left, int right){
    if(left >= right)   return;
    //cout << "left : " << left << " right : " << right << endl;
    int p = partition(left, right);
    quickSort(left, p-1);
    quickSort(p+1, right);
}
void AdvancedSort::quickSort(){
    cout << "@@ quick sort @@" << endl;
    quickSort(0, getArrSize() - 1);
}
int main(){
    clock_t start, end;

    AdvancedSort mySort1(100000);
    AdvancedSort mySort2(100000);
    AdvancedSort mySort3(100000);

    start = clock();
    mySort1.insertionSort();
    mySort1.is_sorted();
    end = clock();
    cout << "insertion sort time : " << static_cast<float>(end - start) / CLOCKS_PER_SEC << endl;; 
    
#if 1
    start = clock();
    mySort2.mergeSort();
    mySort2.is_sorted();
    end = clock();
    cout << "merge sort time : " << static_cast<float>(end - start) / CLOCKS_PER_SEC << endl; 
#endif
    start = clock();
    mySort3.quickSort();
    mySort3.is_sorted();
    end = clock();
    cout << "quick sort time : " << static_cast<float>(end - start) / CLOCKS_PER_SEC << endl; 
}

