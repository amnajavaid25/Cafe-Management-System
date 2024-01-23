#pragma once
class table_reservation
{
private:
	static const int totalTables = 16;

	// true if table is booked, false if it's available
	bool tableStatus[totalTables];

public:
	table_reservation();

	void displayAvailableTables()const;

	void bookTable(int tableNumber);

	void displayTableStatus()const;

};

