#include <stdio.h>

int main() {
    char region = 'N';
    int readingID = 145;
    float avgMoisture = 42.75f;
    double lightIntensity = 9876.54321;
    short temperature = 28;
    long totalReadings = 125000L;
    unsigned int threshold = 500;
    unsigned char mode = 0x01;

    printf("Sensor Region: %c\n", region);
    printf("Current Reading ID: %d\n", readingID);
    printf("Average Soil Moisture: %.2f %%\n", avgMoisture);
    printf("Light Intensity: %.5lf lumens\n", lightIntensity);
    printf("Temperature: %hd °C\n", temperature);
    printf("Total Readings Collected: %ld\n", totalReadings);
    printf("Data Send Threshold: %u\n", threshold);
    printf("Sensor Mode Flag: 0x%02X\n", mode);

    return 0;
}
