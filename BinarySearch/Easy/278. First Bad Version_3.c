

// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

int firstBadVersion(int num) {
    int low = 1;
    int high = num;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        /// generating true false depending on the condition
        /// finding the max true from the array
        if(!isBadVersion(mid) && isBadVersion(mid + 1)) {
            return mid + 1;
        } else if(!isBadVersion(mid - 1) && isBadVersion(mid)) {
            return mid;
        } else if(!isBadVersion(mid)) {
            low = mid + 1;
        } else if(isBadVersion(mid - 1) && isBadVersion(mid)) {
            high = mid - 1;
        }
    }

    return low;
}
