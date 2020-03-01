
int numJewelsInStones(char *jewels, char *stones) {
    int jewelCount = 0;

    for(int i = 0; stones[i]; i++) {
        for(int k = 0; jewels[k]; k++) {
            if(stones[i] == jewels[k]) {
                jewelCount++;
                break;
            }
        }
    }

    return jewelCount;
}

