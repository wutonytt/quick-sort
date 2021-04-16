#include <iostream>
#include <vector>

using namespace std;

void swap(vector<int> &array, int i, int j) {
    int tmp = array[i];
    array[i] = array[j];
    array[j] = tmp;
}

int Partition(vector<int> &array, int front, int end) {
    int pivot = array[end];
    int i = front-1;
    for (int j = front; j < end; j++) {
        if (array[j] < pivot) {
            i++;
            swap(array, i, j);
        }
    }
    i++;
    swap(array, i, end);
    return i;
}

void QuickSort(vector<int> &array, int front, int end) {
    if (front < end) {
        int pivot = Partition(array, front, end);
        QuickSort(array, front, pivot-1);
        QuickSort(array, pivot+1, end);
    }
}

int main() {
    int arr[] = {5,3,8,6,2,7,1,4};
    vector<int> array(arr, arr + sizeof(arr)/sizeof(arr[0]));
    QuickSort(array, 0, array.size()-1);

    for (int i = 0; i < array.size(); i++) {
        cout << array[i] << " ";
    }
}