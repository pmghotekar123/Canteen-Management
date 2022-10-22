#include <bits/stdc++.h>
using namespace std;

class User_Info
{
public:
    string name;
    long long int mobile;
    void Information()
    {
        cout << "Enter your Name : ";
        cin >> name;
        cout << "Enter your Mobile number : ";
        cin >> mobile;
    }
    void display()
    {
        cout << "Your Entered Name and Mobile number is : " << name << " and " << mobile << endl;
    }
};

class Shop : public User_Info
{
public:
    int product_code;
    float set_price[5] = {20, 40, 12, 30, 25}, total_bill = 0, amount[5] = {0}, product_quantity[5] = {0};
    string shop_items[5] = {"Samosa", "Dosa", "Bread Pakoda", "Noodles", "Kachori"};
    void showitem()
    {

        cout << "---------------------------------------------------------------\n";
        for (int i = 0; i < 5; i++)
        {
            cout << i + 1 << ". " << shop_items[i] << " | ";
        }
        cout << "\nEnter number infront of the item to add" << endl;
        cout << "Press 0 to exit and Print Bill" << endl;
    }
    void user_items()
    {
        do
        {
            showitem();
            float temp_price, temp_quantity;
            cin >> product_code;
            if ((product_code == 1) || (product_code == 4))
            {
                cout << "Enter the Quantity of " << shop_items[product_code - 1] << " you want : ";
                cin >> temp_quantity;
                temp_price = temp_quantity * set_price[product_code - 1] * 1.0;
                cout << "Do you want to add " << temp_quantity << " items of " << shop_items[product_code - 1] << " at the rate of " << set_price[product_code - 1] << " per item" << endl;
                cout << "Press 1 to add  |  Press 0 Cancel : ";
                int x;
                cin >> x;
                if (x == 1)
                {
                    total_bill = total_bill + temp_price;
                    amount[product_code - 1] = amount[product_code - 1] + temp_price;
                    product_quantity[product_code - 1] = product_quantity[product_code - 1] + temp_quantity;
                }
            }

            else if (product_code == 0)
            {
            }
            else
            {
                cout << "Invalid Input\n";
            }
        } while (product_code);
        cout << endl;
    }
};

class Bill : public Shop
{
public:
    void print_bill()
    {
        int j = 1;
        int i = 1;
        cout << "\n==========================================================================================\n";
        cout << "                           -----   Raisoni Canteen   -----                             \n";
        cout << "==========================================================================================\n";
        cout << "------------------------------------------------------------------------------------------\n";
        cout << "      Name and Mobile Number : " << name << "  |  " << mobile << "                       \n";
        cout << "|-----------------------------------------------------------------------------------------|\n";
        cout << "|  Sr. No.  |       Name of the Item       |     Quantity    |     Rate    |     Amount   |\n";
        cout << "|-----------|------------------------------|-----------------|-------------|--------------|\n";
        if (product_quantity[j - 1])
        {
            cout << "|     " << i << "     |      " << shop_items[j - 1] << "                  |      " << product_quantity[j - 1] << "\t     |      " << set_price[j - 1] << "\t   |    " << amount[j - 1] << "\t  |\n";
            i++;
        }
        j++;

        if (product_quantity[j - 1])
        {
            cout << "|     " << i << "     |      " << shop_items[j - 1] << "\t\t\t   |      " << product_quantity[j - 1] << "\t     |      " << set_price[j - 1] << "\t   |    " << amount[j - 1] << "\t  |\n";
            i++;
        }
        j++;

        if (product_quantity[j - 1])
        {
            cout << "|     " << i << "     |      " << shop_items[j - 1] << "\t\t   |      " << product_quantity[j - 1] << "\t     |      " << set_price[j - 1] << "\t   |    " << amount[j - 1] << "\t  |\n";
            i++;
        }
        j++;

        if (product_quantity[j - 1])
        {
            cout << "|     " << i << "     |      " << shop_items[j - 1] << "\t\t   |      " << product_quantity[j - 1] << "\t     |      " << set_price[j - 1] << "\t   |    " << amount[j - 1] << "\t  |\n";
            i++;
        }
        j++;

        if (product_quantity[j - 1])
        {
            cout << "|     " << i << "     |      " << shop_items[j - 1] << "\t\t   |      " << product_quantity[j - 1] << "\t     |      " << set_price[j - 1] << "\t   |    " << amount[j - 1] << "\t  |\n";
            i++;
        }
        j++;

        cout << "|           |                              |                 |             |              |\n";
        cout << "|           |                              |                 |             |              |\n";
        cout << " -----------------------------------------------------------------------------------------\n";
        cout << "                                                                   TOTAL : " << total_bill << " " << endl;
        cout << "------------------------------------------------------------------------------------------\n";
        cout << "Thank you for visiting !! Hope to see you again" << endl;
    }
};

int main()
{
    Bill ABC;
    ABC.Information();
    ABC.user_items();
    ABC.print_bill();

    return 0;
}