
/*
    https://leetcode.com/problems/robot-return-to-origin/
*/

bool judgeCircle(char * moves){
    int posX = 0, posY = 0;
    
    for(int i = 0; moves[i] != '\0'; i++) {
        if('L' == moves[i]) {
            posX--;
        } else if('R' == moves[i]) {
            posX++;
        } else if('D' == moves[i]) {
            posY--;
        } else if('U' == moves[i]) {
            posY++;
        }
    }
    
    if(0 == posX && 0 == posY) {
        return true;
    }
    
    return false;
}