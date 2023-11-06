#include <map>

class SeatManager {
public:
    std::map<int, int> dq;
    int n;

    SeatManager(int n) {
        this->n = n;
        for (int i = 1; i <= n; i++) {
            dq[i] = 0;
        }
    }

    int reserve() {
        if (dq.empty()) {
            return -1; // No available seats
        }
        
        auto it = dq.begin();
        int seatNumber = it->first;
        dq.erase(it);
        return seatNumber;
    }

    void unreserve(int seatNumber) {
        dq[seatNumber] = 0;
    }
};
