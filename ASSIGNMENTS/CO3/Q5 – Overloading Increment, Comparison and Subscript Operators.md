#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>
using namespace std;

class Time {
    int seconds;

public:
    Time(int s = 0)
        : seconds((s % 86400 + 86400) % 86400) {}

    // Prefix increment
    Time& operator++() {
        seconds = (seconds + 1) % 86400;
        return *this;
    }

    // Postfix increment
    Time operator++(int) {
        Time old = *this;
        ++(*this);
        return old;
    }

    bool operator==(const Time& t) const {
        return seconds == t.seconds;
    }

    bool operator<(const Time& t) const {
        return seconds < t.seconds;
    }

    friend ostream& operator<<(ostream& out, const Time& t) {
        int h = t.seconds / 3600;
        int m = (t.seconds / 60) % 60;
        int s = t.seconds % 60;

        if (h < 10) out << "0";
        out << h << ":";

        if (m < 10) out << "0";
        out << m << ":";

        if (s < 10) out << "0";
        out << s;

        return out;
    }
};

class Playlist {
    vector<string> tracks;

public:
    Playlist(initializer_list<string> t) : tracks(t) {}

    string& operator[](int i) {
        if (i < 0 || i >= (int)tracks.size())
            throw out_of_range("Playlist index out of range");

        return tracks[i];
    }

    const string& operator[](int i) const {
        if (i < 0 || i >= (int)tracks.size())
            throw out_of_range("Playlist index out of range");

        return tracks[i];
    }

    int size() const {
        return tracks.size();
    }
};

int main() {
    Time t(3599);

    Time a = t++;
    Time b = ++t;

    cout << "a=" << a
         << ", b=" << b
         << ", t=" << t << '\n';

    Time last(59 * 60 + 59);
    ++last;

    cout << "Rollover: " << last << '\n';

    Playlist playlist{"Song A", "Song B", "Song C"};

    for (int i = 0; i < playlist.size(); i++)
        cout << i << ": " << playlist[i] << '\n';

    try {
        cout << playlist[-1] << '\n';
    }
    catch (const out_of_range& e) {
        cout << e.what() << '\n';
    }

    try {
        cout << playlist[playlist.size()] << '\n';
    }
    catch (const out_of_range& e) {
        cout << e.what() << '\n';
    }

    return 0;
}

<img width="298" height="177" alt="image" src="https://github.com/user-attachments/assets/b9478ab4-c57d-400b-9e25-1f50a21fc2ef" />
