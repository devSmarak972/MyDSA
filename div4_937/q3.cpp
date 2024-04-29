#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

string convertTo12HourFormat(const string& timeStr) {
    // Parse hour and minute
    int hour = stoi(timeStr.substr(0, 2));
    int minute = stoi(timeStr.substr(3));

    //  AM or PM
    string meridiem = (hour < 12) ? "AM" : "PM";

    // Convert hour to 12-hour format
    if (hour == 0) {
        hour = 12;
    } else if (hour > 12) {
        hour -= 12;
    }

    stringstream ss;
    ss << setw(2) << setfill('0') << hour << ":" << setw(2) << setfill('0') << minute << " " << meridiem;
    return ss.str();
}

int main() {
    int t;
    cin >> t; // Input number of test cases

    for (int i = 0; i < t; ++i) {
        string timeStr;
        cin >> timeStr; // Input time in 24-hour format

        cout << convertTo12HourFormat(timeStr) << endl;
    }

    return 0;
}
