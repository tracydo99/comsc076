#include <iostream>
#include <string>

using namespace std;

enum class Month {
    January, February, March, April,
    May, June, July, August,
    September, October, November, December
};

class Date
{
private:
    Month month;
    int day;
    int year;

public:
    void setMonth(int m);
    void setDay(int d);
    void setYear(int y);
    void format1() const;
    void format2() const;
    void format3() const;
};

void Date::setMonth(int m)
{
    while (m < 1 || m > 12)
    {
        cout << "Error. Please enter a valid number for the month (1-12): ";
        cin >> m;
    }
    month = static_cast<Month>(m - 1);  // Convert to enum class Month
}

void Date::setDay(int d)
{
    while (d < 1 || d > 31)
    {
        cout << "Error. Please enter a valid number for the day (1-31): ";
        cin >> d;
    }
    day = d;
}

void Date::setYear(int y)
{
    year = y;
}

void Date::format1() const
{
    cout << static_cast<int>(month) + 1 << "/" << day << "/" << year << endl;
}

void Date::format2() const
{
    static const char* monthNames[] = {
        "January", "February", "March", "April",
        "May", "June", "July", "August",
        "September", "October", "November", "December"
    };

    cout << monthNames[static_cast<int>(month)] << " " << day << ", " << year << endl;
}

void Date::format3() const
{
    static const char* monthNames[] = {
        "January", "February", "March", "April",
        "May", "June", "July", "August",
        "September", "October", "November", "December"
    };

    cout << day << " " << monthNames[static_cast<int>(month)] << " " << year << endl;
}

int main()
{
    Date input;
    int input_month;
    int input_day;
    int input_year;

    cout << "Enter the month: ";
    cin >> input_month;
    input.setMonth(input_month);

    cout << "Enter the day: ";
    cin >> input_day;
    input.setDay(input_day);

    cout << "Enter the year: ";
    cin >> input_year;
    input.setYear(input_year);

    input.format1();
    input.format2();
    input.format3();

    return 0;
}
