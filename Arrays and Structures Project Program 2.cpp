#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>

using namespace std;

const int MaxRows = 10;
const int Columns = 7;
const string FileName = "Runner Data.txt";

struct RunnerRecords
{
	string RunnerNames;
	double RunnerData[MaxRows];
	double Total, Averages;
};

// Reads the names of runners from the file.
// Pre-Condition: Finds existing file and reads and stores names of runners.
// Post-Condition: Holds the names for the next function to use.
int RunnerArray(RunnerRecords Runners[], int MaxRows);

// Calculates the total and average miles for each runner.
// Pre-Condition: Receives the raw miles for each runner and number of runners.
// Post-Condition: Total and average miles is calculated for each runner and put at the end of the row for that runner.
void RunnersAveragesandTotal(RunnerRecords Runners[], int NumberofRows);

// Outputs on the screen the Names, Miles, Total Miles, and Average Miles for each runner.
// Pre-Condition: Checks for Averages and Totals for runners from a previous function.
// Post-Condition: Outputs the data on each runner on screen with proper formatting and labels.
void LabelsandOutput(RunnerRecords Runners[], int NumberofRecords);

int main()
{
	RunnerRecords Runners[MaxRows];
	int NumberofRecords;
	NumberofRecords = RunnerArray(Runners, MaxRows);
	RunnersAveragesandTotal(Runners, NumberofRecords);
	LabelsandOutput(Runners, NumberofRecords);

	return 0;
}

int RunnerArray(RunnerRecords Runners[], int MaxRows)
{
	ifstream myiFile;
	int Rows = 0;

	myiFile.open(FileName);

	if (!myiFile.is_open())
	{
		cout << "Could not open file.\n";

		return -1;
	}

	myiFile >> Runners[Rows].RunnerNames;
	while (!myiFile.eof() && !(Rows >= MaxRows))
	{
		for (int i = 0; i < Columns; i++)
		{
			myiFile >> Runners[Rows].RunnerData[i];
		}
		Rows++;
		myiFile >> Runners[Rows].RunnerNames;
	}
	myiFile.close();

	return Rows;
}

void RunnersAveragesandTotal(RunnerRecords Runners[], int NumberofRows)
{
	double Sum = 0;
	for (int i = 0; i < NumberofRows; i++)
	{
		Sum = 0;
		for (int j = 0; j < Columns; j++)
		{
			Sum = Sum + Runners[i].RunnerData[j];
		}
		Runners[i].Total = Sum;
		Runners[i].Averages = Sum / Columns;
	}
}

void LabelsandOutput(RunnerRecords Runners[], int NumberofRecords)
{
	cout << fixed << setprecision(2);
	cout << "Runner  Sunday  Monday Tuesday Wednesday Thursday Friday Saturday Total  Average" << endl;
	for (int i = 0; i < NumberofRecords; i++)
	{
		cout << left << setw(10) << Runners[i].RunnerNames;
		for (int j = 0; j < Columns; j++)
		{
			cout << left << setw(8.5) << Runners[i].RunnerData[j];
		}
		cout << left << setw(8.5) << Runners[i].Total << left << setw(7) << Runners[i].Averages << endl;
	}
}
