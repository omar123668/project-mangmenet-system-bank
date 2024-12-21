#pragma once
#include<iostream>
#include"clsDate.h"
#include<queue>
#include<stack>
using namespace std;
class clsQueueLine
{
private:
	short _TotalTicket = 0;
	short _AverageServeTime = 0;
	string _Prefix = "";

	class clsTicket
	{
	private:
		short _Number = 0;
		string _Prefix = "";
		string _TicketTime = "";
		short _WaitingClients = 0;
		short _ExpectedServeTime = 0;
	public:
		clsTicket(string _Prefix, short Number, short WaitingClients, short _AverageServeTime)
		{
			_Number = Number;
			this->_Prefix = _Prefix;
			_TicketTime = clsDate::GetSystemDateTimeString();
			_WaitingClients = WaitingClients;
			this->_ExpectedServeTime = _AverageServeTime;
		}
		short WaitingClients()
		{
			return _WaitingClients;
		}
		string Prefix()
		{
			return _Prefix;
		}
		string FullNumber()
		{
			return Prefix() + to_string(_Number);
		}
		string TickeTime()
		{
			return _TicketTime;
		}
		short ExpectedServeTime()
		{
		   return _ExpectedServeTime * _WaitingClients;
		}

		void Print()
		{
			cout << endl << endl;
			cout << setw(32) << "" << "______________________________\n\n";
			cout << setw(42) << "" << FullNumber() << endl;
			cout << setw(32) << "" << "wating Clients = " << _WaitingClients << endl;
			cout << setw(32) << "" <<"Serve Time In\n";
			cout << setw(32) << "" << ExpectedServeTime() << " Minutes.\n";
		    cout << setw(32) << "" <<"______________________________\n";
		}
    };
public:
	queue<clsTicket>QueueLine;

	clsQueueLine(string Prefix, int _AverageServeTime)
	{
		_Prefix = Prefix;
		_TotalTicket = 0;
		this->_AverageServeTime = _AverageServeTime;
	}

	void IssueTicket()
	{
		_TotalTicket++;
		clsTicket Ticket(_Prefix,_TotalTicket,WaitingClients(),_AverageServeTime);
		QueueLine.push(Ticket);
	}
	short WaitingClients()
	{
		return QueueLine.size();
	}
	string WhoisNext()
	{
		
			if (QueueLine.empty())
			{
				return "No Client Left.";
			}
			else

			return QueueLine.front().FullNumber();

	}

	void PrintInfo()
	{
		cout << "\n\n";
		cout << setw(30) << "" << "______________________________\n\n";
		cout << setw(39)  << "" << "Queue Info\n";
		cout << setw(30) << "" << "______________________________\n\n";

		cout << setw(32) << "" << "Prefix = " << _Prefix << endl;
	    cout << setw(32) << "" << "Total   Tickets          = " << _TotalTicket << endl;
        cout << setw(32) << "" << "Served  Clients          = " << ServedClients() << endl;
		cout << setw(32) << "" << "Waiting Clients          = " << WaitingClients()<< endl;
		cout << setw(32) << "" << "The Client i Will Serve is = " << WhoisNext() << endl;

		cout << setw(30) << "" << "______________________________\n\n";
	}
	void PrintTicketsLineRTL()
	{
		if (QueueLine.empty())
			cout << "\n\n\t\tTicket: No Ticket.";
		else
			cout << "\n\t\tTicket: ";

		queue<clsTicket>TempQueueLine = QueueLine;

		while (!TempQueueLine.empty())
		{
			cout <<TempQueueLine.front().FullNumber() << " <-- ";
			TempQueueLine.pop();
		}
		cout << "\n";
	}
	void PrintTicketsLineLTR()
	{
		if (QueueLine.empty())
			cout << "\n\t\tTicket: No Ticket.";
		else
			cout << "\n\t\tTicket: ";

		queue<clsTicket>TempQueueLine = QueueLine;
		stack < clsTicket >TempStackLine;

		while (!TempQueueLine.empty())
		{
			TempStackLine.push(TempQueueLine.front());
			TempQueueLine.pop();
		}
		while (!TempStackLine.empty())
		{
			cout << TempStackLine.top().FullNumber() << " --> ";
			TempStackLine.pop();
		}

	}
	short ServedClients()
	{
		return _TotalTicket - QueueLine.size();
	}
	void PrintAllTickets()
	{
		cout << endl << endl;
		cout << setw(40) << "" <<"-- - Tickets-- - ";

		queue<clsTicket>TempQueueLine = QueueLine;
		while(!TempQueueLine.empty())
		{
			TempQueueLine.front().Print();
			TempQueueLine.pop();
		}

	}
	bool ServeNextClient()
	{
		if (QueueLine.empty())
			return false;

		else
			QueueLine.pop();
		return true;
	}

};

