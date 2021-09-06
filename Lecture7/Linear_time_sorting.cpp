#include "../Lecture3/basicSort.cpp"

class LinearTimeSorting : public Basic_Sort{
    private :
        int *sorted_array;
        
    public :
        LinearTimeSorting(int size) : Basic_Sort(size){sorted_array = NULL;}
        ~LinearTimeSorting();

        // counting sort
        bool is_well_counting_sorted();
        void countingSort();

        // radix sort
        void radixSort(int k);
};
LinearTimeSorting::~LinearTimeSorting(){
    if(sorted_array)
        delete[] sorted_array;
}
void LinearTimeSorting::countingSort(){
    int countingTable[MAX_VALUE];
    for(int i=0; i<MAX_VALUE; i++)
        countingTable[i] = 0;
    int *arr = getArray_address();
    int arrLen = getArrSize();

    for(int i=0; i<arrLen; i++)
        countingTable[arr[i]]++;

    for(int i=1; i<MAX_VALUE; i++)
        countingTable[i] += countingTable[i-1];
    sorted_array = new int[arrLen];   

    for(int i = arrLen-1; i>=0; i--){
        sorted_array[countingTable[arr[i]]] = arr[i];
        countingTable[arr[i]]--;
    }
}
bool LinearTimeSorting::is_well_counting_sorted(){
    for(int i=0; i<getArrSize() - 1; i++){
            if(sorted_array[i] > sorted_array[i+1]){
                cout << "the sort is failed" << endl;
                return false;
            }
    }
    return true;
}
void LinearTimeSorting::radixSort(int k){
    int d, count = 0, div, j;
    div = k;
    int max = MAX_VALUE; max--;
    while(1){
        if(max / div == 0) break;
        count++;    div *= div;
    }
    div = k;
    int countingTable[k];
    int *arr = getArray_address();
    int arrLen = getArrSize();

    sorted_array = new int[arrLen];
    for(int i=0; i<= count; i++){
        for(int idx=0; idx<k; idx++)  countingTable[idx] = 1;
        cout << "@@@@@@" << i << " cycles" <<" div :" << div << " @@@@@@" << endl;

        cout << "@@@ count table 1 @@@@" << endl;        
        for(j=0; j<arrLen; j++){
            int index = (arr[j] % div) / (div / k);
            countingTable[index]++;
        }
        for(int idx=0; idx < k; idx++)
            cout << countingTable[idx] << ' ';

        cout << endl;
        cout << "@@@ count table 2 @@@@" << endl;
        for(j=1; j < k; j++)
            countingTable[j] += countingTable[j-1];

        for(int idx=0; idx < k; idx++)
            cout << countingTable[idx] << ' ';
        cout << endl;
        for(j = arrLen-1; j>=0; j--){
            int index = arr[j] % div / (div / k);
            cout << "index : " << index << " value : " << arr[j] << endl;
            sorted_array[countingTable[index]] = arr[j];
            countingTable[index]--;
        }
        div *= div;
        for(int idx=0; idx < arrLen; idx++)
            cout << sorted_array[idx] << endl;

    }
}

int main(){
    clock_t start, end;
 //   LinearTimeSorting mysort(100000);
    LinearTimeSorting mysort_radixSort(10);
#if 0
    start = clock();
    mysort.countingSort();
    end = clock();

    cout << "counting sort time" << static_cast<float>(end-start) / CLOCKS_PER_SEC << endl;
    mysort.is_well_counting_sorted();
#endif
    mysort_radixSort.radixSort(10);
    mysort_radixSort.is_well_counting_sorted();
}
