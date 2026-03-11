// 3-4-2026 Chapter 10 Ride Sharing Trip Fare
#include <iostream>
using namespace std;

class Trip
{
	private:
		float distance_km;
		float rate_per_km;

	public:
		Trip()
		{
			distance_km = 0;
			rate_per_km = 12.5;
		}

		void set_distance_km(int distance)
		{
			if (distance >= 0)
			{
				distance_km = distance;
			}
			else
			{
				cout << "Invalid distance! must be greater than 0" << endl;
				return;
			}
		}

		void set_rate_per_km(int rate)
		{
			if (rate < 0)
			{
				cout << "Invalid rate! must be greater than 0" << endl;
				return;
			}
			else
			{
				rate_per_km = rate;
			}
		}

		int get_fare()
		{
			return distance_km * rate_per_km;
		}
};

int main()
{
	Trip trip;
	float distance_input;
	float rate_input;

	cout << "Enter distance traveled: ";
	cin >> distance_input;

	cout << "Enter new rate: ";
	cin >> rate_input;

	trip.set_distance_km(distance_input);
	trip.set_rate_per_km(rate_input);

	cout.setf(ios::fixed);
	cout.precision(2);

	cout << "Total Fare: " << trip.get_fare() << endl;
}