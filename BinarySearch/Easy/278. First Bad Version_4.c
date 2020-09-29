



// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

int firstBadVersion(long long int num) {
    long int low = 1;
    long int high = num;
    int index;

    while (low <= high) {
        long long int mid = (high + low) / 2;

        bool status = isBadVersion(mid);

        if(status) {
            index = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    return index;
}
