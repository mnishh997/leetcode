class EventManager {

    map<int, int> eventPriority;
    map<int, set<int>> priority;

public:
    EventManager(vector<vector<int>>& events) {
        for(auto it: events) {
            eventPriority[it[0]] = it[1];
            priority[it[1]].insert(it[0]);
        }
    }
    
    void updatePriority(int eventId, int newPriority) {
        int oldPriority = eventPriority[eventId];
        eventPriority[eventId] = newPriority;

        priority[oldPriority].erase(eventId);
        if(priority[oldPriority].size() == 0) {
            priority.erase(oldPriority);
        }
        priority[newPriority].insert(eventId);
        
        return;
    }
    
    int pollHighest() {
        if(priority.size() == 0) {
            return -1;
        }

        auto& it = *priority.rbegin();
        auto eventId = *it.second.begin();
        it.second.erase(eventId);
        if(it.second.size() == 0) {
            priority.erase(it.first);
        }
        eventPriority.erase(eventId);
        return eventId;
    }
};

/**
 * Your EventManager object will be instantiated and called as such:
 * EventManager* obj = new EventManager(events);
 * obj->updatePriority(eventId,newPriority);
 * int param_2 = obj->pollHighest();
 */