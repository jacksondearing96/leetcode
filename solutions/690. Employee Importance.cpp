/*
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/
​
class Solution {
public:
    unordered_map<int, Employee*> employees_map;
    
    int getImportanceHelper(int id) {
        Employee* employee = employees_map[id];
        
        int cumulative_importance = employee->importance;
        for (int subordinate_id : employee->subordinates) {
            cumulative_importance += getImportanceHelper(subordinate_id);
        }
        
        return cumulative_importance;
    }
    
    int getImportance(vector<Employee*> employees, int id) {
        for (auto employee : employees) employees_map[employee->id] = employee;
        return getImportanceHelper(id); 
    }
};
