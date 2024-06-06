#include <algorithm>
#include <vector>
using namespace std;

void print(vector<int>& v) {
    for (int i : v) {
        printf("%d ", i);
    }
    printf("\n");
}

int partition(vector<int>& v, int i, int j) {
    int pivot = v[j];
    int index = j;
    while (i < index) {
        if (v[i] >= pivot) {
            swap(v[i], v[index]);
            while (v[index] >= pivot) {
                index--;
            }
        } else {
            i++;
        }
    }
    return index;
}

void quicksort(vector<int> &v, int i, int j) {
    if (i >= j) {
        return;
    }
    int p = partition(v, i, j);
    quicksort(v, i, p - 1);
    quicksort(v, p + 1, j);
}

vector<int> merge(vector<int> v1, vector<int> v2) {
    vector<int> v;
    int i = 0, j = 0;
    while (i < v1.size() && j < v2.size()) {
        if (v1[i] > v2[j]) {
            v.push_back(v2[j]);
            j++;
        } else {
            v.push_back(v1[i]);
            i++;
        }
    }
    while (i < v1.size()) {
        v.push_back(v1[i]);
        i++;
    }

    while (j < v2.size()) {
        v.push_back(v2[j]);
        j++;
    }
    return v;
}

void mergesort(vector<int>& vec) {
    if (vec.size() <= 1) return;
    int mid = (int)vec.size() / 2;
    vector<int> first_half, second_half;
    for (int i = 0; i < vec.size(); i++) {
        (i < mid) ? first_half.push_back(vec[i]) : second_half.push_back(vec[i]);
    }
    mergesort(first_half);
    mergesort(second_half);
    vec = merge(first_half, second_half);
}

int main() {
    vector<int> v_quick = {4, 3, 2, 1, 5, 6, 7, 8, 9, 10, 5, 3};
    quicksort(v_quick, 0, v_quick.size() - 1);
    print(v_quick);
    vector<int> v_merge = {4, 3, 2, 1, 5, 6, 7, 8, 9, 10, 5, 3};
    mergesort(v_merge);
    print(v_merge);
    return 0;
}