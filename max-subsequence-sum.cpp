#include <iostream>
using namespace std;

struct RetData {
    int begin;
    int end;
    int max;
};

RetData maxSubsequenceSum1(int input[], int begin, int end);
int maxSubsequenceSum2(int input[], int begin, int end);

int main(int argc, char** argv) {

    //int input[8] = {4, -3, 5, -27, -1, 2, 6, -2};     // pass
    //int input[1] = {1};                               // pass
    //int input[7] = {3, 0, -9, 7, 9,-43, 27};          // pass
    //int input[0];                                     // pass
    //int input[3] = {-2, -1, -3};                      // pass
    //int input[6] = {-2, -1, -3, 3, -1, 2};            // pass
    int input[6] = {-2, -1, 3, -3, -1, 2};              // pass
    //int input[6] = {-2, -1, 3, -3, 1, 2};             // pass
    //int input[6] = {-2, -1, 0, 3, 2, 1};              // pass
    int arrLen = sizeof(input) / sizeof(input[0]);
    RetData ret = maxSubsequenceSum1(input, 0, arrLen);
    int max = maxSubsequenceSum2(input, 0, arrLen);
    cout << "Subsequence with max sum is [" << ret.begin << ", " << ret.end << "), " << "and max sum is " << ret.max << "." << endl;
    cout << "Max sum is " << max << endl;
    return 0;

}

// divide and conquer
RetData maxSubsequenceSum1(int input[], int begin, int end) {

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
    int mid = (begin + end) >> 1;

    /// find max subsequence sum of subsequence [begin, mid)
    RetData headRet = maxSubsequenceSum1(input, begin, mid);

    /// find max subsequence sum of subsequence [mid, end)
    RetData tailRet = maxSubsequenceSum1(input, mid, end);

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
    // cross case has highest priority, so longest subsequence with max sum will be returned
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

int maxSubsequenceSum2(int input[], int begin, int end) {
    int thisMax, maxSum;
    thisMax = maxSum = 0;
    for (int i = begin; i < end; ++i) {
        thisMax += input[i];
        if (thisMax > maxSum) {
            maxSum = thisMax;
        }
        if (thisMax < 0) thisMax = 0;
    }
    return maxSum;
}