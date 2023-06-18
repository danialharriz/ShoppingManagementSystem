#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;

class Product
{
protected:
    int pcode;
    string pname;
    float price;
    float dis;

public:
    virtual void Input() = 0;
    virtual void Output() = 0;
    virtual void Update() = 0;
    virtual void Delete() = 0;
    virtual void List() = 0;
    virtual void Receipt() = 0;
};

class Shopping : public Product
{
public:
    void Input() override;
    void Output() override;
    void Update() override;
    void Delete() override;
    void List() override;
    void Receipt() override;

    void Menu();
};

void Shopping::Input()
{
    system("cls");
    ofstream file;
    file.open("product.txt", ios::app);
    cout << "\n\t\t\t ___________________" << endl;
    cout << "\t\t\t|                   | " << endl;
    cout << "\t\t\t|   ADD NEW PRODUCT |" << endl;
    cout << "\t\t\t|___________________|" << endl;
    cout << "\t\t\t                      " << endl;
    cout << "\t\t\t                      " << endl;
    cout << "\t\t\tEnter product code : ";
    cin >> pcode;
    cout << "\t\t\tEnter product name : ";
    cin >> pname;
    cout << "\t\t\tEnter price : ";
    cin >> price;
    cout << "\t\t\tEnter discount : ";
    cin >> dis;

    file << pcode << " " << pname << " " << price << " " << dis << endl;
    file.close();

    cout << "\n\t\t\t Product added successfully!" << endl;
}

void Shopping::Output()
{
    system("cls");
    fstream file;
    file.open("product.txt", ios::in);
    int pcode_out;
    bool found = false;

    cout << "\n\t\t\t ___________________" << endl;
    cout << "\t\t\t|                   | " << endl;
    cout << "\t\t\t|   SEARCH PRODUCT  |" << endl;
    cout << "\t\t\t|___________________|" << endl;
    cout << "\t\t\t                      " << endl;
    cout << "\t\t\t                      " << endl;
    cout << "\t\t\tEnter the product code : ";
    cin >> pcode_out;

    cout << "\n\t\t\t ___________________" << endl;
    cout << "\t\t\t|                   | " << endl;
    cout << "\t\t\t|   PRODUCT DETAILS |" << endl;
    cout << "\t\t\t|___________________|" << endl;
    cout << "\t\t\t                      " << endl;
    cout << "\t\t\t                      " << endl;
    cout << "CODE   NAME            PRICE          DISCOUNT" << endl;

    while (file >> pcode >> pname >> price >> dis)
    {
        if (pcode == pcode_out)
        {
            cout << pcode << "   " << pname << "            " << price << "              " << dis << endl;
            found = true;
        }
    }
    file.close();

    if (!found)
    {
        cout << "\n\t\t\t Product code not found!" << endl;
    }
}

void Shopping::Update()
{
    system("cls");
    fstream file;
    file.open("product.txt", ios::in);
    ofstream temp;
    temp.open("temp.txt", ios::out);
    int pcode_upd;
    bool found = false;

    cout << "\n\t\t\t ___________________" << endl;
    cout << "\t\t\t|                   | " << endl;
    cout << "\t\t\t|   UPDATE PRODUCT  |" << endl;
    cout << "\t\t\t|___________________|" << endl;
    cout << "\t\t\t                      " << endl;
    cout << "\t\t\t                      " << endl;
    cout << "\t\t\tEnter the product code to update : ";
    cin >> pcode_upd;

    while (file >> pcode >> pname >> price >> dis)
    {
        if (pcode == pcode_upd)
        {
            cout << "\n\t\t\t ___________________" << endl;
            cout << "\t\t\t|                   | " << endl;
            cout << "\t\t\t|   NEW INFORMATION |" << endl;
            cout << "\t\t\t|___________________|" << endl;
            cout << "\t\t\t                      " << endl;
            cout << "\t\t\t                      " << endl;
            cout << "\t\t\tEnter product name : ";
            cin >> pname;
            cout << "\t\t\tEnter price : ";
            cin >> price;
            cout << "\t\t\tEnter discount : ";
            cin >> dis;

            temp << pcode << " " << pname << " " << price << " " << dis << endl;
            found = true;
            cout << "\n\t\t\t Product updated successfully!" << endl;
        }
        else
        {
            temp << pcode << " " << pname << " " << price << " " << dis << endl;
        }
    }
    file.close();
    temp.close();

    if (!found)
    {
        cout << "\n\t\t\t Product code not found!" << endl;
    }
    else
    {
        remove("product.txt");
        rename("temp.txt", "product.txt");
    }
}

