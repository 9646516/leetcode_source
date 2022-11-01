// id:369076884
// runtime:96 ms
// memory:59.2 MB
// title:Bitwise XOR of All Pairings
// translatedTitle:所有数对的异或和
// questionId:2533
// time:2022-10-01 22:36:02

class Solution {
  public:
    int xorAllNums(vector<int> &nums1, vector<int> &nums2) {
        int ans = 0;
        if (nums2.size() & 1) {
            for (int i : nums1) {
                ans ^= i;
            }
        }
        if (nums1.size() & 1) {
            for (int i : nums2) {
                ans ^= i;
            }
        }
        return ans;
    }
};
