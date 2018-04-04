#include <iostream.h>
#include <fstream.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<conio.h>

class DateTime
	{
		long date, time;
		public:
			DateTime(long date, long time)
			{
				this->date = date;
				this->time = time;
			}
			DateTime()
			{

			}
			long getDate(){
				return this->date;
			}
			long getTime(){
				return this->time;
			}
	};
class Employee
    {
		int id;
		char name[50];
		int listMeetings[50];
		int meetingCount;

		public:
		Employee()
		{

		}
		Employee(int id, char *name)
		{
			this->id = id;
			strcpy(this->name, name);
			meetingCount = 0;
		}
		void setName(char *name)
		{
			strcpy(this->name, name);
		}
		char* getName()
		{
			return name;
		}
		int addMeeting(int meetingId)
		{
			if(meetingCount>=50)
				return 0;
			listMeetings[meetingCount] = meetingId;
			meetingCount++;
			return 1;
		}
		int deleteMeeting(int meetingId)
		{
			if(meetingCount == 0)
				return 0;
			int index = -1;
			int i;

			for(i = 0;i<meetingCount;i++)
			{
				if(listMeetings[i] == meetingId)
					index = i;
			}
			if(index == -1)
				return 0;
			for(i = index;i<meetingCount;i++)
				listMeetings[i] = listMeetings[i+1];
			meetingCount--;
			return 1;
		}
		int getId()
		{
			return this->id;
		}
    };

class EmployeeMgr{
	Employee listEmployees[50];
	int employeeCount;
	int totalEmployee;
	public:
	EmployeeMgr()
	{
		employeeCount = 0;
		totalEmployee = 1;
	}

	int addEmployee(char *name)
	{
		if(employeeCount == 50)
			return 0;
		for(int i = 0;i<employeeCount;i++)
			if(strcmp(listEmployees[i].getName(), name) == 0)
				return 0;
		Employee employee(totalEmployee, name);
		listEmployees[employeeCount] = employee;
		employeeCount++;
		totalEmployee++;
		return 1;
	}
	int deleteEmployee(char *name)
	{
		if(name == NULL)
			return 0;
		int index = -1;
		int i;
		for(i = 0;i<employeeCount;i++)
			if(strcmp(listEmployees[i].getName(), name) == 0)
				index = i;
		if(index == -1)
			return 0;
		for(i = index;i<employeeCount;i++)
			listEmployees[i] = listEmployees[i+1];
		employeeCount--;
		return 1;
	}
	int modifyEmployee(char *oldName, char *newName)
	{
		if(oldName == NULL || newName == NULL)
			return 0;
		int index = -1;
		for(int i = 0;i<employeeCount;i++)
			if(strcmp(listEmployees[i].getName(), oldName) == 0)
				index = i;
		if(index == -1)
			return 0;
		listEmployees[index].setName(newName);
		return 1;
	}
	int checkExists(char *name)
	{
		if(name == NULL)
			return 0;
		for(int i = 0;i<employeeCount;i++)
			if(strcmp(listEmployees[i].getName(), name) == 0)
				return 1;
		return 0;
	}

	int getEmployeeId(char *name)
	{
		if(checkExists(name) == 0)
			return -1;
		for(int i = 0;i<employeeCount;i++)
			if(strcmp(listEmployees[i].getName(), name) == 0)
				return listEmployees[i].getId();
	}

	char* getEmployeeName(int id)
	{
		for(int i = 0;i<employeeCount;i++)
			if(listEmployees[i].getId() == id)
				return listEmployees[i].getName();
		return NULL;
	}
	int removeMeetingFromEmployees(int meetingId)
	{
		int count = 0;
		for(int i = 0;i<employeeCount;i++)
		{
			if(listEmployees[i].deleteMeeting(meetingId))
				count++;
		}
		return count;
	}
	void display()
	{
		cout<<endl<<"Displaying the list of Employees: \n";
		for(int i = 0;i<employeeCount;i++)
		{
			cout<<listEmployees[i].getId()<<".\t"<<listEmployees[i].getName()<<"\n";
		}
	}
}employeeMgr;

class Meeting{
	int meetingId;
	DateTime datetime;
	int listEmployees[50];
	int employeeCount;
	char venue[50];
	public:

	Meeting(int meetingId, DateTime datetime, char *venue)
	{
		employeeCount = 0;
		this->meetingId = meetingId;
		this->datetime = datetime;
		strcpy(this->venue,venue);
	}
	Meeting(){
		employeeCount = 0;
	}
	int getMeetingId()
	{
		return this->meetingId;
	}

