//TrafficSimulator.cpp - main function for simulating traffic

#include <windows.h>//Sleep()
#include "Car.h"

using namespace std;

void DrawMap(Car* carWE[], Car* carSN[], int num_cars, TrafficLight* lightWE[], TrafficLight* lightSN[]);

int main() {
	TrafficLight* trafficLightWE[NUM_LIGHTS];
	TrafficLight light1(1, 25, LightState::Green);
	TrafficLight light2(49, 25, LightState::Green);
	TrafficLight lightEndWE(1000, 25, LightState::Green);//fictitious next light
	trafficLightWE[0] = &light1;
	trafficLightWE[1] = &light2;
	trafficLightWE[2] = &lightEndWE;

	TrafficLight* trafficLightSN[NUM_LIGHTS];
	TrafficLight light6(50, 6, LightState::Red);
	TrafficLight light7(50, 24, LightState::Red);
	TrafficLight lightEndSN(50, 1000, LightState::Green);//fictitious next light
	trafficLightSN[0] = &light6;
	trafficLightSN[1] = &light7;
	trafficLightSN[2] = &lightEndSN;

	const int NUM_CARS = 10;
	Car* carWE[NUM_CARS];
	Car EndCarWE("EndCarWE", 1000, 50, 0, Direction::WestEast, nullptr, trafficLightWE);//ficticious next car for car1
	Car car1("Car1", 50, 25, 1, Direction::WestEast, &EndCarWE, trafficLightWE);
	Car car2("Car2", 45, 25, 1, Direction::WestEast, &car1, trafficLightWE);
	Car car3("Car3", 40, 25, 1, Direction::WestEast, &car2, trafficLightWE);
	Car car4("Car4", 35, 25, 1, Direction::WestEast, &car3, trafficLightWE);
	Car car5("Car5", 30, 25, 1, Direction::WestEast, &car4, trafficLightWE);
	Car car6("Car6", 25, 25, 1, Direction::WestEast, &car5, trafficLightWE);
	Car car7("Car7", 20, 25, 1, Direction::WestEast, &car6, trafficLightWE);
	Car car8("Car8", 15, 25, 1, Direction::WestEast, &car7, trafficLightWE);
	Car car9("Car9", 10, 25, 1, Direction::WestEast, &car8, trafficLightWE);
	Car car10("Car10", 5, 25, 1, Direction::WestEast, &car9, trafficLightWE);
	carWE[0] = &car1;
	carWE[1] = &car2;
	carWE[2] = &car3;
	carWE[3] = &car4;
	carWE[4] = &car5;
	carWE[5] = &car6;
	carWE[6] = &car7;
	carWE[7] = &car8;
	carWE[8] = &car9;
	carWE[9] = &car10;

	Car* carSN[NUM_CARS];
	Car EndCarSN("EndCarSN", 50, 1000, 0, Direction::NorthSouth, nullptr, trafficLightSN);//ficticious next car for car11
	Car car11("Car11", 50, 20, 1, Direction::NorthSouth, &EndCarSN, trafficLightSN);
	Car car12("Car12", 50, 18, 1, Direction::NorthSouth, &car11, trafficLightSN);
	Car car13("Car13", 50, 16, 1, Direction::NorthSouth, &car12, trafficLightSN);
	Car car14("Car14", 50, 14, 1, Direction::NorthSouth, &car13, trafficLightSN);
	Car car15("Car15", 50, 12, 1, Direction::NorthSouth, &car14, trafficLightSN);
	Car car16("Car16", 50, 10, 1, Direction::NorthSouth, &car15, trafficLightSN);
	Car car17("Car17", 50, 8, 1, Direction::NorthSouth, &car16, trafficLightSN);
	Car car18("Car18", 50, 6, 1, Direction::NorthSouth, &car17, trafficLightSN);
	Car car19("Car19", 50, 4, 1, Direction::NorthSouth, &car18, trafficLightSN);
	Car car20("Car20", 50, 2, 1, Direction::NorthSouth, &car19, trafficLightSN);
	carSN[0] = &car11;
	carSN[1] = &car12;
	carSN[2] = &car13;
	carSN[3] = &car14;
	carSN[4] = &car15;
	carSN[5] = &car16;
	carSN[6] = &car17;
	carSN[7] = &car18;
	carSN[8] = &car19;
	carSN[9] = &car20;

	const double timeStep = 1;
	double time = 0.0;
	double endTime = 360.00;//10 minutes

	for (time = 0.0; time < endTime; time += timeStep) {
		for (int i = 0; i < NUM_CARS; ++i) {
			carWE[i]->Travel(timeStep);
		}
		for (int i = 0; i < NUM_CARS; ++i) {
			carSN[i]->Travel(timeStep);
		}
		for (int i = 0; i < NUM_LIGHTS; ++i) {
			trafficLightWE[i]->Travel(timeStep);
		}
		for (int i = 0; i < NUM_LIGHTS; ++i) {
			trafficLightSN[i]->Travel(timeStep);
		}
		DrawMap(carWE, carSN, NUM_CARS, trafficLightWE, trafficLightSN);
		Sleep(1000);//sleep for 1s
	}

	return 0;
}

void DrawMap(Car* carWE[], Car* carSN[], int num_cars, TrafficLight* lightWE[], TrafficLight* lightSN[]) {
	system("Cls");
	for (int y = 0; y < 50; ++y) {//row by row
		cout << endl;
		for (int x = 0; x < 100; ++x) {//left to right
			cout << " ";
			for (int i = 0; i < num_cars; ++i) {//check the cars going W to E
				if (y <= carWE[i]->GetYPos() && (y + 1) > carWE[i]->GetYPos() && x <= carWE[i]->GetXPos() && (x + 1) > carWE[i]->GetXPos()) {
					cout << "X";
					++x;
				}
			}
			for (int i = 0; i < num_cars; ++i) {//check the cars going S to N
				if (y <= carSN[i]->GetYPos() && (y + 1) > carSN[i]->GetYPos() && x <= carSN[i]->GetXPos() && (x + 1) > carSN[i]->GetXPos()) {
					cout << "Y";
					++x;
				}
			}
			for (int i = 0; i < NUM_LIGHTS; ++i) {//check the W E lights
				if (y <= lightWE[i]->GetYPos() && (y + 1) > lightWE[i]->GetYPos() && x <= lightWE[i]->GetXPos() && (x + 1) > lightWE[i]->GetXPos()) {
					lightWE[i]->DrawLight();
					++x;
				}
			}
			for (int i = 0; i < NUM_LIGHTS; ++i) {//check the S N lights
				if (y <= lightSN[i]->GetYPos() && (y + 1) > lightSN[i]->GetYPos() && x <= lightSN[i]->GetXPos() && (x + 1) > lightSN[i]->GetXPos()) {
					lightSN[i]->DrawLight();
					++x;
				}
			}
		}
	}
}


