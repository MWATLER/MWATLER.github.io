//AirplaneManifest.cpp - main code for an airplane manifest

enum class PassengerType
{
    Aircrew,
    AirMarshal,
    flyer
};

struct Passenger
{
    std::string name;
    unsigned weight;
    PassengerType  pType;
};

void byPassengerType(std::ostream& os, const Passenger& passenger)
{
    os << "\nBy Passenger Type";
    switch (passenger.pType)
    {
    case PassengerType::Aircrew:
        os << "Aircrew \n";
        break;
    case PassengerType::AirMarshal:
        os << "AirMarshal \n";
        break;
    case PassengerType::flyer:
        os << "flyer \n";
        break;
    }
}

void byWeight(std::ostream& os, const Passenger& passenger)
{
    os << "\nBy Passenger Weight";
    os << passenger.weight;
}

int main()
{
    Passenger passengers[]
    {
      {"Tommy Douglas   ", 90, PassengerType::Aircrew},
      {"Pierre Trudeau  ", 85, PassengerType::AirMarshal},
      {"Trudeau Jr William  ", 122, PassengerType::Aircrew},
      {"Kim Campbell    ", 80, PassengerType::flyer},
      {"Kathleen William  ", 170, PassengerType::Aircrew},
      {"William King    ", 95, PassengerType::flyer},
      {"Agnes Machail   ", 75, PassengerType::flyer},
      {"Kathleen Wynne  ", 70, PassengerType::Aircrew}
    };

    Manifest* records = new Manifest();
    for (const auto& i : passengers)
        *records += i;

    records->display(byPassengerType);
    records->display(byWeight);
    std::cout << "==========\nWeight of Kim Campbell: " << (*records)["Kim Campbell    "]->weight << std::endl;
    std::cout << "==========\nEnd of Program ...." << std::endl;
    delete records;
}
