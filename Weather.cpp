#include<bits/stdc++.h>
using namespace std;

//Weather modelling using quadratic equations
class Weather {
public:
    // Function to calculate the temperature at a given time using a quadratic equation
    double calculateTemperature(double time) {
        // Example quadratic equation: T(t) = at^2 + bt + c
        double a = 0.1; // Coefficient for t^2
        double b = -2.0; // Coefficient for t
        double c = 20.0; // Constant term

        return a * time * time + b * time + c;
    }
};
// Function to simulate weather over a range of time
void simulateWeather(double startTime, double endTime, double step) {
    Weather weather;
    for (double t = startTime; t <= endTime; t += step) {
        double temperature = weather.calculateTemperature(t);
        cout << "Time: " << t << " Temperature: " << temperature << endl;
    }
}
// Main function to run the weather simulation
int main() {
    double startTime; // Start time in hours
    double endTime; // End time in hours
    double step; // Step size in hours

    // Read start time, end time, and step size from a file
    ifstream inputFile("Weather.txt");
    if (!inputFile) {
        cerr << "Error: could not open Weather.txt for reading\n";
        return 1;
    }
    inputFile >> startTime >> endTime >> step;
    inputFile.close();

    simulateWeather(startTime, endTime, step);
    return 0;
}