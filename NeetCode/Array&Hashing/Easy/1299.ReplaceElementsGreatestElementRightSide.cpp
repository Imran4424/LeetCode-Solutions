class Solution {
public:
        vector<int> replaceElements(vector<int>& arr) {

                int storedValue = 0;
                int maxElement = arr[arr.size() - 1];
                arr[arr.size() - 1] = -1;

                for (int i = arr.size() - 2; i >= 0; --i) {
                        storedValue = arr[i];
                        arr[i] = maxElement;

                        if (storedValue > maxElement) {
                                maxElement = storedValue;
                        }
                        
                }

                return arr;
        }
};