	DateTime getDatetime()
	{
		return this->datetime;
	}

	char* getVenue()
	{
		return this->venue;
	}

	int updateVenue(char *newVenue)
	{
		if(newVenue == NULL)
			return 0;
		strcpy(this->venue,newVenue);
		return 1;
	}

	int updateDatetime(DateTime datetime)
	{
		this->datetime = datetime;
		return 1;
	}

	int addEmployee(char *name)
	{
		if(name == NULL)
			return 0;
		int employeeId = employeeMgr.getEmployeeId(name);
		if(employeeId == -1)
			return 0;
		listEmployees[employeeCount] = employeeId;
		employeeCount++;
		return 1;
	}

	int removeEmployee(char *name)
	{
		if(name == NULL)
			return 0;
		int employeeId = employeeMgr.getEmployeeId(name);
		if(employeeId == -1)
			return 0;

		int index = -1;
		int i;
		for(i = 0;i<employeeCount;i++)
			if(listEmployees[i] == employeeId)
				index = i;
		if(index == -1)
			return 0;

		for(i = index;i<employeeCount;i++)
			listEmployees[i] = listEmployees[i+1];
		employeeCount--;
		return 1;
	}
	int getEmployeeCount()
	{
		return this->employeeCount;
	}
	int* getListEmployees()
	{
		return this->listEmployees;
	}

};

class MeetingMgr{
	Meeting listMeetings[50];
	int meetingCount;
	int totalMeeting;
	public:
	MeetingMgr(){
		meetingCount = 0;
		totalMeeting = 1;
	}

	int addMeeting(DateTime datetime, char *venue)
	{
		if(meetingCount >=50)
			return 0;
		if(venue == NULL)
			return 0;
		Meeting meeting(totalMeeting, datetime, venue);
		listMeetings[meetingCount] = meeting;
		meetingCount++;
		totalMeeting++;
		return 1;
	}

	int updateMeeting(int meetingId, DateTime datetime, char *venue)
	{
		int index = -1;
		for(int i = 0;i<meetingCount;i++)
			if(listMeetings[i].getMeetingId() == meetingId)
			{
				listMeetings[i].updateDatetime(datetime);
				listMeetings[i].updateVenue(venue);
				index = -1;
			}
		if(index == -1)
			return 0;
		return 1;
	}
	int deleteMeeting(int meetingId)
	{
		int index = -1;
		int i;
		for(i = 0;i<meetingCount;i++)
			if(listMeetings[i].getMeetingId() == meetingId)
				index = i;
		if(index == -1)
			return 0;
		for(i = index;i<meetingCount;i++)
			listMeetings[i] = listMeetings[i+1];
		meetingCount--;
		return 1;
	}

	int addEmployeeToMeeting(int meetingId, char *name)
	{
		if(name == NULL)
			return 0;
		int index = -1;
		for(int i = 0;i<meetingCount;i++)
			if(listMeetings[i].getMeetingId() == meetingId)
				index = i;
		if(index == -1)
			return 0;
		listMeetings[index].addEmployee(name);
		return 1;
	}

	int removeEmployeeFromMeeting(int meetingId, char *name)
	{
		if(name == NULL)
			return 0;
		int index = -1;
		for(int i = 0;i<meetingCount;i++)
			if(listMeetings[i].getMeetingId() == meetingId)
				index = i;
		if(index == -1)
			return 0;
		listMeetings[index].removeEmployee(name);
		return 1;
	}

	int removeEmployeeFromAllMeetings(char *name)
	{
		int count = 0;
		if(name == NULL)
			return -1;
		for(int i = 0;i<meetingCount;i++)
		{
			if(removeEmployeeFromMeeting(listMeetings[i].getMeetingId(), name))
				count++;
		}
		return count;
	}
	void display()
	{
		cout<<endl<<"List of meetings in the organization("<<meetingCount<<"): \n";
		for(int i = 0;i<meetingCount;i++)
		{

			cout<<"\nMeeting ID: "<<listMeetings[i].getMeetingId()<<"\n";
			cout<<"DateTime: "<< listMeetings[i].getDatetime().getDate() << " "<< listMeetings[i].getDatetime().getTime()<<"\n";
			cout<<"Venue: "<<listMeetings[i].getVenue()<<"\n";
			cout<<"\n List of Participants: "<<endl;

			int *listParticipants = listMeetings[i].getListEmployees();
			int numParticipants = listMeetings[i].getEmployeeCount();

			for(int j = 0;j<numParticipants;j++)
			{
				cout<<listParticipants[j]<<"\t"<<employeeMgr.getEmployeeName(listParticipants[j])<<"\n";
			}
			cout<<"\n";
		}
	}
	int getTotalCount()
	{
		return this->totalMeeting;
	}
};

