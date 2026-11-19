#include <iostream>
#include <stdexcept>
using namespace std;

void validate(double amount) {
    if (amount < 0)
        throw invalid_argument("negative amount");

    if (amount > 1000000)
        throw out_of_range("too large");

    cout << "ok ";
}

void process(double amount) {
    try {
        validate(amount);
    }
    catch (const out_of_range& e) {
        cout << "log " << e.what() << " ";
        throw;
    }
}

int main() {
    double amounts[] = {100, -5, 2000000};

    for (double a : amounts) {
        try {
            process(a);
            cout << "done";
        }
        catch (const exception& e) {
            cout << "caught " << e.what();
        }

        cout << endl;
    }

    try {
        throw bad_alloc();
    }
    catch (const bad_alloc&) {

    
        cout << "caught memory allocation failure" << endl;
    }

    return 0;
}


<img width="224" height="99" alt="image" src="https://github.com/user-attachments/assets/3e778f87-3d3f-42de-a817-b2e58c92d83c" />
