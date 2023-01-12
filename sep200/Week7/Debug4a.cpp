#include <iostream>
using namespace std;
class Rain {
public:
  virtual void windSpeed(int amount) = 0;

  virtual ~Rain() {
  }
};
class Hurricane : public Rain {
  double speed;
public:
  Hurricane(double vel)  {
    speed = vel;
  }
  void windSpeed(int value) {
    speed = value;
  }
  ~Hurricane() {
  }
};
int main() {
  Rain* rain[2];
  rain[0] = new Hurricane(66.5);
  rain[1] = new Rain();
  for (int i = 0; i < 2; ++i) {
      rain[i]->windSpeed((double)110.0);
  }
  
  for(int i=0; i<2; ++i)
      delete rain[i];

  return 0;
}
















/* ANSWER */
/* Rain is an abstract class. You cannot create an object of an abstract class. */
