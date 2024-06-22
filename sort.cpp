#include<iostream>
#include<ctime>
#include<vector> 
#include<algorithm>
#include<map> 
using namespace std;

//=======================prototype=========================//
void bubbleSort(int a[], int n);
void selectionSort(int a[], int n);
void insertionSort(int a[], int n);
void interchangeSort(int a[], int n);
void shakeSort(int a[], int n);
void heapSort(int a[], int n); 
void quickSort(int a[], int left, int right);
void mergeSort(int a[], int left, int right, int b[]);
void binaryInsertionSort(int a[], int n);
void shellSort(int a[], int n);
void radixSort(int a[], int n);
void countingSort(int a[], int n);
void bucketSort(int a[], int n);

void heapify(int a[], int n, int i);
void merge(int a[], int left, int mid, int right, int b[]);
int binarySearch(int a[], int left, int right, int x);
int getMax(int a[], int n);
void countSort(int a[], int n, int exp);
void print(int a[], int n);
void resetArray(int a[], int originalArray[], int n);

double timeRunningBubbleSort(int a[], int n);
double timeRunningSelectionSort(int a[], int n);
double timeRunningInsertionSort(int a[], int n);
double timeRunningInterchangeSort(int a[], int n);
double timeRunningShakeSort(int a[], int n);
double timeRunningHeapSort(int a[], int n);
double timeRunningQuickSort(int a[], int n);
double timeRunningMergeSort(int a[], int n);
double timeRunningBinaryInsertionSort(int a[], int n);
double timeRunningShellSort(int a[], int n);
double timeRunningRadixSort(int a[], int n);
double timeRunningCountingSort(int a[], int n);
double timeRunningBucketSort(int a[], int n);

//=======================variable=========================//
int a[10] = {10, 7, 4, 3, 6, 5, 1, 8, 9, 2};
int b[10]; // for merge sort
int n = 10;

//=========================main===========================//
int main() {
    int originalArray[10] = {10, 7, 4, 3, 6, 5, 1, 8, 9, 2};

    return 0;
}

//=======================SETUP SORT=========================//
void bubbleSort(int a[], int n){
    for(int i = 0; i < n - 1; i++){
        for(int j = n - 1; j > i; j--){
            if(a[j] < a[j - 1]){
                swap(a[j], a[j - 1]);
            }
        }
    }
}

void selectionSort(int a[], int n){
    for(int i = 0; i < n - 1; i++){
        int min = i;
        for(int j = i + 1; j < n; j++){
            if(a[j] < a[min]){
                min = j;
            }
        }
        swap(a[i], a[min]);
    }
}

