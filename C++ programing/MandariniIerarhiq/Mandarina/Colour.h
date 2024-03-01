#include <string>
using std::string;

class Color {

public:
	string getColor() const;
	void setColor(string color);
private:
	string color;
};

