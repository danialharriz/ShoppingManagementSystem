#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include<vector>
#include <iomanip>

using namespace std;

class Product
{
private:
    int pcode;
    float price;
    float dis;
    string pname;

public:
    Product(int code, float pr, float discount, const string& name): pcode(code), price(pr), dis(discount), pname(name) {}

    int getCode() const { return pcode; }
    float getPrice() const { return price; }
    float getDiscount() const { return dis; }
    string getName() const { return pname; }
};


class Shopping
{
protected:
    int pcode;
    float price;
    float dis;
    string pname;
    Product* products;

public:
    virtual void Receipt();
    void Menu();
    void Admin();
    void Buyer();
    void Add();
    void Edit();
    void Delete();
    void List();
};

class DiscountedProduct : public Shopping
{
public:
    void Receipt();
};

class SelectedItems : public Shopping
{
public:
    void Edit();
};

void Shopping ::Menu()
{
m:
    system("cls");
    int choice;
    string email;
    string password;

    cout << "\t\t\t ___________________" << endl;
    cout << "\t\t\t|                   | " << endl;
    cout << "\t\t\t|     MAIN MENU     |" << endl;
    cout << "\t\t\t|___________________|" << endl;
    cout << "\t\t\t                      " << endl;
    cout << "\t\t\t                      " << endl;
    cout << "\t\t\t1) Admin                    " << endl;
    cout << "\t\t                      " << endl;
    cout << "\t\t\t2) Buyer                    " << endl;
    cout << "\t\t                      " << endl;
    cout << "\t\t\t3) Exit                    " << endl;
    cout << "\t\t                      " << endl;
    cout << "\t\t\tPlease Select : ";
    cin >> choice;

    switch (choice)
    {
    case 1:
        system("cls");
        cout << "\t\t\t ___________________  " << endl;
        cout << "\t\t\t|                   | " << endl;
        cout << "\t\t\t|       LOGIN       | " << endl;
        cout << "\t\t\t|___________________| " << endl;
        cout << "\t\t\t                      " << endl;
        cout << "\t\t\t Please Login !" << endl;
        cout << "\t\t\t Enter Email : ";
        cin >> email;
        cout << "\t\t\t Password : ";
        cin >> password;

        if (email == "tempest@mail.com" && password == "tempest123")
        {
            Admin();
        }
        else
        {
            cout << "\n\n\t\tInvalid email / password !.." << endl;
            cout << "\t\tYou will now be redirected to the Main Menu..." << endl;
            cout << "\t\t" << system("pause");
        }
        break;

    case 2:
    {
        Buyer();
        break;
    }

    case 3:
    {
        exit(0);
        break;
    }

    default:
    {
        cout << "Invalid option. Pick again!";
    }
    }
    goto m;
}

void Shopping ::Admin()
{
m:
system("cls");
    int choice;

    cout << "\t\t\t ___________________" << endl;
    cout << "\t\t\t|                   | " << endl;
    cout << "\t\t\t|     ADMIN MENU    |" << endl;
    cout << "\t\t\t|___________________|" << endl;
    cout << "\t\t\t                      " << endl;
    cout << "\t\t\t                      " << endl;
    cout << "\t\t\t1) Add product                       " << endl;
    cout << "\t\t                      " << endl;
    cout << "\t\t\t2) Modify product                    " << endl;
    cout << "\t\t                      " << endl;
    cout << "\t\t\t3) Delete product                    " << endl;
    cout << "\t\t                      " << endl;
    cout << "\t\t\t4) Back to Main Menu                    " << endl;
    cout << "\t\t                      " << endl;
    cout << "\t\t\tPlease Select : ";
    cin >> choice;

    switch (choice)
    {
    case 1:
        Add();
        break;

    case 2:
        Edit();
        break;

    case 3:
        Delete();
        break;

    case 4:
        Menu();
        break;

    default:
        cout << "Invalid choice";
    }
    goto m;
}

void Shopping :: Buyer()
{
    system("cls");
    int choice;
    cout << "\t\t\t _______________________  " << endl;
    cout << "\t\t\t|                       | " << endl;
    cout << "\t\t\t|       BUYER MENU      | " << endl;
    cout << "\t\t\t|_______________________| " << endl;
    cout << "\t\t\t                      " << endl;
    cout << "\t\t\t 1) Buy product       " << endl;
    cout << "\t\t\t                      " << endl;
    cout << "\t\t\t 2) Go back           " << endl;
    cout << "\t\t\t                      " << endl;
    cout << "\t\t\t Enter your choice : ";
    cin >> choice;

    switch (choice)
    {
    case 1:
        {
            Shopping *product = new DiscountedProduct();
            product->Receipt();
            delete product;
            break;
        }

    case 2:
        Menu();
        break;

    default:
        cout << "Invalid choice";
    }

    return;
}