void Shopping::Delete()
{
    system("cls");
    fstream file;
    file.open("product.txt", ios::in);
    ofstream temp;
    temp.open("temp.txt", ios::out);
    int pcode_del;
    bool found = false;

    cout << "\n\t\t\t ___________________" << endl;
    cout << "\t\t\t|                   | " << endl;
    cout << "\t\t\t|   DELETE PRODUCT  |" << endl;
    cout << "\t\t\t|___________________|" << endl;
    cout << "\t\t\t                      " << endl;
    cout << "\t\t\t                      " << endl;
    cout << "\t\t\tEnter the product code to delete : ";
    cin >> pcode_del;

    while (file >> pcode >> pname >> price >> dis)
    {
        if (pcode != pcode_del)
        {
            temp << pcode << " " << pname << " " << price << " " << dis << endl;
        }
        else
        {
            found = true;
        }
    }
    file.close();
    temp.close();

    if (found)
    {
        remove("product.txt");
        rename("temp.txt", "product.txt");
        cout << "\n\t\t\t Product deleted successfully!" << endl;
    }
    else
    {
        cout << "\n\t\t\t Product code not found!" << endl;
    }
}

void Shopping::List()
{
    system("cls");
    ifstream file;
    file.open("product.txt", ios::in);

    cout << "\n\t\t\t ___________________" << endl;
    cout << "\t\t\t|                   | " << endl;
    cout << "\t\t\t|   PRODUCT LIST    |" << endl;
    cout << "\t\t\t|___________________|" << endl;
    cout << "\t\t\t                      " << endl;
    cout << "\t\t\t                      " << endl;
    cout << "CODE   NAME            PRICE          DISCOUNT" << endl;

    while (file >> pcode >> pname >> price >> dis)
    {
        cout << pcode << "   " << pname << "            " << price << "              " << dis << endl;
    }
    file.close();
}

void Shopping::Receipt()
{
    system("cls");
    ifstream file;
    file.open("product.txt", ios::in);
    ofstream receipt;
    receipt.open("receipt.txt", ios::out);
    int pcode_rec;
    bool found = false;
    float total_price = 0;

    cout << "\n\t\t\t ___________________" << endl;
    cout << "\t\t\t|                   | " << endl;
    cout << "\t\t\t|   GENERATE RECEIPT|" << endl;
    cout << "\t\t\t|___________________|" << endl;
    cout << "\t\t\t                      " << endl;
    cout << "\t\t\t                      " << endl;
    cout << "\t\t\tEnter the product code (enter 0 to end) : ";
    cin >> pcode_rec;

    receipt << "CODE   NAME            PRICE          DISCOUNT" << endl;

    while (pcode_rec != 0)
    {
        file.clear();
        file.seekg(0, ios::beg);

        while (file >> pcode >> pname >> price >> dis)
        {
            if (pcode == pcode_rec)
            {
                receipt << pcode << "   " << pname << "            " << price << "              " << dis << endl;
                total_price += price * (1 - dis / 100);
                found = true;
                break;
            }
        }

        cout << "\t\t\tEnter the product code (enter 0 to end) : ";
        cin >> pcode_rec;
    }
    file.close();
    receipt << "Total Price: " << total_price << endl;
    receipt.close();

    if (found)
    {
        cout << "\n\t\t\t Receipt generated successfully!" << endl;
    }
    else
    {
        cout << "\n\t\t\t Product code not found!" << endl;
    }
}

void Shopping::Menu()
{
    int choice;
    do
    {
        system("cls");
        cout << "\n\t\t\t ___________________" << endl;
        cout << "\t\t\t|                   | " << endl;
        cout << "\t\t\t|   SHOPPING MENU   |" << endl;
        cout << "\t\t\t|___________________|" << endl;
        cout << "\t\t\t                      " << endl;
        cout << "\t\t\t                      " << endl;
        cout << "\t\t\t 1. Add Product" << endl;
        cout << "\t\t\t 2. Search Product" << endl;
        cout << "\t\t\t 3. Update Product" << endl;
        cout << "\t\t\t 4. Delete Product" << endl;
        cout << "\t\t\t 5. List Products" << endl;
        cout << "\t\t\t 6. Generate Receipt" << endl;
        cout << "\t\t\t 7. Exit" << endl;
        cout << "\n\t\t\t Enter your choice : ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            Input();
            break;
        case 2:
            Output();
            break;
        case 3:
            Update();
            break;
        case 4:
            Delete();
            break;
        case 5:
            List();
            break;
        case 6:
            Receipt();
            break;
        case 7:
            cout << "\n\t\t\t Exiting the program..." << endl;
            break;
        default:
            cout << "\n\t\t\t Invalid choice! Please try again." << endl;
        }

        cout << "\n\t\t\t Press enter to continue...";
        cin.ignore();
        cin.get();
    } while (choice != 7);
}

int main()
{
    Shopping s;
    s.Menu();
    return 0;
}
