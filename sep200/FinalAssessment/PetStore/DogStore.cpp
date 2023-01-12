//DogStore.cpp - main function for a dog store
//
#include <iostream>
#include "Owner.h"
#include "Dog.h"

using namespace std;

void Purchase(Owner& owner, Dog& dog) {
	owner.AddDog(dog);
	dog.SetOwner(owner);
}

int main() {
	Owner owner1("Michael Hagley", "14 Brentwood Terrace");
	Owner owner2("Oliver Walter", "299 Mill Road");
	Dog dog1("Cheeto", 5, 2000.00);
	Dog dog2("Mavrick", 8, 1800.00);
	Dog dog3("Biglet", 4, 2100.00);
	Dog dog4("Snoopy", 11, 600.00);
	Dog dog5("Leggo", 2, 500.00);
	Dog dog6("Bugsy", 4, 1100.00);

	Purchase(owner1, dog1);
	Purchase(owner1, dog5);
	Purchase(owner2, dog2);
	Purchase(owner2, dog3);
	Purchase(owner2, dog6);

	cout << owner1;
	cout << owner2;

	Owner* owner = dog1.GetOwner();
	if (owner) cout << dog1.GetName() << " belongs to " << owner->GetName() << endl;

	owner = dog4.GetOwner();
	if (owner) cout << dog4.GetName() << " belongs to " << owner->GetName() << endl;

	return 0;
}