void Shopping ::Add()
{
m: 
    system("cls");
    fstream data;
    int c;
    int token = 0;
    float p;
    float d;
    string n;

    cout << "\t\t\t ___________________  " << endl;
    cout << "\t\t\t|                   | " << endl;
    cout << "\t\t\t|    ADD PRODUCT    | " << endl;
    cout << "\t\t\t|___________________| " << endl;
    cout << "\t\t\t                      " << endl;
    cout << "\t\t\t Product code of the product : ";
    cin >> pcode;
    cout << "\t\t\t Name of the product         : ";
    cin >> pname;
    cout << "\t\t\t Price of the product        : ";
    cin >> price;
    cout << "\t\t\t Discount on the product     : ";
    cin >> dis;

    data.open("database.txt", ios::in);

    if (!data)
    {
        data.open("database.txt", ios::app | ios::out);
        data.close();
    }
    else
    {
        data >> c >> n >> p >> d;

        while (!data.eof())
        {

            if (c == pcode)
            {
                token++;
            }

            data >> c >> n >> p >> d;
        }
        data.close();
    }

    if (token == 1)
    {
        system("cls");
        cout << "\t\tYou have entered a duplicated product code. Please re-enter the product details!" << endl;
        cout << "\t\t" << system("pause");
        goto m;
    }
    else
    {
        data.open("database.txt", ios::app | ios::out);
        data << "\t\t" << pcode << "\t\t" << pname << "\t\t" << price << "\t\t" << dis << "\n";
        data.close();
    }

    cout << "\n\n\t\t Record Inserted !" << endl;
    cout << "\t\t You will now be redirected to the Admin Menu.." << endl;
    cout << "\t\t" << system("pause");
}

void Shopping ::Edit()
{
    system("cls");
    fstream data, data1;
    int pkey;
    int token = 0;
    int c;
    float p;
    float d;
    string n;

    cout << "\t\t\t ___________________" << endl;
    cout << "\t\t\t|                   | " << endl;
    cout << "\t\t\t| Modify The Record | " << endl;
    cout << "\t\t\t|___________________| " << endl;
    cout << "\t\t\t                      " << endl;
    cout << "\t\t\t Product code : ";
    cin >> pkey;

    data.open("database.txt", ios ::in);

    if (!data)
    {
        cout << "\n\nFile doesn't exist!";
    }

    else
    {
        data1.open("database1.txt", ios::app | ios::out);
        data >> pcode >> pname >> price >> dis;

        while (!data.eof())
        {
            if (pkey == pcode)
            {
                cout << "\t\t\t Product new code    : ";
                cin >> c;
                cout << "\t\t\t Name of the product : ";
                cin >> n;
                cout << "\t\t\t Price               : ";
                cin >> p;
                cout << "\t\t\t Discount            : ";
                cin >> d;
                data1 << " " << c << " " << n << " " << p << " " << d << "\n";
                cout << "\n\n\t\t\t Record edited ";
                token++;
            }

            else
            {
                data1 << " " << pcode << " " << pname << " " << price << " " << dis << "\n";
            }
            data >> pcode >> pname >> price >> dis;
        }
        data.close();
        data1.close();

        remove("database.txt");
        rename("database1.txt", "database.txt");

        if (token == 0)
        {
            cout << "\n\n Record not found!";
        }
    }
}

void SelectedItems::Edit()
{
    Edit();
}

void Shopping ::Delete()
{
    system("cls");
    fstream data, data1;
    int pkey;
    int token = 0;

    cout << "\t\t\t ___________________" << endl;
    cout << "\t\t\t|                   | " << endl;
    cout << "\t\t\t| Delete The Record | " << endl;
    cout << "\t\t\t|___________________| " << endl;
    cout << "\t\t\t                      " << endl;
    cout << "\t\t\t Product code : ";
    cin >> pkey;

    data.open("database.txt", ios::in);

    if (!data)
    {
        cout << "File doesn't exist!";
    }

    else
    {
        data1.open("database1.txt", ios::app | ios::out);
        data >> pcode >> pname >> price >> dis;
        while (!data.eof())
        {

            if (pcode == pkey)
            {
                cout << "\n\n\t Product deleted succesfully";
                token++;
            }

            else
            {
                data1 << " " << pcode << " " << pname << " " << price << " " << dis << "\n";
            }

            data >> pcode >> pname >> price >> dis;
        }
        data.close();
        data1.close();

        remove("database.txt");
        rename("database1.txt", "database.txt");

        if (token == 0)
        {
            cout << "Record is not found!";
        }
    }
}

void Shopping ::List()
{
    fstream data;
    data.open("database.txt", ios::in);

    cout << "\n\n\t\t_______________________________________________\n";
    cout << "\t\tProduct No\t\tName\t\tPrice\n";
    data >> pcode >> pname >> price >> dis;
    cout << "\t\t_______________________________________________\n";

    while (!data.eof())
    {
        cout << "\t\t" << pcode << "\t\t\t" << pname << "\t\t" << price << "\n";
        data >> pcode >> pname >> price >> dis;
    }
    data.close();
}


