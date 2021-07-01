/*
    terminology:
        1) del[i] = gas[i] - cost[i]
        2) total = sum(gas) - sum(cost)

    observations :
        1) del[i] cant be negative if u want to start from i
        2) total cant be negative
        3) if running del is negative then we dont need to go back, we can start from the next index and make del = 0

    test on:
        gas = [1,2,3,4,5]
        cost= [3,4,5,1,2]
*/
int Solution::canCompleteCircuit(const vector<int> &gas, const vector<int> &cost)
{
    int del = 0, total = 0, s = 0;
    for(int i=0;i<gas.size(); ++i)
    {
        del += gas[i] - cost[i];
        total += gas[i] - cost[i];
        
        if(del < 0)
        {
            del = 0;
            s = i+1;
        }
    }
    
    if(total < 0) return -1;
    
    return s;
}