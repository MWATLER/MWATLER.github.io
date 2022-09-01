#define _CRT_SECURE_NO_WARNINGS
#define NUM 3
#include "math.h"
#include <stdio.h>

struct GeoData {
	char name[31];
	double latitude;
	double longitude;
	double waveAmplitude;
	double richterScale;
};

int CalculateRichterScale(struct GeoData *geo);

int main(void) {
	struct GeoData city[NUM];
	double largestAmplitude = 0;
	int index = -1;

	for (int i = 0; i < NUM; ++i) {
		printf("Enter the city name: ");
		scanf("%30s", city[i].name);
		printf("Enter the latitude and longitude separated by a space: ");
		scanf("%lf %lf", &city[i].longitude, &city[i].latitude);
		printf("Enter the wave Amplitude in millimeters: ");
		scanf("%lf", &city[i].waveAmplitude);
 		int err = CalculateRichterScale(&city[i]);
		if (err==0 && city[i].waveAmplitude > largestAmplitude) {
			largestAmplitude = city[i].waveAmplitude;
			index = i;
		}
	}

	printf("The city with the largest tremor is %s at latitude %.2lf and longitude %.2lf\n",
		city[index].name, city[index].latitude, city[index].longitude);
	printf("The tremor measured %.2lfmm which is %.2lf on the Richter scale\n",
		city[index].waveAmplitude, city[index].richterScale);
}

int CalculateRichterScale(struct GeoData *geo) {
	int retVal = 0;
	if (geo->waveAmplitude < 0) {
		geo->richterScale = 0;
		retVal = -1;
	}
	else {
		geo->richterScale = sqrt(geo->waveAmplitude);
	}
	return retVal;
}