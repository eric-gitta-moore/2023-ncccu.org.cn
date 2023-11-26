#include <iostream>

class Time {
private:
    int hours;
    int minutes;
    int seconds;

public:
    Time(int h, int m, int s) : hours(h), minutes(m), seconds(s) {}

    // 加法运算
    Time operator+(const Time& other) const {
        Time result(0, 0, 0);
        result.seconds = (seconds + other.seconds) % 60;
        result.minutes = (minutes + other.minutes + (seconds + other.seconds) / 60) % 60;
        result.hours = (hours + other.hours + (minutes + other.minutes + (seconds + other.seconds) / 60) / 60) % 24;
        return result;
    }

    // 减法运算
    Time operator-(const Time& other) const {
        Time result(0, 0, 0);
        int totalSeconds1 = hours * 3600 + minutes * 60 + seconds;
        int totalSeconds2 = other.hours * 3600 + other.minutes * 60 + other.seconds;
        int diffSeconds = (totalSeconds1 - totalSeconds2 + 86400) % 86400;

        result.seconds = diffSeconds % 60;
        result.minutes = (diffSeconds / 60) % 60;
        result.hours = diffSeconds / 3600;

        return result;
    }

    // 显示时间
    void displayTime(bool is12HourFormat) const {
        int displayHours = is12HourFormat ? (hours % 12 == 0 ? 12 : hours % 12) : hours;
        std::string amPmIndicator = (hours < 12) ? "AM" : "PM";

        printf("%02d:%02d:%02d", displayHours, minutes, seconds);
        if (is12HourFormat) {
            std::cout << " " << amPmIndicator;
        }
        std::cout << std::endl;
    }
};

int main() {
//    std::freopen("in", "r", stdin);
    int initialHours, initialMinutes, initialSeconds;
    int addHours, addMinutes, addSeconds;
    int subtractHours, subtractMinutes, subtractSeconds;

    std::cin >> initialHours >> initialMinutes >> initialSeconds;

    std::cin >> addHours >> addMinutes >> addSeconds;

    std::cin >> subtractHours >> subtractMinutes >> subtractSeconds;

    Time t1(initialHours, initialMinutes, initialSeconds);
    Time t2 = t1 + Time(addHours, addMinutes, addSeconds);
    Time t3 = t2 - Time(subtractHours, subtractMinutes, subtractSeconds);

    t1.displayTime(true);
    t1.displayTime(false);

    t2.displayTime(true);
    t2.displayTime(false);

    t3.displayTime(true);
    t3.displayTime(false);

    return 0;
}
