// reader.get(index) is provided by the judge and returns 2147483647 outside the hidden array.
class Solution {
   public:
    int search(const ArrayReader& reader, int target) {
        int l = 0, r = 1, mid;
        while (reader.get(r) < target) {
            r *= 2;
        }
        while (l <= r) {
            
            mid = l + (r - l) / 2;
            if (reader.get(mid) == target)
                return mid;
            else if (reader.get(mid) > target) {
                r = mid - 1;
            } else
                l = mid + 1;
        }
        return -1;
    }
};
