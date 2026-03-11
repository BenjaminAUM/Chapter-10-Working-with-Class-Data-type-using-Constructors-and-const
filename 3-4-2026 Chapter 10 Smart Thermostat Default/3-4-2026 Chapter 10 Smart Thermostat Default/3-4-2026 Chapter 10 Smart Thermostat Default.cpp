// 3-4-2026 Chapter 10 Smart Thermostat Default
#include <iostream>
using namespace std;

class Thermostat
{
private:
	int temperature;

public:
	Thermostat()
	{
		temperature = 24;
	}

	void setTemp(int temp)
	{
		if (temp < 16 || temp > 30)
		{
			cout << "Invalid temperature!" << endl;
			return;
		}
		else
		{
			temperature = temp;
		}
	}

	int getTemp()
	{
		return temperature;
	}
};

int main()
{
	Thermostat temp_1;
	int user_input;

	cout << "Current temp: " << temp_1.getTemp() << endl;

	cout << "Enter new temp (16 - 30): ";
	cin >> user_input;

	temp_1.setTemp(user_input);

	cout << "New temp: " << temp_1.getTemp() << endl;
	
	return 0;
}