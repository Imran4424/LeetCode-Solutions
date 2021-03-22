
int minValue(int x , int y) {
    if(x < y) {
        return x;
    }

    return y;
}

int nthUglyNumber(int n){
    int uglyNumbers[n];
    int index = 0;
    uglyNumbers[index++] = 1;
    int count = 0;
    int indexTwo = 0;
    int indexThree = 0;
    int indexFive = 0;

    int valueTwo = 2;
    int valueThree = 3;
    int valueFive = 5;



    while(index < n) {
        int current = minValue(minValue(valueTwo, valueThree), valueFive);
        uglyNumbers[index++] = current;

        if(current == valueTwo) {
            valueTwo = uglyNumbers[++indexTwo] * 2;
        }

        if (current == valueThree) {
            valueThree = uglyNumbers[++indexThree] * 3;
        }

        if(current == valueFive) {
            valueFive = uglyNumbers[++indexFive] * 5;
        }
    }

    return uglyNumbers[index - 1];
}


