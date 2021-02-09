#include <i2c_t3.h>
#include <SFE_BMP180.h>
#include <SFE_BMP180_2.h>

float get_pressure(SFE_BMP180 sensor) {
    char status;
    double T, P, p0, a;

    // Sensor 1
    status = sensor.startTemperature();
    if (status != 0)
    {
        // Wait for the measurement to complete:
        delay(status);

        // Retrieve the completed temperature measurement:
        // Note that the measurement is stored in the variable T.
        // Function returns 1 if successful, 0 if failure.

        status = sensor.getTemperature(T);
        if (status != 0)
        {

            // Start a pressure measurement:
            // The parameter is the oversampling setting, from 0 to 3 (highest res, longest wait).
            // If request is successful, the number of ms to wait is returned.
            // If request is unsuccessful, 0 is returned.

            status = sensor.startPressure(3);
            if (status != 0)
            {
                // Wait for the measurement to complete:
                delay(status);

                // Retrieve the completed pressure measurement:
                // Note that the measurement is stored in the variable P.
                // Note also that the function requires the previous temperature measurement (T).
                // (If temperature is stable, you can do one temperature measurement for a number of pressure measurements.)
                // Function returns 1 if successful, 0 if failure.

                status = sensor.getPressure(P, T);
                if (status != 0)
                {
                    return P;
                }
                else return -1;
            }
            else return -1;
        }
        else return -1;
    }
    else return -1;
}

float get_pressure(SFE_BMP180_2 sensor) {
    char status;
    double T, P, p0, a;

    // Sensor 1
    status = sensor.startTemperature();
    if (status != 0)
    {
        // Wait for the measurement to complete:
        delay(status);

        // Retrieve the completed temperature measurement:
        // Note that the measurement is stored in the variable T.
        // Function returns 1 if successful, 0 if failure.

        status = sensor.getTemperature(T);
        if (status != 0)
        {

            // Start a pressure measurement:
            // The parameter is the oversampling setting, from 0 to 3 (highest res, longest wait).
            // If request is successful, the number of ms to wait is returned.
            // If request is unsuccessful, 0 is returned.

            status = sensor.startPressure(3);
            if (status != 0)
            {
                // Wait for the measurement to complete:
                delay(status);

                // Retrieve the completed pressure measurement:
                // Note that the measurement is stored in the variable P.
                // Note also that the function requires the previous temperature measurement (T).
                // (If temperature is stable, you can do one temperature measurement for a number of pressure measurements.)
                // Function returns 1 if successful, 0 if failure.

                status = sensor.getPressure(P, T);
                if (status != 0)
                {
                    return P;
                }
                else return -1;
            }
            else return -1;
        }
        else return -1;
    }
    else return -1;
}