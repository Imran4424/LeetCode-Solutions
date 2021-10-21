class Solution {
public:
    string interpret(string command) {
        string decrypt = "";
        
        for (int i = 0; i < command.size(); i++) {
            if('(' == command[i]) {
                if (')' == command[i + 1]) {
                    decrypt += 'o';
                    i++;
                } else {
                    decrypt += "al";
                    i = i + 3;
                }
                continue;
            }
            decrypt += command[i];
        }
        
        return decrypt;
    }
};