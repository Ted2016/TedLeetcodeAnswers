class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
    	int tank = 0, path = 0, location = 0, gas_diff = 0; 
        for(int i = 0; i < gas.size(); i++) {
        	tank += gas[i];
        	path += cost[i];
        	if(tank < path) {
        		location = i+1;
        		gas_diff += tank-path;
        		tank = 0, path = 0;
        	}
        }
        gas_diff += tank-path;
        return gas_diff < 0 ? -1 : location;
    }
};