#include <iostream>
using namespace std;

template<typename T>
int binarySearch(T input[], int begin, int end, T target);
template<typename T>
int binarySearch2(T input[], int begin, int end, T target);

int main(int argc, char** argv) {
    int input[] = {-68, -10, 3, 7, 8, 9, 10, 23, 23, 200, 400};
    int inputLen = sizeof(input) / sizeof(input[0]);
    int target = 7;
    cout << "Index of value " << target << " in input array is " << binarySearch2(input, 0, inputLen, target) << endl;
}

template<typename T>
int binarySearch(T input[], int begin, int end, T target) {

    if (begin >= end) throw "invalid boundary";

    int mid = (begin + end) >> 1;
    if (input[mid] == target) return mid;
    if (begin == mid && input[mid] != target) return -1;

    if (input[mid] > target) return binarySearch(input, begin, mid, target);
    else return binarySearch(input, mid, end, target);

}

template<typename T>
int binarySearch2(T input[], int begin, int end, T target) {

    if (begin >= end) throw "invalid boundary";
    int mid = (begin + end) >> 1;
    while (begin != mid) {
        if (input[mid] == target) return mid;
        if (input[mid] > target) {
            end = mid;
        } else {
            begin = mid;
        }
        mid = (begin + end) >> 1;
    }
    return -1;

}