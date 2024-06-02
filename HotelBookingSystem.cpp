#include<iostream>
#include<string.h>
#include<conio.h>
#define getch() _getch()
using namespace std;
int numOfRoom = 0;
int i, option;
int rn;
int roomFoundatIndex;


class Guest {
protected:
	// data is stored in protected 
	char Address[30];
	int  CnicNumber;
	char FromDate[15];
	char ToDate[15];
	long long int TelNumber;
public:
	char Name[20];
	int AdvancedPayment;

	void getGuestInfo(int);
	void guestShow(int);
	void removeTheRecord(int);

};
class HotelMangment {
public:
	void ManageRoom();
	void Booking();
	void AvailableRoom();
	void SearchGuest();
	void Clearing();
	void GuestSummaryReport();
};
class Room :public HotelMangment, public Guest {
private:
	bool isVip;
	int roomType;
public:
	bool roomStatus; 
	int RoomNumber; 
	int DailyRent; 


	void getInfo();
	int searchRoom(int);
	void show(int);

};
Room room[10];
void Guest::getGuestInfo(int roomFoundatIndex) {
	cout << "\tFull Name: ";

	cin >> room[roomFoundatIndex].Name;
	cin.ignore(20, '\n');
	cout << "\tAddress [just city Name]: ";

	cin >> room[roomFoundatIndex].Address;
	cin.ignore(20, '\n');

	cout << "\tCNIC/Passport Number: ";
	cin >> room[roomFoundatIndex].CnicNumber;
	cout << "\tFrom Date [dd/mm/yyyy]: ";
	cin.ignore(20, '\n');
	
	cin >> room[roomFoundatIndex].FromDate;

	cout << "\tTo Date [dd/mm/yyyy]: ";

	cin.ignore(15, '\n');
	cin >> room[roomFoundatIndex].ToDate;
	cin.ignore(15, '\n');
	cout << "\tContact Number: ";
	cin >> room[roomFoundatIndex].TelNumber;
	cin.ignore(15, '\n');
	cout << "\tAdvanced Payment: ";
	cin >> room[roomFoundatIndex].AdvancedPayment;
}
void Guest::guestShow(int nameFoundAtIndex) {
	cout << endl;
	cout << "\t----------" << endl;

	cout << "\tGuest Name= " << room[nameFoundAtIndex].Name << endl;
	cout << "\tRoom Number= " << room[nameFoundAtIndex].RoomNumber << endl;
	cout << "\tAddres= " << room[nameFoundAtIndex].Address << endl;
	cout << "\tTelephone Number= 0" << room[nameFoundAtIndex].TelNumber << endl;
	cout << "\tAdvanced Payment= " << room[nameFoundAtIndex].AdvancedPayment << " $" << endl;
}
void Guest::removeTheRecord(int roomFoundatIndex) {
	room[roomFoundatIndex].Name[0] = 0;
	room[roomFoundatIndex].Address[0] = 0;
	room[roomFoundatIndex].CnicNumber = 0;
	room[roomFoundatIndex].FromDate[0] = 0;
	room[roomFoundatIndex].ToDate[0] = 0;
	room[roomFoundatIndex].TelNumber = 0;
	room[roomFoundatIndex].AdvancedPayment = 0;
}
void Room::getInfo()
{
	cout << "\n\t*****Room Details*****" << endl;
	cout << "\t Add Room Number: ";
	cin >> RoomNumber;
	roomFoundatIndex = room->searchRoom(RoomNumber);
	if (roomFoundatIndex != -1)
		cout << "\tRoom is already existing " << endl;
	else
	{
		do
		{
			cout << "\t Room is Vip: " << endl;
			cout << "\t\t 1.Yes" << endl;
			cout << "\t\t 2.NO!  ";
			cin >> option;
			switch (option)
			{
			case 1:
				isVip = true;
				break;
			case 2:
				isVip = false;
				break;
			default:
				cout << "\tWrong Choice, Try Again!." << endl;
			}
		} while (option != 1 && option != 2);
		do
		{
			cout << "\t Room Type: " << endl;
			cout << "\t\t 1.Single Bed. " << endl;
			cout << "\t\t 2.Double Bed.  ";
			cin >> option;
			switch (option)
			{
			case 1:
				roomType = 1;
				break;
			case 2:
				roomType = 2;
				break;
			default:
				cout << "\tWrong Choice, Try Again!." << endl;
			}
		} while (option != 1 && option != 2);
		cout << "\t Daily Rent: ";
		cin >> DailyRent;
		room[numOfRoom].roomStatus = 1;
		numOfRoom++;
		system("cls");
		cout << "\n\tRoom Added Successfully!" << endl;
	}
}
void Room::show(int roomFoundatIndex) {
	cout << "\t----------" << endl;
	if (room[roomFoundatIndex].roomStatus == 0)
		cout << "\tRoom is Reserved " << endl;
	else
		cout << "\tRoom is Available " << endl;

	if (room[roomFoundatIndex].isVip == true)
		cout << "\tRoom is Vip " << endl;
	else
		cout << "\tRoom is normal." << endl;
	if (room[roomFoundatIndex].roomType == 1)
		cout << "\tRoom is Single Bed " << endl;
	else
		cout << "\tRoom is Double Bed" << endl;
	cout << "\tRoom Number= " << room[roomFoundatIndex].RoomNumber << endl;
	cout << "\tDaily Rent= " << room[roomFoundatIndex].DailyRent << " $" << endl;
	cout << "\t----------" << endl;
}
int Room::searchRoom(int rn) {
	int flag = -1;
	for (i = 0; i < numOfRoom; i++)
	{
		if (room[i].RoomNumber == rn)
		{
			flag = i;
		}
	}
	if (flag != -1)
	{
		return flag;
	}
	else
		return -1;
}
void HotelMangment::ManageRoom() {
	do {
		cout << "\n\t 1.Add Rooms" << endl;
		cout << "\t 2.Search Room" << endl;
		cout << "\t 3.Back To Main menu" << endl;
		cout << "\t Enter Option: ";
		cin >> option;

		switch (option)
		{
		case 1:
			
			if (numOfRoom < 10)
			{
				room[numOfRoom].getInfo();
			}
			else
				cout << "\tsorry there is no space for adding new room" << endl;
			break;
		case 2:
			cout << "\tSearch Room" << endl;
			cout << "\t Enter Room Number: ";
			cin >> rn;
			roomFoundatIndex = room->searchRoom(rn);
			if (roomFoundatIndex != -1)
			{
				system("cls");
				cout << "\n\t*****Show Record*****" << endl;
				room->show(roomFoundatIndex);
			}
			else
				cout << "\t Room is not Founded" << endl;
			break;
		case 3:
			 
			break;
		default:
			cout << "\tWrong Choice, Try Again!." << endl;
			break;
		}
	} while (option != 3);
}
void HotelMangment::Booking()
 {
	cout << "\n\t*****Booking*****" << endl;
	cout << "\t Enter Room Number: ";
	cin >> rn;
	roomFoundatIndex = room->searchRoom(rn);
	if (roomFoundatIndex != -1)
	{
		if (room[roomFoundatIndex].roomStatus == 1) {
			cout << "\n\t*****Guest Information*****" << endl;
			cout << "\tRoom is available " << endl;
			room[roomFoundatIndex].getGuestInfo(roomFoundatIndex);
			cout << "\n\tRoom Booked Successfully!" << endl;
			room[roomFoundatIndex].roomStatus = 0;
		}
		else
			cout << "\tRoom is already reserved" << endl;
	}
	else
		cout << "\t Room is not Founded" << endl;
}


