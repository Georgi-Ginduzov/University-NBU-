#include <iostream>

class Fruit
{
private:
	std::string name;
	int otKogaEOtkusnat;
	float weight;
	bool isBio;

public:
	Fruit() {
		name = "";
		otKogaEOtkusnat = 0;
		weight = 0;
		isBio = false;
	}

	Fruit(std::string name, int otKogaEOtkusnat, float weight, bool isBio) {

	}

	~Fruit() {

	}

	void setName(std::string name) {
		this->name = name;
	}
	void setOtKogaEOtkusnat(int otKogaEOtkusnat) {
		this->otKogaEOtkusnat = otKogaEOtkusnat;
	}
	void setWeight(float weight) {
		this->weight = weight;
	}
	void setisBio(bool isBio) {
		this->isBio = isBio;
	}

	std::string getName() {
		return this->name;
	}
	int getOtKogaEOtkusnat() {
		return this->otKogaEOtkusnat;
	}
	float getWeight() {
		return this->weight;
	}
	bool getIsBio() {
		return this->isBio;
	}

	friend std::ostream& operator<<(std::ostream& out, const Fruit& fruit) {
		out << fruit.name << " is grasped " << fruit.otKogaEOtkusnat << " and weights " << fruit.weight << " and is ";
		if (fruit.isBio == false)
		{
			out << " not bio\n";
		}
		else
		{
			out << " bio\n";
		}
	}
	friend std::istream& operator>>(std::istream& in, Fruit& fruit) {
		std::string name;
		in >> name;
		fruit.setName(name);

		int isGraspedInDays;
		in >> isGraspedInDays;
		fruit.setOtKogaEOtkusnat(isGraspedInDays);

		float weight;
		in >> weight;
		fruit.setWeight(weight);

		bool isBio;
		in >> isBio;
		fruit.setisBio(isBio);
		
		return in;
	}
};

int main() {

	Fruit a(" ", 0, 0, false);

	std::cin >> a;
	std::cout << a;

	return 0;
}