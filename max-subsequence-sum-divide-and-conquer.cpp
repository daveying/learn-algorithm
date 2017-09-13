#include <iostream>
using namespace std;

struct RetData {
    int begin;
    int end;
    int max;
};

RetData maxSubsequenceSum(int input[], int begin, int end);

int main(int argc, char** argv) {

    //int input[8] = {4, -3, 5, -27, -1, 2, 6, -2};     // pass
    //int input[1] = {1};                               // pass
    //int input[7] = {3, 0, -9, 7, 9,-43, 27};          // pass
    int input[0];                                       // pass
    int arrLen = sizeof(input) / sizeof(input[0]);
    RetData ret = maxSubsequenceSum(input, 0, arrLen);
    cout << ret.begin << endl << ret.end << endl << ret.max << endl;
    return 0;

}

RetData maxSubsequenceSum(int input[], int begin, int end) {

    RetData ret;
    /// length of input array is zero (invalid input)
    if (begin == end) {
        ret.begin = -1;
        ret.end = -1;
        ret.max = -1;
        return ret;
    }
    /// length of susequence is 1, return the value as max value
    if (begin + 1 == end) {
        ret.begin = begin;
        ret.end = end;
        ret.max = input[begin];
        return ret;
    }
    /// calculate middle index of subsequence
    int mid = (begin + end) / 2;

    /// find max subsequence sum of subsequence [begin, mid)
    RetData headRet = maxSubsequenceSum(input, begin, mid);

    /// find max subsequence sum of subsequence [mid, end)
    RetData tailRet = maxSubsequenceSum(input, mid, end);

    /// find max subsequence sum cross middle point (the sum of subsequence [headRet.begin, tailRet.end) )
    int maxHead = headRet.max;
    for (int i = headRet.end; i < mid; ++i) {
        maxHead += input[i];
    }
    int maxTail = tailRet.max;
    for (int i = mid; i < tailRet.begin; ++i) {
        maxTail += input[i];
    }
    int maxCross = maxHead + maxTail;

    /// compare and find which one is the max subsuquence sum
    if (maxCross >= headRet.max && maxCross >= tailRet.max) {
        ret.begin = headRet.begin;
        ret.end = tailRet.end;
        ret.max = maxCross;
        return ret;
    }

    if (headRet.max >= tailRet.max && headRet.max >= maxCross) {
        return headRet;
    }
    return tailRet;

}