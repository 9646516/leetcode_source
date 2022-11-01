// id:321223903
// runtime:20 ms
// memory:9.6 MB
// title:Kth Largest Element in an Array
// translatedTitle:数组中的第K个最大元素
// questionId:215
// time:2022-06-03 14:03:29

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

template<typename T>
T *nth(T *src, int k, int len) {

    swap(src[0], src[len - 1]);
    int ptr = 0;
    for (int i = 0; i < len - 1; i++) {
        if (src[i] < src[len - 1]) {
            swap(src[i], src[ptr++]);
        }
    }
    swap(src[ptr], src[len - 1]);
    if (k <= ptr) {
        return nth(src, k, ptr);
    } else if (k == ptr + 1) {
        return src + ptr;
    } else {
        return nth(src + ptr + 1, k - ptr - 1, len - ptr - 1);
    }
}

class Solution {
public:
    int findKthLargest(vector<int> &nums, int k) {
        return *nth(nums.data(), nums.size() + 1 - k, nums.size());
    }
};

