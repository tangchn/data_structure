#include <iostream>
#include <vector>
#include <iterator>

using namespace std;

int kth(vector<int> arr, int begin, int end, int k);
int partion(vector<int> &arr, int begin, int end);
void qsort(vector<int> &arr, int begin, int end);

int main()
{
    int arrTemp[10] = {23,33,12,8,9,45,324,25,5,39};
    vector<int> arr(arrTemp, arrTemp + 10);
    copy(arr.begin(), arr.end(), ostream_iterator<int>(cout," "));
    cout << endl;
    //qsort(arr,0,9);
    //copy(arr.begin(), arr.end(), ostream_iterator<int>(cout," "));
    int k = 3;
    cout <<"The "<<k<<"th number is: "<<kth(arr, 0, 9, k);
    cout << endl;
    qsort(arr,0,9);
    copy(arr.begin(), arr.end(), ostream_iterator<int>(cout," "));
    return 0;
}


int kth(vector<int> arr, int begin, int end, int k)
{
    int pivot = partion(arr, begin, end);
    while(pivot != k - 1)
    {
        if(pivot < k - 1)
        {
            pivot = partion(arr, pivot + 1, end);
        }
        if(pivot > k - 1)
        {
            pivot = partion(arr, begin, pivot - 1);
        }
    }

    return arr[pivot];
}

void qsort(vector<int> &arr, int begin, int end)
{
    int pivot;
    if(begin < end)
    {
        pivot = partion(arr, begin, end);
        qsort(arr, begin, pivot-1);
        qsort(arr, pivot + 1, end);
    }
}

int partion(vector<int> &arr, int begin, int end)
{
    int i, j, pivot;
    pivot = arr[begin];
    i = begin;
    j = end;
    while(i < j)
    {
        while(i < j && arr[j] >= pivot)
        {
            j--;
        }
        arr[i] = arr[j];
        while(i < j && arr[i] <= pivot)
        {
            i++;
        }
       arr[j] = arr[i];
    }
    arr[i] = pivot;
    return i;
}
