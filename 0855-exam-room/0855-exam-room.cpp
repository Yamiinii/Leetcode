#include <set>
#include <queue>
#include <vector>
#include <algorithm>

class ExamRoom {
public:
    ExamRoom(int n) : n(n) {}

    int seat() {
        // If no students are seated, the first student sits at seat 0
        if (occupied.empty()) {
            occupied.insert(0);
            return 0;
        }

        // Initialize the maximum gap
        int max_distance = 0;
        int seat_to_take = 0;

        // Check the gap from the start to the first occupied seat
        auto it = occupied.begin();
        int first_seat = *it;
        max_distance = first_seat;
        seat_to_take = 0;

        // Check gaps between occupied seats
        int prev = -1;
        for (it = occupied.begin(); it != occupied.end(); ++it) {
            if (prev != -1) {
                int current_seat = *it;
                int distance = (current_seat - prev) / 2;
                if (distance > max_distance) {
                    max_distance = distance;
                    seat_to_take = prev + distance;
                }
            }
            prev = *it;
        }

        // Check the gap from the last occupied seat to the end
        int last_seat = *(--occupied.end());
        if (n - 1 - last_seat > max_distance) {
            seat_to_take = n - 1;
        }

        // Seat the student
        occupied.insert(seat_to_take);
        return seat_to_take;
    }

    void leave(int p) {
        occupied.erase(p);
    }

private:
    int n;  // Number of seats
    std::set<int> occupied;  // To keep track of occupied seats
};