void DiscountedProduct::Receipt()
{
    system("cls");
    fstream data;
    int arrc[100];
    int arrq[100];
    char choice;
    int c = 0;
    float amount = 0;
    float total = 0;
    float additionalDiscount = 10; // Additional discount percentage for discounted products

    cout << "\n\t\t-----------------------------------------------";
    cout << "\n\t\t|                 RECEIPT                      |";
    cout << "\n\t\t-----------------------------------------------";
    data.open("database.txt", ios::in);

    if (!data)
    {
        cout << "\n\n Empty database";
    }
    else
    {
        data.close();

        List();
        cout << "\n\t\t\t ___________________" << endl;
        cout << "\t\t\t|                   | " << endl;
        cout << "\t\t\t|    Place Order    | " << endl;
        cout << "\t\t\t|___________________| " << endl;
        cout << "\t\t\t                      " << endl;
        do
        {
            m:
            cout << "\nEnter product code : ";
            cin >> arrc[c];
            cout << "\nEnter the product quantity : ";
            cin >> arrq[c];

            for (int i = 0; i < c; i++)
            {
                if (arrc[c] == arrc[i] && arrq[c] == arrq[i])
                {
                    cout << "\n\n Duplicated product code and quantity. Try Again!";
                    goto m;
                }
            }
            cout << "\n\n Do you want to buy another product? (Y = YES, N = NO) : ";
            cin >> choice;
            c++;
        } while (choice == 'Y' || choice == 'y');

        // Apply additional discount for discounted products
        float discount = additionalDiscount + dis;

        // Calculate and display the receipt
        system("cls");
        cout << "\n\n\t\t\t_______________RECEIPT__________________" << endl;
        cout << "ProductNo" << setw(20) << "Product Name" << setw(20) << "Product Quantity" << setw(10) << "Price" << setw(10) << "Amount" << setw(20) << "Discounted Price\n";


        data.open("database.txt", ios::in);
        data >> pcode >> pname >> price >> dis;
        while (!data.eof())
        {
            for (int i = 0; i < c; i++)
            {
                if (pcode == arrc[i])
                {
                    amount = price * arrq[i];
                    float discountedPrice = amount - (amount * discount / 100);
                    total += discountedPrice;
                    cout << endl <<setw(5) << pcode << setw(22) << pname << setw(15) << arrq[i] << setw(15) << price << setw(10) << amount << setw(15) << discountedPrice << endl;
                }
            }
            data >> pcode >> pname >> price >> dis;
        }
        data.close();
    }
    cout << "\n\nTotal Amount : " << total << endl;
    system("pause");
}



void Shopping::Receipt()
{
    fstream data;
    int arrc[100];
    int arrq[100];
    char choice;
    int c = 0;
    float amount = 0;
    float total = 0;
    float additionalDiscount = 10; // Additional discount percentage for discounted products

    cout << "\n---------------------------------------";
    cout << "\n\t\t RECEIPT ";
    data.open("database.txt", ios::in);

    if (!data)
    {
        cout << "\n\n Empty database";
    }
    else
    {
        data.close();

        List();
        cout << "\n\t\t\t ___________________" << endl;
        cout << "\t\t\t|                   | " << endl;
        cout << "\t\t\t|    Place Order    | " << endl;
        cout << "\t\t\t|___________________| " << endl;
        cout << "\t\t\t                      " << endl;
        do
        {
            m:
            cout << "\n\nEnter product code : ";
            cin >> arrc[c];
            cout << "\n\nEnter the product quantity : ";
            cin >> arrq[c];

            for (int i = 0; i < c; i++)
            {
                if (arrc[c] == arrc[i] && arrq[c] == arrq[i])
                {
                    cout << "\n\n Duplicated product code and quantity. Try Again!";
                    goto m;
                }
            }
            cout << "\n\n Do you want to buy another product? (Y = YES, N = NO) : ";
            cin >> choice;
            c++;
        } while (choice == 'Y' || choice == 'y');

        // Apply additional discount for discounted products
        float discount = additionalDiscount + dis;

        // Calculate and display the receipt
        cout << "\n\n\t\t\t_______________RECEIPT__________________" << endl;
        cout << "ProductNo" << setw(10) << "Product Name" << setw(15) << "Product Quantity" << setw(10) << "Price" << setw(10) << "Amount" << setw(20) << "Discounted Price\n";


      data.open("database.txt", ios::in);
      data >> pcode >> pname >> price >> dis;

      cout << "ProductNo" << setw(10) << "Product Name" << setw(15) << "Product Quantity" << setw(10) << "Price" << setw(10) << "Amount" << setw(20) << "Discounted Price\n";

    while (!data.eof())
    {
        for (int i = 0; i < c; i++)
        {
            if (pcode == arrc[i])
            {
                amount = price * arrq[i];
                float discountedPrice = amount - (amount * discount / 100);
                total += discountedPrice;
                cout << pcode << setw(15) << pname << setw(20) << arrq[i] << setw(10) << price << setw(10) << amount << setw(20) << discountedPrice << endl;
            }
        }
        data >> pcode >> pname >> price >> dis;
    }
    data.close();
    }
    cout << "\n\nTotal Amount : " << total;
}

int main()
{
    Shopping p;
    p.Menu();

    return 0;
}
