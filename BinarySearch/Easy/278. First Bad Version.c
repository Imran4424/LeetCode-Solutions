

// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

int firstBadVersion(int num) {
    for(int i = num; i >= 0; i--) {
        if(!isBadVersion(i)) {
            return i + 1;
        }
    }
    
    return num;
}