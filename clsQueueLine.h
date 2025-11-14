#pragma once
#include <iostream>
#include <string>
#include <iomanip>
#include <queue>
#include <stack>
#include "E:\Programming_Path\Course#10\OOP_Notes\OOP_Notes\clsDate.h"
using namespace std;

// Issue and Serve Tickets:
// - handle queue's Ticket
// - handle Line's Info Process

class clsQueueLine
{
private:
	// global members of each new Line
	string _Name;
	string _Prefix;
	int _TotalTickets = 0;
	short _AverageServeTime = 0;

	class clsTicket
	{
	private:
		string _Prefix;
		int _Order = 0;
		string _TicketTime;
		short _ExpectedServeTime = 0;
		int _WaitingClients = 0;
		short _AverageServeTime = 0;

	public:
		clsTicket(string Prefix, int Order, int WaitingClients, short AverageServeTime)
		{
			_Prefix = Prefix;
			_Order = Order + 1;
			_TicketTime = clsDate::GetSystemDateTimeString();
			_WaitingClients = WaitingClients;
			_AverageServeTime = AverageServeTime;
		}

		string getPrefix()
		{
			return _Prefix;
		}

		int getOrder()
		{
			return _Order;
		}

		string TicketID()
		{
			return _Prefix + to_string(_Order);
		}

		string TicketTime()
		{
			return clsDate::GetSystemDateTimeString();
		}

		short getExpectedServeTime()
		{
			return _AverageServeTime * _WaitingClients; // depends on how many clients before this client
		}

		void PrintTicketInfo()
		{
			cout << setw(12) << "" << "----------------------" << endl;
			cout << setw(12) << "" << "\t   " << TicketID() << endl << endl;
			cout << setw(12) << "" << TicketTime() << endl;
			cout << setw(12) << "" << "Waiting Clients: " << _WaitingClients << endl;
			cout << setw(12) << "" << "Serve time in" << endl;
			cout << setw(12) << "" << getExpectedServeTime() << " Minutes." << endl;
			cout << setw(12) << "" << "----------------------" << endl << endl;
		}
	};

	queue <clsTicket> _QueueLine;

public:
	clsQueueLine(string LineName, string LinePrefix, short LineAverageServeTime)
	{
		_Name = LineName;
		_Prefix = LinePrefix;
		_AverageServeTime = LineAverageServeTime;
	}

	int WaitingClients()
	{
		return _QueueLine.size();

	}

	string WhoIsNext()
	{
		if (_QueueLine.empty())
			return "\nNo Clients Left.\n";
		else
			return _QueueLine.front().TicketID();
	}

	short ServedClients()
	{
		return _TotalTickets - WaitingClients();
	}

	void IssueTicket()
	{
		_QueueLine.push(clsTicket(_Prefix, _TotalTickets, WaitingClients(), _AverageServeTime));
		_TotalTickets++;
	}

	bool ServeNextClient()
	{
		if (_QueueLine.empty())
			return false;

		_QueueLine.pop();
		return true;
	}

	void PrintTicketsLineLTR()
	{
		if (_QueueLine.empty())
			cout << "\n\t\tNo Tickets.\n";
		else
			cout << "\n\t\tTickets:\n";

		// Copy queue in order not to lose the original
		queue <clsTicket> TempQueueLine = _QueueLine;
		while (!TempQueueLine.empty())
		{
			if (TempQueueLine.size() != 1)
				cout << TempQueueLine.front().TicketID() << "  ->  ";
			else
				cout << TempQueueLine.front().TicketID();
			TempQueueLine.pop();
		}
	}

	void PrintTicketsLineRTL()
	{
		if (_QueueLine.empty())
			cout << "\n\t\tNo Tickets.\n";
		else
			cout << "\n\t\tTickets:\n";

		queue <clsTicket> TempQueueLine = _QueueLine;
		stack <clsTicket> TempStackLine;

		// Copy queue in order to stack for reverse printing
		while (!TempQueueLine.empty())
		{
			TempStackLine.push(TempQueueLine.front());
			TempQueueLine.pop();
		}

		while (!TempStackLine.empty())
		{
			if (TempStackLine.size() != 1)
				cout << TempStackLine.top().TicketID() << "  <-  ";
			else
				cout << TempStackLine.top().TicketID();
			TempStackLine.pop();
		}
	}

	void PrintAllTickets()
	{
		if (_QueueLine.empty())
			cout << "\n\n\t\t\t No Tickets in the System\n";
		else
			cout << "\n\n\t\t\t ---Tickets---\n";

		queue <clsTicket> TempQueueLine = _QueueLine;
		while (!TempQueueLine.empty())
		{
			TempQueueLine.front().PrintTicketInfo();
			TempQueueLine.pop();
		}
	}

	void PrintInfo()
	{
		cout << "\n\t\t\t  ________________________________";
		cout << "\n\t\t\t |                                |";
		cout << "\n\t\t\t |  " << left << setw(18) << (_Name + " Line Info") << "         |";
		cout << "\n\t\t\t |________________________________|";
		cout << "\n\t\t\t | Prefix         : " << left << setw(12) << _Prefix << "  |";
		cout << "\n\t\t\t | Total Tickets  : " << left << setw(12) << _TotalTickets << "  |";
		cout << "\n\t\t\t | Served Clients : " << left << setw(12) << ServedClients() << "  |";
		cout << "\n\t\t\t | Waiting Clients: " << left << setw(12) << WaitingClients() << "  |";
		cout << "\n\t\t\t | Avg Serve Time : " << left << setw(12) << _AverageServeTime << "  |";
		cout << "\n\t\t\t |________________________________|\n";
	}
};