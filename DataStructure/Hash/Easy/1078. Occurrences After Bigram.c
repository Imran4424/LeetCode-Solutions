
void stringToken(char *text, char **tokenArr, int *index) {
        int x = 0;
        for(int i = 0; text[i]; i++) {
                if(' ' == text[i]) {
                        tokenArr[(*index)++][x] = '\0';
                        x = 0;
                        continue;
                }

                tokenArr[(*index)][x++] = text[i];
        }

        tokenArr[(*index)++][x] = '\0';
}

int compareString (char *source, char *destination) {
        int i;
        for(i = 0;  source[i]; i++) {
                if(source[i] != destination[i]) {
                        return source[i] - destination[i];
                }
        }

        return source[i] - destination[i];
}

void copyString (char* destination, char* source) {
        int i;
        for(i = 0; source[i]; i++) {
                destination[i] = source[i];
        }

        destination[i] = '\0';
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char ** findOcurrences(char * text, char * first, char * second, int* returnSize) {
        char **tokenArr = malloc( 201 * sizeof(char*));
        for(int i = 0; i < 201; i++) {
                tokenArr[i] = malloc(13 * sizeof(char));
        }

        int index = 0;
        stringToken(text, tokenArr, &index);

        char **occurredString = malloc( 50 * sizeof(char*));
        for(int i = 0; i < 50; i++) {
                occurredString[i] = malloc(13 * sizeof(char));
        }

        int occurIndex = 0;

        for(int i = 0; i < index; i++) {
                if(i + 1 < index  && i + 2 < index && 0 == compareString(tokenArr[i], first) && 0 == compareString(tokenArr[i + 1], second)) {
                        copyString(occurredString[occurIndex++], tokenArr[i + 2]);
                        i++;
                }
        }

        *returnSize = occurIndex;
        return occurredString;
}