int main()
{
	MeetingMgr meetings;

	cout << "\t\tMeeting Management System" << endl << endl;
	char rep,opt;
	cout<< "Load data from Meetings.dat & Employee.dat? (y/n): ";
	cin>>opt;
	if(opt == 'y'||opt == 'Y')
	{
		ifstream readStream("Meetings.dat", ios::in|ios::binary);
		if(readStream)
		{
		readStream.read((char *)&meetings, sizeof(MeetingMgr));
		readStream.close();
		}
		else
			cout<<"\nMeetings.dat does not exist......";
		
		readStream.open("Employee.dat", ios::in|ios::binary);
		if(readStream)
		{
		readStream.read((char *)&employeeMgr, sizeof(EmployeeMgr));
		readStream.close();
		}
		else
			cout<<"\nEmployee.dat does not exist......";
	}
	do{
		cout<<"Employees or Meetings\n";
		cout<<"Enter your choice: ";
		int choice;
		cin>>choice;
		switch(choice)
		{
			case 1:
			{
				int subChoice;
				cout<<"1.Add \n2.Delete \n3.Update \n4.Display\n";
				cout<<"Enter your employee option: ";
				cin>>subChoice;
				switch(subChoice)
				{
					case 1:
					{
						cout<<"Enter the name of the employee: ";
						char name[50];
						cin>>name;
						employeeMgr.addEmployee(name);
					}break;

					case 2:
					{
						cout<<"Enter the name of the employee: ";
						char name[50];
						cin>>name;
						meetings.removeEmployeeFromAllMeetings(name);
						employeeMgr.deleteEmployee(name);
					}break;
					case 3:
					{
						char oldName[50], newName[50];
						cout<<"Enter the current name of the employee: ";
						cin>>oldName;
						cout<<"Enter the new name of the employee: ";
						cin>>newName;
					}break;
					case 4:
					{
						employeeMgr.display();
					}
					default:
					cout<<"Please enter a valid choice\n";
				}
			}break;
			case 2:
			{
				int subChoice;
				cout<<"1.Add \n2.Delete \n3.Update \n4.Display\n";
				cout<<"Enter your Meeting option: ";
				cin>>subChoice;
				switch(subChoice)
				{
					case 1:
					{
						long date, time;
						int numParticipants;
						char venue[50];
						cout<<"Enter the date (ddmmyyyy): ";
						cin>>date;
						cout<<"Enter the time 24 hr(hh:mm): ";
						cin>>time;
						cout<<"Enter the venue: ";
						cin>>venue;
						cout<<"Enter the number of participants to be added: ";
						cin>>numParticipants;
						int meetingID = meetings.getTotalCount();
						DateTime datetime(date,time);
						meetings.addMeeting(datetime,venue);
						for(int i = 0;i<numParticipants;i++)
						{
							char name[50];
							cout<<"Enter the name of participant "<<i+1<<": ";
							cin>>name;
							meetings.addEmployeeToMeeting(meetingID,name);
						}
					}break;
					case 2:
					{
						int meetingID;
						cout<<"Enter the meeting ID: ";
						cin>>meetingID;
						if(meetings.deleteMeeting(meetingID))
						{
							cout<<"Meeting successfully deleted\n";
							employeeMgr.removeMeetingFromEmployees(meetingID);
						}
						else
							cout<<"Unable to delete such a meeting\n";
					}break;
					case 3:
					{
						int meetingID;
						int date, time;
						cout<<"Enter the meeting ID: ";
						cin>>meetingID;
						char venue[50];
						cout<<"Enter the date (ddmmyyyy): ";
						cin>>date;
						cout<<"Enter the time 24 hr(hh:mm): ";
						cin>>time;
						cout<<"Enter the venue: ";
						cin>>venue;

					}break;
					case 4:
					{
						meetings.display();
					}break;
					default:
					cout<<"Please Enter a valid choice\n";
				}
			}break;
			default:
			cout<<"Invalid Option\n";
		}
		cout<<"Do you want to continue: ";
		cin>>rep;
	}while (rep == 'y'||rep == 'Y');

	ofstream writeStream("Meetings.dat", ios::out|ios::binary);
	writeStream.write((char *)&meetings, sizeof(MeetingMgr));
	writeStream.close();
	
	writeStream.open("Employee.dat", ios::out|ios::binary);
	writeStream.write((char *)&employeeMgr, sizeof(EmployeeMgr));
	writeStream.close();

	return 0;
}
