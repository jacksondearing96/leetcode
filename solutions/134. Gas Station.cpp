class Solution {
public:
    
    int nextStation(int current_station, int number_of_stations) {
        return (current_station + 1) % number_of_stations; 
    }
    
    bool canCompleteCircuit(vector<int>& gas, vector<int>& cost, int starting_station) {
         int station = starting_station;
         int tank = 0;
        
         do {
            tank += gas[station];
            tank -= cost[station]; 
            station = nextStation(station, gas.size());
         } while (station != starting_station && tank >= 0);
         
         return station == starting_station && tank >= 0;
    }
    
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        for (int station = 0; station < gas.size(); ++station)  {
            if (canCompleteCircuit(gas, cost, station)) return station;
        }
        return -1;
    }
};
