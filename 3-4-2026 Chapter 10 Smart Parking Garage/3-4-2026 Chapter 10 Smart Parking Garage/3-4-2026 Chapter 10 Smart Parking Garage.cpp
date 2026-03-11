// 3-4-2026 Chapter 10 Smart Parking Garage
#include <iostream>
using namespace std;

enum ParkingSpot_Status
{
	EMPTY,
	OCCUPIED,
	RESERVED
};

char status_to_char(ParkingSpot_Status s)
{
	if (s == EMPTY)
	{
		return 'E';
	}
	else if (s == OCCUPIED)
	{
		return 'O';
	}
	else
	{
		return 'R';
	}
}


void print_garage_map(const ParkingSpot_Status garage[3][4]);
int count_empty_spots(const ParkingSpot_Status garage[3][4]);


class Parking_Garage
{
	private:
		ParkingSpot_Status garage[3][4];
		int parked_count[3];

		bool is_valid_index(int floor, int spot)
		{
			return (floor >= 0 && floor < 3 && spot >= 0 && spot < 4);
		}

	public:
		Parking_Garage()
	{
		for (int row = 0; row < 3; row++)
		{
			for (int col = 0; col < 4; col++)
			{
				garage[row][col] = EMPTY;
			}
		}

		for (int parked_index = 0; parked_index < 3; parked_index++)
		{
			parked_count[parked_index] = 0;
		}

		garage[0][0] = RESERVED;
	}

		bool set_spot_status(int floor, int spot, ParkingSpot_Status new_status)
	{
		if (!is_valid_index(floor, spot))
		{
			cout << "Invalid Location!" << endl;
			return false;
		}

		if (floor == 0 && spot == 0)
		{
			cout << "Spot (0,0) is already reserved!" << endl;
			return false;
		}

		ParkingSpot_Status current_status = garage[floor][spot];

		if (new_status == OCCUPIED)
		{
			if (current_status == EMPTY)
			{
				garage[floor][spot] = OCCUPIED;
				parked_count[floor]++;
				return true;
			}
			else
			{
				cout << "Cannot park here!" << endl;
				return false;
			}
		}

		if (new_status == EMPTY)
		{
			if (current_status == OCCUPIED)
			{
				garage[floor][spot] = EMPTY;
				parked_count[floor]--;
				return true;
			}
			else
			{
				cout << "Cannot leave here!" << endl;
				return false;
			}
		}

		if (new_status == RESERVED)
		{
			if (current_status == EMPTY)
			{
				garage[floor][spot] = RESERVED;
				return true;
			}
			else
			{
				cout << "Cannot reserve here!" << endl;
				return false;
			}
		}

		return false;
	}

		ParkingSpot_Status get_spot_status(int floor, int spot)
	{
		return garage[floor][spot];
	}

		int get_parked_count(int floor)
	{
		if (floor < 0 || floor >= 3)
		{
			return 0;
		}

		return parked_count[floor];
	}

		void print_map()
		{
			print_garage_map(garage);
		}

		int total_empty_spots()
		{
			return count_empty_spots(garage);
		}
};

int main()
{
	Parking_Garage garage;

	int num_of_opps;

	cout << "Enter Number of Opperations: ";
	cin >> num_of_opps;

	for (int index = 0; index < num_of_opps; index++)
	{
		char opps;
		int floor;
		int spot;

		cout << "Enter Opperation (P, L, R), floor #, Spot #: ";
		cin >> opps >> floor >> spot;

		if (opps == 'P')
		{
			garage.set_spot_status(floor, spot, OCCUPIED);
		}
		else if (opps == 'L')
		{
			garage.set_spot_status(floor, spot, EMPTY);
		}
		else if (opps == 'R')
		{
			garage.set_spot_status(floor, spot, RESERVED);
		}
		else
		{
			cout << "Invalid opperation!" << endl;
		}
	}

	garage.print_map();

	cout << "Parked count per floor: " << endl;

	for (int floor = 0; floor < 3; floor++)
	{
		cout << "Floor " << floor + 1 << ": " << garage.get_parked_count(floor) << endl;
	}

	cout << "Total empty seats: " << garage.total_empty_spots() << endl;

	return 0;
}

void print_garage_map(const ParkingSpot_Status garage[3][4])
{
	cout << "Garage Map: " << endl;

	for (int floor = 0; floor < 3; floor++)
	{
		for (int spot = 0; spot < 4; spot++)
		{
			cout << status_to_char(garage[floor][spot]) << " ";
		}
		cout << endl;
	}
}

int count_empty_spots(const ParkingSpot_Status garage[3][4])
{
	int empty_count = 0;

	for (int floor = 0; floor < 3; floor++)
	{
		for (int spot = 0; spot < 4; spot++)
		{
			if (garage[floor][spot] == EMPTY)
			{
				empty_count++;
			}
		}
	}

	return empty_count;
}