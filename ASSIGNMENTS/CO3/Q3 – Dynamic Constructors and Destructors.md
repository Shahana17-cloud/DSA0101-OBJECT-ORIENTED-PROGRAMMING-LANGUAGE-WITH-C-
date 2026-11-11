#include <iostream>
#include <string>
using namespace std;

class Event {
    string name;
    int rows, seatsPerRow;
    bool** seats;
    int booked;

public:
    Event(const string& n, int r, int s)
        : name(n), rows(r), seatsPerRow(s),
          seats(nullptr), booked(0) {

        if (rows < 0 || seatsPerRow < 0)
            throw invalid_argument("Invalid seat dimensions");

        if (rows > 0 && seatsPerRow > 0) {
            seats = new bool*[rows]();

            try {
                for (int i = 0; i < rows; i++)
                    seats[i] = new bool[seatsPerRow]();
            }
            catch (...) {
                for (int i = 0; i < rows; i++)
                    delete[] seats[i];

                delete[] seats;
                throw;
            }
        }

        cout << "Created: " << name << '\n';
    }

    bool book(int r, int s) {
        if (r < 0 || r >= rows ||
            s < 0 || s >= seatsPerRow)
            return false;

        if (seats[r][s])
            return false;

        seats[r][s] = true;
        booked++;
        return true;
    }

    bool cancel(int r, int s) {
        if (r < 0 || r >= rows ||
            s < 0 || s >= seatsPerRow)
            return false;

        if (!seats[r][s])
            return false;

        seats[r][s] = false;
        booked--;
        return true;
    }

    void summary() const {
        cout << name << ": "
             << booked << " seat(s) booked\n";
    }

    ~Event() {
        for (int i = 0; i < rows; i++)
            delete[] seats[i];

        delete[] seats;

        cout << "Closed: ";
        summary();
    }
};

int main() {
    Event stackEvent("Stack Event", 2, 3);

    stackEvent.book(0, 1);
    stackEvent.book(1, 2);
    stackEvent.cancel(0, 1);

    {
        Event blockEvent("Block Event", 1, 2);
        blockEvent.book(0, 0);
    }

    Event* heapEvent = new Event("Heap Event", 2, 2);

    heapEvent->book(1, 1);

    delete heapEvent;

    Event zeroEvent("Zero Row Event", 0, 5);

    cout << "Zero-row booking: "
         << zeroEvent.book(0, 0) << '\n';

    return 0;
}

<img width="254" height="197" alt="image" src="https://github.com/user-attachments/assets/bbfbf616-d99d-4162-8175-db281f246510" />
