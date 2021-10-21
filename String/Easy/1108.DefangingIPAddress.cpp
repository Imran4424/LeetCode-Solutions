class Solution {
public:
    string defangIPaddr(string address) {
        string defangIP = "";
        
        for (int i = 0; i < address.length(); i++) {
            if('.' == address[i]) {
                defangIP = defangIP + "[" + address[i] + "]";
                continue;
            }
            
            defangIP += address[i];
        }
        
        return defangIP;
    }
};