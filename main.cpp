#include <iostream>
#include <iomanip>

using namespace std;

class Tips
{
private:
    double taxRate;

public:
    Tips(double rate = .065) // Constructor that accepts a tax rate
    {                        // or uses a default value of 6.5%
        if (rate >= 0)
            taxRate = rate;
        else
            taxRate = .065;
    }
    double computeTip(double, double);
};

double Tips::computeTip(double bill, double rate)
{
    double cost = bill - (bill * taxRate);
    double tip = cost * rate;

    return tip;
}

int main(int argc, char const *argv[])
{

    double bill;
    double tipPercent;
    double taxRate;
    double tipResult;
    char escapeChar;

    Tips tipCal;

    cout << "Please enter local Tax Rate. \n If 0 or less. The rate will be set at 6.5%." << endl;
    cin >> taxRate;
    tipCal = Tips(taxRate / 100);

    cout << "Tax % for this location: "  << taxRate << "." << endl;

    do
    {
        cout << endl;
        cout << "************* Tip Helper ***********" << endl;
        cout << endl;
        cout << "Enter total bill amount: ";
        cin >> bill;
        cout << "Enter desired tip %: ";
        cin >> tipPercent;
        tipPercent /= 100;
        tipResult = tipCal.computeTip(bill, tipPercent);
        cout << "The tip should be $ ";
        cout << setprecision(2) << fixed;
        cout << tipResult << endl;
        cout << "compute another tip (y/n)?";
        cin >> escapeChar;
    } while (escapeChar == 'y' || escapeChar == 'Y');
    return 0;
}
