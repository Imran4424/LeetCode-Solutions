
class MyCalendarTwo {
	map<int, vector <int> > events;
public:
	MyCalendarTwo() {
		events.clear();
	}
    
	bool book(int start, int end) {
		// int occurence = 0;
		unordered_map<int, int> occurenceCount;
		int maxOccur = 0;
		for (auto event : events) {

			for (int i = 0; i < event.second.size(); ++i) {
				// inside
				if (event.first < start && event.second[i] > end) {
					//cout << "inside" << endl;
					// ++occurence;
					// cout << start << " " << end << " " << maxOccur << endl;
					if (!occurenceCount.count(start)) {
						occurenceCount[start] = 1;
					} else {
						++occurenceCount[start];
					}

					if (maxOccur < occurenceCount[start]) {
						maxOccur = occurenceCount[start];
					}

					if (!occurenceCount.count(end)) {
						occurenceCount[end] = 1;
					} else {
						++occurenceCount[end];
					}

					if (maxOccur < occurenceCount[end]) {
						maxOccur = occurenceCount[end];
					}

				} else if (event.first >= start && event.second[i] < end) {
					//cout << "outside" << endl;
					//outside overlapping, equal
					// ++occurence;
					// cout << start << " " << end << " " << maxOccur << endl;
					if (!occurenceCount.count(event.first)) {
						occurenceCount[event.first] = 1;
					} else {
						++occurenceCount[event.first];
					}

					if (maxOccur < occurenceCount[event.first]) {
						maxOccur = occurenceCount[event.first];
					}

					if (!occurenceCount.count(event.second[i])) {
						occurenceCount[event.second[i]] = 1;
					} else {
						++occurenceCount[event.second[i]];
					}

					if (maxOccur < occurenceCount[event.second[i]]) {
						maxOccur = occurenceCount[event.second[i]];
					}

				} else if (event.first <= start && event.second[i] > start) {
					// left inside, right outside
					//cout << "left inside, right outside" << endl;
					// ++occurence;
					//cout << start << " " << end << " " << occurence << endl;
					if (!occurenceCount.count(start)) {
						occurenceCount[start] = 1;
					} else {
						++occurenceCount[start];
					}

					if (maxOccur < occurenceCount[start]) {
						maxOccur = occurenceCount[start];
					}

					if (!occurenceCount.count(event.second[i])) {
						occurenceCount[event.second[i]] = 1;
					} else {
						++occurenceCount[event.second[i]];
					}

					if (maxOccur < occurenceCount[event.second[i]]) {
						maxOccur = occurenceCount[event.second[i]];
					}

				} else if (event.first > start && event.first < end) {
					// left outside, right inside
					//cout << "left outside, right inside" << endl;
					// ++occurence;
					//cout << start << " " << end << " " << occurence << endl;
					if (!occurenceCount.count(event.first)) {
						occurenceCount[event.first] = 1;
					} else {
						++occurenceCount[event.first];
					}

					if (maxOccur < occurenceCount[event.first]) {
						maxOccur = occurenceCount[event.first];
					}

					if (!occurenceCount.count(end)) {
						occurenceCount[end] = 1;
					} else {
						++occurenceCount[end];
					}


					if (maxOccur < occurenceCount[end]) {
						maxOccur = occurenceCount[end];
					}
				}
			}
		}

		// cout << start << " " << end << " " << maxOccur << endl;

		if (maxOccur >= 2) {
			return false;
		}

		events[start].push_back(end);
		return true;
	}
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */