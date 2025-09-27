#include <iostream>
using namespace std;

class Population {
private:
    int population;
    int births;
    int deaths;

public:
    Population(int population, int births, int deaths){}

    double birthRate() const {
        return static_cast<double>(births) / population;
    }

    double deathRate() const {
        return static_cast<double>(deaths) / population;
    }
};

int main() {
    int population;
    int births;
    int deaths;

    cout << "Enter the population size: ";
    cin >> population;

    cout << "Enter the number of births: ";
    cin >> births;

    cout << "Enter the number of deaths: ";  // Corrected semicolon to colon
    cin >> deaths;

    Population city(population, births, deaths);

    cout << "Birth Rate: " << city.birthRate() << endl;
    cout << "Death Rate: " << city.deathRate() << endl;

    return 0;
}
