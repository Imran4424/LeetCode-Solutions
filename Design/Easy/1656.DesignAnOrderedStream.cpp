class OrderedStream {
	int index;
	vector<string> orderedStream;

public:
    OrderedStream(int n) {
        orderedStream = vector<string>(n + 1);
        index = 1;
    }
    
    vector<string> insert(int idKey, string value) {
    	vector<string> result;
    	orderedStream[idKey] = value;

    	while (index < orderedStream.size()) {
    		if(orderedStream[index].empty()) {
    			return result;
    		}

    		result.push_back(orderedStream[index++]);
    	}

    	return result;
    }
};

/**
 * Your OrderedStream object will be instantiated and called as such:
 * OrderedStream* obj = new OrderedStream(n);
 * vector<string> param_1 = obj->insert(idKey,value);
 */