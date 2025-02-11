#include <iostream>
using namespace std;

int sensorStatus = 0;  // Declaring the sensor status as volatile

void checkSensor() {
    if (sensorStatus == 1) {
        cout << "Sensor is active!" << endl;
    }
}

int main() {
    // Simulate hardware setting the sensor status to 1 (interrupt or external change)
    sensorStatus = 1;
    checkSensor();  // Output: Sensor is active!
    return 0;
}