void insertionSort(int a[], int n){
    for(int i = 1; i < n; i++){
        int temp = a[i];
        int j = i - 1;
        while(j >= 0 && a[j] > temp){
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = temp;
    }
}

void interchangeSort(int a[], int n){
    for(int i = 0; i < n - 1; i++){
        for(int j = i + 1; j < n; j++){
            if(a[i] > a[j]){
                swap(a[i], a[j]);
            }
        }
    }
}

void shakeSort(int a[], int n){
    int top = 0, bottom = n - 1, save = n - 1;

    while(top < bottom){
        for(int i = bottom; i > top; i--){
            if(a[i] < a[i - 1]){
                swap(a[i], a[i - 1]);
                save = i; 
            }
        }
        top = save; 

        for(int i = top; i < bottom; i++){
            if(a[i] > a[i + 1]){
                swap(a[i], a[i + 1]);
                save = i + 1;
            }
        }
        bottom = save;
    }
}

void heapSort(int a[], int n){
    for(int i = n / 2 - 1; i >= 0; i--){
        heapify(a, n, i);
    }
    for(int i = n - 1; i >= 0; i--){
        swap(a[0], a[i]);
        heapify(a, i, 0);
    }
}

void quickSort(int a[], int left, int right){
    int i = left, j = right;

    int partition = a[(left + right) / 2];

    while(i <= j){
        while(a[i] < partition) i++;
        while(a[j] > partition) j--;
        if(i <= j){
            swap(a[i], a[j]);
            i++;
            j--;
        }
    }

    if(left < j) quickSort(a, left, j);
    if(i < right) quickSort(a, i, right);
}

void mergeSort(int a[], int left, int right, int b[]){
    if(left < right){
        int mid = (left + right) / 2;
        mergeSort(a, left, mid, b);
        mergeSort(a, mid + 1, right, b);
        merge(a, left, mid, right, b);

        for(int i = left; i <= right; i++){
            a[i] = b[i];
        }
    }
}

void binaryInsertionSort(int a[], int n){
    int i, locate, j, k, selected;
    for(i = 1; i < n; ++i){
        j = i - 1;
        selected = a[i];
        locate = binarySearch(a, 0, j, selected);

        while(j >= locate){
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = selected;
    }
}

void shellSort(int a[], int n){
    for(int gap = n / 2; gap > 0; gap /= 2){
        for(int i = gap; i < n; i++){
            int temp = a[i];
            int j = i - gap;
            while(j >= 0 && a[j] > temp){
                a[j + gap] = a[j];
                j -= gap;
            }
            a[j + gap] = temp;
        }
    }
}

void radixSort(int a[], int n){
    int m = getMax(a, n);
    for(int exp = 1; m / exp > 0; exp *= 10)
        countSort(a, n, exp);
}

void countingSort(int a[], int n){
    int max = getMax(a, n);

    map<int, int> count;

    for(int i = 0; i < n; ++i){
        count[a[i]]++;
    }

    int index = 0;
    for(const auto& pair : count){
        int element = pair.first;
        int frequency = pair.second;
        for(int i = 0; i < frequency; ++i){
            a[index++] = element;
        }
    }
}

void bucketSort(int a[], int n){
    int max = getMax(a, n);

    int numBuckets = max / 10 + 1;

    vector<vector<int>> buckets(numBuckets);

    for(int i = 0; i < n; i++){
        int bucketIndex = a[i] / 10;
        buckets[bucketIndex].push_back(a[i]);
    }

    for(int i = 0; i < numBuckets; i++){
        insertionSort(buckets[i].data(), buckets[i].size());
    }

    int index = 0;
    for(int i = 0; i < numBuckets; i++){
        for(size_t j = 0; j < buckets[i].size(); j++){
            a[index++] = buckets[i][j];
        }
    }
}

//=====================support function=======================//
void heapify(int a[], int n, int i){
    int largest = i;

    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if(left < n && a[left] > a[largest]){
        largest = left;
    }

    if(right < n && a[right] > a[largest]){
        largest = right;
    }

    if(largest != i){
        swap(a[i], a[largest]);
        heapify(a, n, largest);
    }
}

void merge(int a[], int left, int mid, int right, int b[]){
    int i = left, j = mid + 1, k = left; 
    while(i <= mid && j <= right){
        if(a[i] < a[j]){
            b[k++] = a[i++];
        }
        else{
            b[k++] = a[j++];
        }
    }
    
    while(i <= mid){
        b[k++] = a[i++];
    }

    while(j <= right){
        b[k++] = a[j++];
    }
}

int binarySearch(int a[], int left, int right, int x){
    while(left <= right){
        int mid = left + (right - left) / 2;
        if(a[mid] < x) left = mid + 1;
        else right = mid - 1;
    }
    return left;
}

int getMax(int a[], int n){
    int max = a[0];
    for(int i = 1; i < n; i++)
        if(a[i] > max)
            max = a[i];
    return max;
}

void countSort(int arr[], int n, int exp){
    int output[n], i, count[10] = {0};

    for(i = 0; i < n; i++)
        count[(arr[i] / exp) % 10]++;

    for(i = 1; i < 10; i++)
        count[i] += count[i - 1];

    for(i = n - 1; i >= 0; i--){
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }

    for(i = 0; i < n; i++)
        arr[i] = output[i];
}

void print(int a[], int n){
    for(int i = 0; i < n; i++){
        cout << a[i] << " ";
    }
    cout << endl;
}

void resetArray(int dest[], int src[], int n){
    for(int i = 0; i < n; i++) {
        dest[i] = src[i];
    }
}

//=====================time running function=====================//
double timeRunningBubbleSort(int a[], int n){
	clock_t start, end;
    start = clock();
	bubbleSort(a,n);
	end = clock();
	double time = (double)(end-start) / CLOCKS_PER_SEC;	
	return time;
}

double timeRunningSelectionSort(int a[], int n){
	clock_t start, end;
    start = clock();
	selectionSort(a,n);
	end = clock();
	double time = (double)(end-start) / CLOCKS_PER_SEC;	
	return time;
}

double timeRunningInsertionSort(int a[], int n){
	clock_t start, end;
    start = clock();
	insertionSort(a,n);
	end = clock();
	double time = (double)(end-start) / CLOCKS_PER_SEC;	
	return time;
}

double timeRunningInterchangeSort(int a[], int n){
	clock_t start, end;
    start = clock();
	interchangeSort(a,n);
	end = clock();
	double time = (double)(end-start) / CLOCKS_PER_SEC;	
	return time;
}

double timeRunningShakeSort(int a[], int n){
	clock_t start, end;
    start = clock();
	shakeSort(a,n);
	end = clock();
	double time = (double)(end-start) / CLOCKS_PER_SEC;	
	return time;
}

double timeRunningHeapSort(int a[], int n){
	clock_t start, end;
    start = clock();
    heapSort(a,n);
	end = clock();
	double time = (double)(end-start) / CLOCKS_PER_SEC;	
	return time;
}

double timeRunningQuickSort(int a[], int n){
	clock_t start, end;
    start = clock();
	quickSort(a,0,n-1);
	end = clock();
	double time = (double)(end-start) / CLOCKS_PER_SEC;	
	return time;
}

double timeRunningMergeSort(int a[], int n){
	clock_t start, end;
    start = clock();
	mergeSort(a,0,n-1,b);
	end = clock();
	double time = (double)(end-start) / CLOCKS_PER_SEC;	
	return time;
}

double timeRunningBinaryInsertionSort(int a[], int n){
	clock_t start, end;
    start = clock();
    binaryInsertionSort(a,n);
	end = clock();
	double time = (double)(end-start) / CLOCKS_PER_SEC;	
	return time;
}

double timeRunningShellSort(int a[], int n){
	clock_t start, end;
    start = clock();
    shellSort(a,n);
	end = clock();
	double time = (double)(end-start) / CLOCKS_PER_SEC;	
	return time;
}

double timeRunningRadixSort(int a[], int n){
	clock_t start, end;
    start = clock();
    radixSort(a,n);
	end = clock();
	double time = (double)(end-start) / CLOCKS_PER_SEC;	
	return time;
}

double timeRunningCountingSort(int a[], int n){
	clock_t start, end;
    start = clock();
    countingSort(a,n);
	end = clock();
	double time = (double)(end-start) / CLOCKS_PER_SEC;	
	return time;
}

double timeRunningBucketSort(int a[], int n){
	clock_t start, end;
    start = clock();
    bucketSort(a,n);
	end = clock();
	double time = (double)(end-start) / CLOCKS_PER_SEC;	
	return time;
}