void HotelMangment::AvailableRoom() {
	int flag = -1;
	for (i = 0; i < numOfRoom; i++)
	{
		if (room[i].roomStatus == 1)
		{
			room->show(i);
			getch();//it will hold screen for somemoment 
			flag = 0;
		}
	}
	if (flag == -1)
		cout << "\tAll Rooms Are Reserved. ";
}
void HotelMangment::SearchGuest() {
	char nameForSearch[20];//name for searching
	int flag = -1;	
	for (i = 0; i < numOfRoom; i++)
	{
		if (room[i].roomStatus == 0)
			flag = 0;
	}
	if (flag != 0)
		cout << "\tAll rooms are free, there is no Guest." << endl;
	else
	{
		flag = -1; 
		cout << "\t Enter the Name: ";
		cin.ignore(20, '\n');//now get the name and search  
		cin.getline(nameForSearch, 20);
		for (i = 0; i < numOfRoom; i++)
		{
			if (room[i].roomStatus == 0 && strcmp(room[i].Name, nameForSearch) == 0)
			{
				//strcmp fucntion whill check if both name are same or not 
				cout << "\t----------" << endl;
				cout << "\tGust Name: " << room[i].Name << endl;
				cout << "\tRoom Number: " <<
                      room[i].RoomNumber << endl;
				cout << "\t----------" << endl;
				flag = 0;
				getch();
			}
		}
		if (flag != 0)
			cout << "\t Person is not found. " << endl;
	}
}
void HotelMangment::Clearing()
{
	int numberOfDay;
	int billOmount;
	int flag = -1;
	for (i = 0; i < numOfRoom; i++)
	{
		if (room[i].roomStatus == 0)
			flag = 0;
	}
	if (flag != 0)

		cout << "\tAll rooms are free, there is no Guest." << endl;

	else
	{
		cout << "\tEnter Room Number: ";
		cin >> rn;
		roomFoundatIndex = room->searchRoom(rn);//look if the room is exicting
		if (roomFoundatIndex != -1)
		{
			if (room[roomFoundatIndex].roomStatus == 0)// if this room is reserved so do clearing 
			{
				cout << "\tEnter Number of Days: ";
				cin >> numberOfDay;
				billOmount = numberOfDay * room[roomFoundatIndex].DailyRent;
				billOmount = billOmount - room[roomFoundatIndex].AdvancedPayment;
				room->guestShow(roomFoundatIndex);
				cout << "\tTotal Bill= " << billOmount << " $ only. " << endl;
				cout << "\t----------" << endl;

				room[roomFoundatIndex].roomStatus = 1;
				room->removeTheRecord(roomFoundatIndex);
			}
			else
				cout << "\t This Room is free, no Guest is there. " << endl;
		}
		else
			cout << "\t Room is not Founded" << endl;
	}
}
void HotelMangment::GuestSummaryReport() {
	int flag = -1;
	for (i = 0; i < numOfRoom; i++)
	{
		if (room[i].roomStatus == 0)
		{
			room->guestShow(i);
			flag = 0;
		}
	}
	if (flag != 0)
		cout << "\tAll rooms are free, there is no Guest." << endl;
}

