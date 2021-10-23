class OrderedStream {
	vector<string> orderedStream;
	int n;

public:
    OrderedStream(int n) {
        this -> n = n;
    }
    
    vector<string> insert(int idKey, string value) {
    	orderedStream = vector<string>(n);
    	orderedStream[idKey - 1] = value;

    	return orderedStream;
    }
};

/**
 * Your OrderedStream object will be instantiated and called as such:
 * OrderedStream* obj = new OrderedStream(n);
 * vector<string> param_1 = obj->insert(idKey,value);
 */