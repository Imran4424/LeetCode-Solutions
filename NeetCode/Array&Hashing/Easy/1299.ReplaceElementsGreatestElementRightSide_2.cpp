class Solution {
public:
        vector<int> replaceElements(vector<int>& arr) {
                int storedValue = 0;
                int maxElement = -1;

                for (int i = arr.size() - 1; i >= 0; --i) {
                        storedValue = arr[i];
                        arr[i] = maxElement;

                        if (storedValue > maxElement) {
                                maxElement = storedValue;
                        }
                        
                }

                return arr;
        }
};