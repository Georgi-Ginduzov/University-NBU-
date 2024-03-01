
class Fruit {

public:
	void eat() const;
	Fruit(bool hasSeedsOrPits, bool isPoisonous, double sugarPercentage);
private:
	bool hasSeedsOrPits;
	bool isPoisonous;
	double sugarPercentage;
};

