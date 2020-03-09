

int repeatedNTimes(int* arr, int arrSize){
    bool visited[10005] = {false};

    for(int i = 0; i < arrSize; i++) {
        if(visited[arr[i]]) {
            return arr[i];
        } else {
            visited[arr[i]] = true;
        }
    }

    return -1;
}