int main()
{
	
	do {
		cout << "\n\t*****Hotel Managment Saystem*****" << endl;
		cout << "\t 1.Manage Rooms" << endl;
		cout << "\t 2.Check-In Room(booking)" << endl;
		cout << "\t 3.Available Rooms" << endl;
		cout << "\t 4.Search Guest" << endl;
		cout << "\t 5.Check-Out Room(clearing)" << endl;
		cout << "\t 6.Guest Summary Report" << endl;
		cout << "\t 7.Exit" << endl;
		cout << "\t Enter Option: ";
		cin >> option;
		cout << endl;
	
		switch (option)
		{
		case 1:
			system("cls");
			cout << "\n\t*****Manage Rooms*****" << endl;
			room[numOfRoom].ManageRoom();
			break;
		case 2:
			system("cls");
			cout << "\n\t*****Check-In Room(booking)*****" << endl;
			if (numOfRoom == 0)
				cout << "\tRooms data is not available.\n\tPlease add the rooms first" << endl;
			else
				room->Booking();

			break;
		case 3:
			system("cls");
			cout << "\n\t*****Show All Available Rooms*****" << endl;

			if (numOfRoom == 0)
				cout << "\tRooms data is not available.\n\tPlease add the rooms first" << endl;
			else
				room->AvailableRoom();
			break;
		case 4:
			system("cls");
			cout << "\n\t*****Search Guest*****" << endl;
			if (numOfRoom == 0)
				cout << "\tRooms data is not available.\n\tPlease add the rooms first" << endl;
			else
				room->SearchGuest();
			break;
		case 5:
			system("cls");
			cout << "\n\t*****Check-Out Room(clearing)*****" << endl;
			if (numOfRoom == 0)
				cout << "\tRooms data is not available.\n\tPlease add the rooms first" << endl;
			else
				room->Clearing();
			break;
		case 6:
			system("cls");
			cout << "\n\t*****Guest Summary Report*****" << endl;

			if (numOfRoom == 0)
				cout << "\tRooms data is not available.\n\tPlease add the rooms first" << endl;
			else
				room->GuestSummaryReport();
			break;
		case 7:
			system("cls");
			cout << "\tThank You For using Software." << endl;
			break;
		default:
			system("cls");
			cout << "\tWrong Choice, Try Again!." << endl;
			break;
		}
	} while (option != 7);

	return 0;
}
