#include <iostream>
#include <iomanip>
#include <ctime>
#include <thread>
#include <chrono>
#include <cstring>
#include <sstream>
#include <windows.h>
using namespace std;

// Convert month name to a 0-based month number
int getMonthNumber(const string& month) {
    const string months[] = {
        "January", "February", "March", "April", "May", "June", 
        "July", "August", "September", "October", "November", "December"
    };

    for (int i = 0; i < 12; ++i) {
        if (months[i] == month) return i;
    }
    return -1;  // Return -1 if the month is invalid
}

// Calculate total remaining time in days, hours, minutes, and seconds
void calculateTimeUntilEvent(tm presentDate, tm eventDate, int& days, int& hours, int& minutes, int& seconds) {
    time_t presentTime = mktime(&presentDate);
    time_t eventTime = mktime(&eventDate);
    double totalSeconds = difftime(eventTime, presentTime); // difftime() returns double

    if (totalSeconds < 0) {
        days = hours = minutes = seconds = -1; // Event is in the past
        return;
    }

    int totalSecInt = static_cast<int>(totalSeconds); // Convert double to int

    days = totalSecInt / (60 * 60 * 24);
    hours = (totalSecInt / 3600) % 24;
    minutes = (totalSecInt / 60) % 60;
    seconds = totalSecInt % 60;
}


// Countdown function
void startCountdown(int days, int hours, int minutes, int seconds, const string& eventGreeting) {
    for (int d = days; d >= 0; --d) {
        for (int h = (d == days ? hours : 23); h >= 0; --h) {
            for (int m = (d == days && h == hours ? minutes : 59); m >= 0; --m) {
                for (int s = (d == days && h == hours && m == minutes ? seconds : 59); s >= 0; --s) {
                    cout << d << " days, " 
                         << setfill('0') << setw(2) << h << ":"
                         << setw(2) << m << ":" << setw(2) << s << endl;
                    this_thread::sleep_for(chrono::seconds(1));
                }
            }
        }
    }
    
    // Display alarm message
    cout << endl << eventGreeting << endl;
    Beep(1000, 500); 
    Beep(1200, 500);
    Beep(1400, 500);
    cout << "(Alarm sound)" << endl;
}

int main() {
    string eventName, eventDateStr, eventAlarmTime, eventGreeting;

    cout << "Please input the event schedule." << endl;
    cout << "Event Name: ";
    getline(cin, eventName);
    cout << "Event Date (Month Day, Year): ";
    getline(cin, eventDateStr);
    cout << "Event Alarm Time (HH:MM AM/PM): ";
    getline(cin, eventAlarmTime);
    cout << "Event Greetings: ";
    getline(cin, eventGreeting);

    cout << "Event Schedule starts ..." << endl;

    // Get current date and time
    time_t now = time(0);
    tm presentDate = *localtime(&now);

    // Parse event date
    tm eventDate = {};
    string monthName;
    int day, year;

    istringstream iss(eventDateStr);
    if (!(iss >> monthName >> day) || iss.get() != ',' || !(iss >> year)) {
        cout << "Error: Invalid date format!" << endl;
        return 1;
    }

    eventDate.tm_mon = getMonthNumber(monthName);
    if (eventDate.tm_mon == -1) {
        cout << "Error: Invalid month name!" << endl;
        return 1;
    }
    
    eventDate.tm_mday = day;
    eventDate.tm_year = year - 1900;  // Adjust for tm struct

    // Parse event alarm time
    int alarmHour, alarmMinute;
    char ampm[3];
    if (sscanf(eventAlarmTime.c_str(), "%d:%d %2s", &alarmHour, &alarmMinute, ampm) != 3) {
        cout << "Error: Invalid time format!" << endl;
        return 1;
    }

    if (strcmp(ampm, "PM") == 0 && alarmHour != 12) alarmHour += 12;
    if (strcmp(ampm, "AM") == 0 && alarmHour == 12) alarmHour = 0;

    eventDate.tm_hour = alarmHour;
    eventDate.tm_min = alarmMinute;
    eventDate.tm_sec = 0;

    // Calculate remaining time correctly
    int daysToEvent, hoursToEvent, minutesToEvent, secondsToEvent;
    calculateTimeUntilEvent(presentDate, eventDate, daysToEvent, hoursToEvent, minutesToEvent, secondsToEvent);

    if (daysToEvent < 0) {
        cout << "Error: Event date is in the past!" << endl;
        return 1;
    }

    cout << "Present Date: " << put_time(&presentDate, "%B %d, %Y ") << endl;
    cout << "Present Time: " << put_time(&presentDate, "%I:%M %p (%I:%M)") << endl;
    cout << "Number of Days To Event: " << daysToEvent << " days" << endl;
    cout << "Timer Starts:" << endl;

    startCountdown(daysToEvent, hoursToEvent, minutesToEvent, secondsToEvent, eventGreeting);

    return 0;
}
