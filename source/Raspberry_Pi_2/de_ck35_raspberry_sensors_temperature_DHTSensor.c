#include <stdio.h>
#include "de_ck35_raspberry_sensors_temperature_DHTSensor.h"
#include "pi_2_dht_read.h"
#include "../common_dht_read.h"

JNIEXPORT jfloatArray JNICALL Java_de_ck35_raspberry_sensors_temperature_DHTSensor_readNative(JNIEnv *env, jobject object, jint sensorId, jint gpioPin) {

        float temperature;
	float humidity;

	int callResult = pi_2_dht_read(sensorId, gpioPin, &humidity, &temperature);
	
	if (callResult != DHT_SUCCESS) {
		return NULL;
        }
	
	float values[2] = { temperature, humidity };
        jfloatArray result = (*env) -> NewFloatArray(env, 2);
        (*env) -> SetFloatArrayRegion(env, result, 0, 2, values);
        return result;
        
}

