#include <iostream>
#include <vector>
#include <iterator>


void qsort(std::vector<int> &arr, int left, int right);
int bi_search(std::vector<int> arr, int n, int val);
void bubble_sort(std::vector<int> &arr, int n);
void bubble_sort2(std::vector<int> &arr, int n);
void select_sort(std::vector<int> &arr, int n);
void insert_sort(std::vector<int> &arr, int n);
void bi_insert_sort(std::vector<int> &arr, int n);
void shell_sort(std::vector<int> &arr, int n);
void merge_sort(std::vector<int> &arr, std::vector<int> &temp, int start, int end);
void merge_array(std::vector<int> &arr, std::vector<int> &temp, int start, int mid, int end);

int main()
{
    int a[12] = {1,28,23,3,58,20,16,56,22,10,8,33};

    std::vector<int> arr(a, a + 12);
    std::copy(arr.begin(), arr.end(), std::ostream_iterator<int>(std::cout, " "));
    std::cout<<std::endl;
    //qsort(arr, 0, 11);
    //shell_sort(arr, 12);
    std::vector<int> temp(12);
    merge_sort(arr, temp, 0, 11);
    std::copy(arr.begin(), arr.end(), std::ostream_iterator<int>(std::cout, " "));
    std::cout<<std::endl;
    std::cout<<bi_search(arr, 12, 58)<<std::endl;
    return 0;
}

void qsort(std::vector<int> &arr, int left, int right)
{
    if(left > right){
        return;
    }
    int i, j, temp;
    i = left;
    j = right;
    temp = arr[left];
    while(i != j)
    {
        while(arr[j] >= temp && i < j){
            j--;
        }
        while(arr[i] <= temp && i < j){
            i++;
        }
        if(i < j){
            std::swap(arr[i], arr[j]);
        }
    }
    arr[left] = arr[i];
    arr[i] = temp;

    qsort(arr, left, i - 1);
    qsort(arr, i + 1, right);
}

void bubble_sort(std::vector<int> &arr, int n)
{
    int i, j;
    for(i = 0; i < n; i++){
        for(j = i + 1; j < n; j++){
            if(arr[j] < arr[i]){
                std::swap(arr[i], arr[j]);
            }
        }
    }
}

void bubble_sort2(std::vector<int> &arr, int n)
{
    int i, j;
    for(i = 0; i < n; i++){
        for(j = n - 1; j > i; j--){
            if(arr[j] > arr[j - 1]){
                std::swap(arr[j-1], arr[j]);
            }
        }
    }
}

int bi_search(std::vector<int> arr, int n, int val)
{
    int i, j, mid;
    i = 0;
    j = n - 1;
    while(i <= j){
        mid = (i + j)/2;
        if(arr[mid] == val){
            return mid;
        }else if(arr[mid] > val){
            j = mid - 1;

        }else{
            i = mid + 1;
        }
    }
    return -1;
}

void select_sort(std::vector<int> &arr, int n){
    int i, j, k;
    for(i = 0; i < n; i++){
        k = i;
        for(j = i + 1; j < n; j++){
            if(arr[j] < arr[k]){
                k = j;
            }
        }
        if(k != i)
        {
            std::swap(arr[i], arr[k]);
        }
    }
}

void insert_sort(std::vector<int> &arr, int n){
    int i, j, temp;
    for(i = 1; i < n; i++)
    {
        temp = arr[i];
        for(j = i - 1; j >=0 && arr[j] > temp; j--){
            arr[j + 1] = arr[j];
        }
        arr[j + 1] = temp;
    }
}

void bi_insert_sort(std::vector<int> &arr, int n){
    int i, j, temp;
    int start, end, mid;
    for(i = 1; i < n; i++){
        temp = arr[i];
        start = 0;
        end = i - 1;
        while(start <= end){
            mid = (start + end)/2;
            if(arr[mid] == temp){
                break;
            }else if(arr[mid] > temp){
                end = mid - 1;
            }else{
                start = mid + 1;
            }
        }
        for(j = i - 1; j >= start; j--){
            arr[j + 1] = arr[j];
        }
        arr[start] = temp;
    }
}

void shell_sort(std::vector<int> &arr, int n){
    int i, j, gap, temp;
    gap = n;
    while(gap > 1)
    {
        gap = gap/3 + 1;
        for(i = gap; i < n; i+=gap){
            temp = arr[i];
            for(j = i - gap; j >=0 && arr[j] > temp; j-= gap){
                arr[j + gap] = arr[j];
            }
            arr[j + gap] = temp;
        }
    }
}

void merge_array(std::vector<int> &arr, std::vector<int> &temp, int start, int mid, int end)
{
    int i, j, k;
    i = start;
    j = mid + 1;
    k = 0;
    while(i <= mid && j <= end){
        if(arr[i] > arr[j]){
            temp[k++] = arr[j++];
        }else{
            temp[k++] = arr[i++];
        }
    }
    while(i <= mid){
        temp[k++] = arr[i++];
    }
    while(j <= end){
        temp[k++] = arr[j++];
    }
    for(i = 0; i < k; i++){
        arr[start+i] = temp[i];
    }
}

void merge_sort(std::vector<int> &arr, std::vector<int> &temp, int start, int end)
{
   if(start < end){
        int mid = (start + end)/2;
        merge_sort(arr, temp, start, mid);
        merge_sort(arr, temp, mid + 1, end);
        merge_array(arr, temp, start, mid, end);
   }
}
