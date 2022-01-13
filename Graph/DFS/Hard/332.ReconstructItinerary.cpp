/*
	You are given a list of airline tickets where tickets[i] = [fromi, toi] represent 
	the departure and the arrival airports of one flight. Reconstruct the itinerary in 
	order and return it.

	All of the tickets belong to a man who departs from "JFK", thus, the itinerary must 
	begin with "JFK". If there are multiple valid itineraries, you should return the itinerary 
	that has the smallest lexical order when read as a single string.

    	For example, the itinerary ["JFK", "LGA"] has a smaller lexical order than ["JFK", "LGB"].

	You may assume all tickets form at least one valid itinerary. You must use all the tickets 
	once and only once.
*/

class Solution {
	unordered_map<string, map<string, bool> > travelList;
	vector <string> result;
	unordered_set<string> cityList;

	typedef map<string, bool>:: iterator innerIt;

	void dfs(string current, innerIt ptr) {
		if (!travelList.count(current)) {
			return;
		}

		result.push_back(current);
		cityList.erase(current);
		ptr->second = true;

		for (innerIt it = travelList[current].begin(); it != travelList[current].end(); it++) {
			if (!it->second) {
				dfs(it->first, it);
			}
		}
	}

public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
    	for (int i = 0; i < tickets.size(); i++) {
    		travelList[tickets[i][0]][tickets[i][1]] = false;
    		cityList.insert(tickets[i][0]);
    		cityList.insert(tickets[i][1]);
    	}

    	result.clear();
    	map<string, bool> tempMap;
    	tempMap["JFK"] = false;
    	dfs("JFK", tempMap.begin());

    	if (!cityList.empty()) {
    		result.push_back(*(cityList.begin()));
    	}

    	return result;
    }
};

/*
	This solution will end up in wrong answer

*/