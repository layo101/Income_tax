//load the declarations of the standard input output library functions
#include <iostream>
#include <iomanip>
using namespace std;

//define the main function
int main()
{
	//This program calculates the annual income tax
	//This program will be used by a group of 10,000 people
	//This program will calculate the total	income tax due based upon the amount of income earned(before any deductions),
	//the number of dependents(children), and the amount of tax already deducted from their income by the employer.
	//AUTHOR: Layomi Dele-Dare
	//DATE COMPLETED: 2014-10-07
	
	//declare constants for the main function
	//initialize constants at time of declaration, their values cannot be changed later
	const int mindependent = 0;
	const int maxdependent = 10;
	const int minincometaxrate = 0;
	const double incometaxrate1 = 0.15;
	const double incometaxrate2 = 0.20;
	const double incometaxrate3 = 0.18;
	const double surtax = 0.035;
	const int mintaxableincome = 0;
	const double taxableincome1 = 12000.00;
	const double taxableincome2 = 20000.00;
	const double taxableincome3 = 50000.00;
	const double taxableincome4 = 100000.00;
	const double maxtaxableincome = 10000000.00;
	const int eligible = 5000; 
	const double randomnumber = 0.0;

	//declare variables for the main function
	//Inititalize variables, values of variables will change during the program execution
	double taxableinco1 = 0.0;
	double taxableinco2 = 0.0;
	double taxableinco3 = 0.0;
	double taxableinco4 = 0.0;
	double taxableinco5 = 0.0;
	double taxableinco6 = 0.0;
	double taxableinco7 = 0.0;
	double totalincome = 0.0;
	int children = 0;
	double taxdeducted = 0.0;
	double taxableincome = 0.0;
	double incometax1 = 0.0;
	double incometax2 = 0.0;
	double incometax3 = 0.0;
	double balance1 = 0.0;
	double balance2 = 0.0;
	double balance3 = 0.0;
	double balance4 = 0.0;
	double refund1 = 0.0;
	double refund2 = 0.0;
	double refund3 = 0.0;
	double refund4 = 0.0;


	//request and collect inputs
	cout << "Please enter your total income before any deductions for income tax ";
	cin >> totalincome;
	if (totalincome < mintaxableincome)
	{
		cout << "Error entering income, your income cannot be < " << mintaxableincome << endl;
		return 1;
	}
	cout << "Please enter the number of children you support ";
	cin >> children;
	if (children < mindependent)
	{
		cout << "You cannot have a negative number of dependents" << endl;
		return 2;
	}

	cout << "Please enter the amount of income tax your employer already deducted ";
	cin >> taxdeducted; 
	if (taxdeducted < minincometaxrate)
	{
		cout << "You cannot prepay negative amounts of tax" << endl;
		return 3; 
	}
	else if (taxdeducted > totalincome)
	{
		cout << "You cannot prepay more in tax than you receive in income" << endl; 
		return 4;
	}

	if (totalincome > maxtaxableincome)
	{
		cout << "Your income is too high to use this method of tax calculation" << endl;
		return 5;
	}

	//Equations required to calculate taxable income, income tax, surtax, balance and refund
	if (children < maxdependent)
	{
		taxableincome = totalincome - (children * eligible);
	}
	else if (children > maxdependent)
	{
		taxableincome = totalincome - (maxdependent * eligible);
	}

	taxableinco1 = incometaxrate1 * taxableincome;
	taxableinco2 = incometaxrate1 * taxableincome2;
	taxableinco3 = incometaxrate3 * taxableincome2;
	taxableinco4 = incometaxrate2 * (taxableincome - taxableincome2);
	taxableinco5 = incometaxrate3 * (taxableincome3 - taxableincome2);
	taxableinco6 = incometaxrate3 * (taxableincome - taxableincome3);
	taxableinco7 = surtax * (taxableincome - taxableincome4);
	incometax1 = taxableinco2 + taxableinco4;
	incometax2 = taxableinco3 + taxableinco5 + taxableinco6;
	incometax3 = taxableinco3 + taxableinco5 + taxableinco6 + taxableinco7;
	balance1 = taxableinco1 - taxdeducted;
	balance2 = incometax1 - taxdeducted;
	balance3 = incometax2 - taxdeducted;
	balance4 = incometax3 - taxdeducted;
	refund1 = taxdeducted - taxableinco1;
	refund2 = taxdeducted - incometax1; 
	refund3 = taxdeducted - incometax2; 
	refund4 = taxdeducted - incometax3;

	
	cout << endl << endl;
	

	cout.setf(ios::fixed);
	cout.setf(ios::showpoint);
	cout.precision(2);

	// Inform the user of the inputs and the results

	cout << setw(45) << fixed << left << "Amount of income:" << "$" << setw(15) << fixed << right << totalincome << endl;
	if (children < maxdependent)
	{
		cout << setw(60) << fixed << left << "Number of qualifying dependents:" << children << endl;
	}
	else if (children >= maxdependent)
	{
		cout << setw(59) << fixed << left << "Number of qualifying dependents:" << maxdependent << endl;
	}
	cout << setw(45) << fixed << left << "Taxable income:" << "$" << setw(15) << fixed << right << taxableincome << endl;
	cout << setw(45) << fixed << left << "Amount of income tax deducted:" << "$" << setw(15) << fixed << right << taxdeducted << endl;
	cout << endl << endl;


	if (taxableincome < taxableincome1)
	{
		cout << "You do not owe any income tax" << endl;
		cout << setw(45) << fixed << left << "You will receive a refund of" << "$" << setw(15) << fixed << right << taxdeducted << endl; 
	}
	else if  (taxableincome1 <= taxableincome && taxableincome <= taxableincome2)
	{
		cout << setw(45) << fixed << left << "Tax on first $20,000 of taxable income " << "$" << setw(15) << fixed << right << taxableinco1 << endl;
		cout << setw(45) << fixed << left << "Tax on next $30,000 of taxable income " << "$" << setw(15) << fixed << right << randomnumber << endl; 
		cout << setw(45) << fixed << left << "Tax on remaining taxable income " << "$" << setw(15) << fixed << right << randomnumber << endl;
		cout << setw(45) << fixed << left << "Income Tax surtax " << "$" << setw(15) << fixed << right << randomnumber << endl;

		if (taxableinco1 >= taxdeducted)
		{
			cout << setw(45) << fixed << left << "You must pay a balance of " << "$" << setw(15) << fixed << right << balance1 << endl;
			cout << setw(45) << fixed << left << "You will receive a refund of " << "$" << setw(15) << fixed << right << randomnumber << endl; 
		}
		else if (taxableinco1 < taxdeducted)
		{
			cout << setw(45) << fixed << left << "You must pay a balance of " << "$" << setw(15) << fixed << right << randomnumber << endl;
			cout << setw(45) << fixed << left << "You will receive a refund of " << "$" << setw(15) << fixed << right << refund1 << endl;
		}
	}
	else if (taxableincome2 < taxableincome && taxableincome <= taxableincome3)
	{
		cout << setw(45) << fixed << left << "Tax on first $20,000 of taxable income " << "$" << setw(15) << fixed << right << taxableinco2 << endl;
		cout << setw(45) << fixed << left << "Tax on next $30,000 of taxable income " << "$" << setw(15) << fixed << right << taxableinco4 << endl;
		cout << setw(45) << fixed << left << "Tax on remaining taxable income " << "$" << setw(15) << fixed << right << randomnumber << endl;
		cout << setw(45) << fixed << left << "Income Tax surtax " << "$" << setw(15) << fixed << right << randomnumber << endl;
		
		if (incometax1 >= taxdeducted)
		{
			cout << setw(45) << fixed << left << "You must pay a balance of " << "$" << setw(15) << fixed << right << balance2 << endl;
			cout << setw(45) << fixed << left << "You will receive a refund of " << "$" << setw(15) << fixed << right << randomnumber << endl;
		}
		else if (incometax1 < taxdeducted)
		{
			cout << setw(45) << fixed << left << "You must pay a balance of " << "$" << setw(15) << fixed << right << randomnumber << endl;
			cout << setw(45) << fixed << left << "You will receive a refund of " << "$" << setw(15) << fixed << right << refund2 << endl;
		}
	
	}
	else if (taxableincome3 < taxableincome && taxableincome <= taxableincome4)
	{
		cout << setw(45) << fixed << left << "Tax on first $20,000 of taxable income " << "$" << setw(15) << fixed << right << taxableinco3 << endl;
		cout << setw(45) << fixed << left << "Tax on next $30,000 of taxable income " << "$" << setw(15) << fixed << right << taxableinco5 << endl;
		cout << setw(45) << fixed << left << "Tax on remaining taxable income " << "$" << setw(15) << fixed << right << taxableinco6 << endl;
		cout << setw(45) << fixed << left << "Income Tax surtax " << "$" << setw(15) << fixed << right << randomnumber << endl;

		if (incometax2 >= taxdeducted)
		{
			cout << setw(45) << fixed << left << "You must pay a balance of " << "$" << setw(15) << fixed << right << balance3 << endl;
			cout << setw(45) << fixed << left << "You will receive a refund of " << "$" << setw(15) << fixed << right << randomnumber << endl;
		}
		else if (incometax2 < taxdeducted)
		{
			cout << setw(45) << fixed << left << "You must pay a balance of " << "$" << setw(15) << fixed << right << randomnumber << endl;
			cout << setw(45) << fixed << left << "You will receive a refund of " << "$" << setw(15) << fixed << right << refund3 << endl;
		}

	}
	else if (taxableincome4 < taxableincome && taxableincome <= maxtaxableincome)
	{
		cout << setw(45) << fixed << left << "Tax on first $20,000 of taxable income " << "$" << setw(15) << fixed << right << taxableinco3 << endl;
		cout << setw(45) << fixed << left << "Tax on next $30,000 of taxable income " << "$" << setw(15) << fixed << right << taxableinco5 << endl;
		cout << setw(45) << fixed << left << "Tax on remaining taxable income " << "$" << setw(15) << fixed << right << taxableinco6 << endl;
		cout << setw(45) << fixed << left << "Income Tax surtax " << "$" << setw(15) << fixed << right << taxableinco7 << endl;

		if (incometax3 >= taxdeducted)
		{
			cout << setw(45) << fixed << left << "You must pay a balance of " << "$" << setw(15) << fixed << right << balance4 << endl;
			cout << setw(45) << fixed << left << "You will receive a refund of " << "$" << setw(15) << fixed << right << randomnumber << endl;
		}
		else if (incometax3 < taxdeducted)
		{
			cout << setw(45) << fixed << left << "You must pay a balance of " << "$" << setw(15) << fixed << right << randomnumber << endl;
			cout << setw(45) << fixed << left << "You will receive a refund of " << "$" << setw(15) << fixed << right << refund4 << endl;
		}

	}
	return 0; 
}