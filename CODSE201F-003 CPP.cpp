#include<iostream>
#include<fstream>
#include<windows.h>
#include<conio.h>
#include<iomanip>
using namespace std;
int lgch,searchCode;
char ch;
class login
{
private:
    string username,password,inUser,inPass;
    int input,loggedIn;
    char inP;
public:
    void lIn()
    {
        while(loggedIn==0)
        {
            system("cls");system("color 02");
            cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<"\t\t\t\t**************************************************";
            cout<<endl<<"\t\t\t\t*"<<setw(27)<<"Welcome"<<setw(22)<<"*";
            cout<<endl<<"\t\t\t\t*"<<setw(24)<<"To"<<setw(25)<<"*";
            cout<<endl<<"\t\t\t\t*"<<setw(32)<<"Red Eye Computers"<<setw(17)<<"*";
            cout<<endl<<"\t\t\t\t**************************************************";
            cout<<endl<<"\t\t\t\t*"<<setw(27)<<"1.Sign Up"<<setw(22)<<"*";
            cout<<endl<<"\t\t\t\t*"<<setw(27)<<"2.Sign In"<<setw(22)<<"*";
            cout<<endl<<"\t\t\t\t*"<<setw(26)<<"3.Exit"<<setw(23)<<"*";
            cout<<endl<<"\t\t\t\t**************************************************";
            cout<<endl<<"\t\t\t\t\t\t\t";
            cin>>input;
            system("cls");system("color 0C");
            fstream afile;
            if (input==1)
            {
                inPass="";
                afile.open("login.dat",ios::app);
                cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<"\t\t\t\t**************************************************";
                cout<<endl<<"\t\t\t\t*"<<setw(27)<<"Sign Up"<<setw(22)<<"*";
                cout<<endl<<"\t\t\t\t**************************************************";
                cout<<endl<<"\t\t\t\t*"<<setw(27)<<"Enter Username: "<<setw(22)<<"*";
                cout<<endl<<"\t\t\t\t*"<<setw(27)<<"Enter Password: "<<setw(22)<<"*";
                cout<<endl<<"\t\t\t\t**************************************************";
                cout<<endl<<"\t\t\t\t\t\t\t";
                HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
                COORD pos = {60, 12};SetConsoleCursorPosition(hConsole, pos);
                cin>>inUser;
                pos = {60, 13};SetConsoleCursorPosition(hConsole, pos);
                inP = getch();
                while(inP != 13)
                {
                    inPass=inPass+inP;
                    cout << '*';
                    inP = getch();
                }
                afile<<inUser<<endl;
                afile<<inPass<<endl;
                pos = {0, 15};SetConsoleCursorPosition(hConsole, pos);
                cout<<"User Successfully Created";
                Sleep(500);
                afile.close();
            }
            if (input==2)
            {
                afile.open("login.dat",ios::in);
                inPass="";
                cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<"\t\t\t\t**************************************************";
                cout<<endl<<"\t\t\t\t*"<<setw(27)<<"Sign In"<<setw(22)<<"*";
                cout<<endl<<"\t\t\t\t**************************************************";
                cout<<endl<<"\t\t\t\t*"<<setw(27)<<"Enter Username: "<<setw(22)<<"*";
                cout<<endl<<"\t\t\t\t*"<<setw(27)<<"Enter Password: "<<setw(22)<<"*";
                cout<<endl<<"\t\t\t\t**************************************************";
                cout<<endl<<"\t\t\t\t\t\t\t";
                HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
                COORD pos = {60, 12};SetConsoleCursorPosition(hConsole, pos);
                cin>>inUser;
                pos = {60, 13};SetConsoleCursorPosition(hConsole, pos);
                inP = getch();
                while(inP != 13)
                {
                    inPass=inPass+inP;
                    cout << '*';
                    inP = getch();
                }
                afile>>username;
                while(afile)
                {
                    afile>>password;
                    if (username==inUser && password==inPass)
                    {
                        cout<<endl<<"Login Successful"<<endl;
                        loggedIn=1;lgch=1;
                    }
                    afile>>username;
                }
                if (loggedIn==0)
                {
                    cout<<"\nIncorrect Username or Password"<<endl;
                    Sleep(1000);
                }
                afile.close();
            }
            if (input==3)
            {
                cout<<"Have a nice day"<<endl;
                break;
            }
        }
    }
    int check()
    {
        return loggedIn;
    }
    string getUser()
    {
        return inUser;
    }
    void signOut()
    {
        loggedIn=0;
    }
};

class customer
{
protected:
    int cusnum,cusage;
    string cusname;
    float loyalty;
public:
    void newCustomer()
    {
        cout<<"Enter Customer Number: ";
        cin>>cusnum;
        cout<<"Enter Customer Name: ";
        cin>>cusname;
        cout<<"Enter Customer Age: ";
        cin>>cusage;
        fstream bfile;
        loyalty=0;
        bfile.open("customer.dat",ios::app);
        bfile<<cusnum<<endl;
        bfile<<cusname<<endl;
        bfile<<cusage<<endl;
        bfile<<loyalty<<endl;
        bfile.close();
    }
    void listCustomer()
    {
        fstream cfile;
        cfile.open("customer.dat",ios::in);
        cout<<endl<<"\t\t\t************************************************************"<<endl<<"\t\t\t";
        cout<<setw(20)<<"Customer Number"<<setw(20)<<"Customer Name"<<setw(10)<<"Age"<<setw(10)<<"Loyalty"<<endl;
        cout<<"\t\t\t************************************************************"<<endl;
        cfile>>cusnum;
        while (cfile)
        {
            cfile>>cusname;
            cfile>>cusage;
            cfile>>loyalty;
            cout<<"\t\t\t"<<setw(20)<<cusnum<<setw(20)<<cusname<<setw(10)<<cusage<<setw(10)<<loyalty<<endl;
            cfile>>cusnum;
        }
    }
    void searchCustomer()
    {
        fstream cfile;
        cfile.open("customer.dat",ios::in);
        cfile>>cusnum;
        while(cfile)
        {
            cfile>>cusname;
            cfile>>cusage;
            cfile>>loyalty;
            if (cusnum==searchCode)
            {
                break;
            }
            cfile>>cusnum;
        }
        cfile.close();
    }
    void displayCustomer()
    {
        system("cls");
        cout<<"Enter Customer Number: ";
        cin>>searchCode;
        searchCustomer();
        cout<<endl<<"\t\t\t************************************************************"<<endl<<"\t\t\t";
        cout<<setw(20)<<"Customer Number"<<setw(20)<<"Customer Name"<<setw(10)<<"Age"<<setw(10)<<"Loyalty"<<endl;
        cout<<"\t\t\t************************************************************"<<endl;
        cout<<"\t\t\t"<<setw(20)<<cusnum<<setw(20)<<cusname<<setw(10)<<cusage<<setw(10)<<loyalty<<endl;
        cout<<endl<<"Press anykey to continue"<<endl;ch=getch();
    }
    void replaceCustomer()
    {
        int tempnum,tempage;
        string tempcName;
        float temployalty;
        fstream efile;
        fstream dfile;
        efile.open("temp.dat",ios::app);
        dfile.open("customer.dat",ios::in);
        dfile>>tempnum;
        while(dfile)
        {
            dfile>>tempcName;
            dfile>>tempage;
            dfile>>temployalty;
            if (tempnum==cusnum)
            {
                efile<<cusnum<<endl;
                efile<<cusname<<endl;
                efile<<cusage<<endl;
                efile<<loyalty<<endl;
            }
            else
            {
                efile<<tempnum<<endl;
                efile<<tempcName<<endl;
                efile<<tempage<<endl;
                efile<<temployalty<<endl;
            }
            dfile>>tempnum;
        }
        efile.close();
        dfile.close();
        remove("customer.dat");
        rename("temp.dat","customer.dat");
    }

};

class stock
{
protected:
    int stockCode,stocktype,quantity;
    string stockName,stypename;
    float price;
    fstream dfile;
public:
    void addNewStock()
    {
        while(true)
        {
            cout<<"Enter Stock Code: ";
            cin>>searchCode;
            searchStock();
            if (searchCode==stockCode)
            {
                cout<<"Code already taken"<<endl;
            }
            else
            {
                stockCode=searchCode;
                break;
            }
        }
        system("cls");
        cout<<"Enter Stock Type: \n\t\t1.Mouse\n\t\t2.Keyboard\n\t\t3.Monitor\n\t\t4.Speakers\n\t\t5.Headset\n\t\t6.Laptops\n\t\t7.GPUs\n\t\t8.Cases\n\t\t9.RAM\n\t\t10.Motherboards\n\t\t11.Power Supply: ";
        cin>>stocktype;
        while(true)
        {
            if(stocktype==1)
            {
                stypename="Mouse";
                break;
            }
            else if(stocktype==2)
            {
                stypename="Keyboard";
                break;
            }
            else if(stocktype==3)
            {
                stypename="Monitor";
                break;
            }
            else if(stocktype==4)
            {
                stypename="Speakers";
                break;
            }
            else if(stocktype==5)
            {
                stypename="Headset";
                break;
            }
            else if(stocktype==6)
            {
                stypename="Laptops";
                break;
            }
            else if(stocktype==7)
            {
                stypename="GPU";
                break;
            }
            else if(stocktype==8)
            {
                stypename="Case";
                break;
            }
            else if(stocktype==9)
            {
                stypename="RAM";
                break;
            }
            else if(stocktype==10)
            {
                stypename="Motherboards";
                break;
            }
            else if(stocktype==11)
            {
                stypename="PowerSupply";
                break;
            }
            else
            {
                cout<<"Enter Valid Type"<<endl;
            }
        }
        cout<<"Enter "<<stypename<<" Name: ";
        cin>>stockName;
        cout<<"Enter "<<stockName<<" Price: ";
        cin>>price;
        cout<<"Enter Quantity: ";
        cin>>quantity;
        dfile.open("stock.dat",ios::app);
        dfile<<stockCode<<endl;
        dfile<<stypename<<endl;
        dfile<<stockName<<endl;
        dfile<<price<<endl;
        dfile<<quantity<<endl;
        dfile.close();
        cout<<endl<<"Press anykey to continue"<<endl;ch=getch();
    }
    void searchStock()
    {
        dfile.open("stock.dat",ios::in);
        dfile>>stockCode;
        while(dfile)
        {
            dfile>>stypename;
            dfile>>stockName;
            dfile>>price;
            dfile>>quantity;
            if (stockCode==searchCode)
            {
                break;
            }
            dfile>>stockCode;
        }
        dfile.close();
    }
    void editStock()
    {
        int input;
        cout<<endl<<"Enter Stock Code: ";
        cin>>searchCode;
        system("cls");
        searchStock();
        cout<<endl<<"\t\t\t************************************************************"<<endl<<"\t\t\t";
        cout<<setw(7)<<"Code"<<setw(13)<<"Type"<<setw(20)<<"Name"<<setw(10)<<"Price"<<setw(10)<<"Quantity"<<endl;
        cout<<endl<<"\t\t\t************************************************************"<<endl;
        cout<<"\t\t\t"<<setw(10)<<stockCode<<setw(10)<<stypename<<setw(20)<<stockName<<setw(10)<<price<<setw(10)<<quantity<<endl<<endl;
        cout<<"\t\t\t\t\t-----------------------------------"<<endl;
        cout<<"\t\t\t\t"<<setw(8)<<"|"<<setw(27)<<"What do you want to edit?"<<setw(9)<<"|"<<endl;
        cout<<"\t\t\t\t\t-----------------------------------"<<endl;
        cout<<"\t\t\t\t"<<setw(8)<<"|"<<setw(6)<<"1"<<setw(6)<<"|"<<setw(16)<<"Price"<<setw(8)<<"|"<<endl;
        cout<<"\t\t\t\t\t-----------------------------------"<<endl;
        cout<<"\t\t\t\t"<<setw(8)<<"|"<<setw(6)<<"2"<<setw(6)<<"|"<<setw(16)<<"Quantity"<<setw(8)<<"|"<<endl;
        cout<<"\t\t\t\t\t-----------------------------------"<<endl;
        cout<<"\t\t\t\t"<<setw(8)<<"|"<<setw(23)<<"Enter value (1/2): "<<setw(13)<<"|"<<endl;
        cout<<"\t\t\t\t\t-----------------------------------"<<endl;
        HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
        COORD pos = {63,14};SetConsoleCursorPosition(hConsole, pos);
        cin>>input;
        pos = {0,16};SetConsoleCursorPosition(hConsole, pos);
        while(true)
        {
            if (input==1)
            {
                cout<<"\t\t\t\t"<<setw(8)<<"|"<<setw(23)<<"Enter New Price: "<<setw(13)<<"|"<<endl;
                cout<<"\t\t\t\t\t-----------------------------------"<<endl;
                pos = {63,16};SetConsoleCursorPosition(hConsole, pos);
                cin>>price;
                break;
            }
            else if (input==2)
            {
                cout<<"\t\t\t\t"<<setw(8)<<"|"<<setw(23)<<"Enter New Quantity: "<<setw(13)<<"|"<<endl;
                cout<<"\t\t\t\t\t-----------------------------------"<<endl;
                pos = {63,16};SetConsoleCursorPosition(hConsole, pos);
                cin>>quantity;
                break;
            }
            else
                cout<<"Enter Valid Input";
        }
        replaceStock();
    }
    void replaceStock()
    {
        int tempCode,tempquantity;
        string tempName,ttypename;
        float tempprice;
        fstream efile;
        efile.open("temp.dat",ios::app);
        dfile.open("stock.dat",ios::in);
        dfile>>tempCode;
        while(dfile)
        {
            dfile>>ttypename;
            dfile>>tempName;
            dfile>>tempprice;
            dfile>>tempquantity;
            if (tempCode==stockCode)
            {
                efile<<stockCode<<endl;
                efile<<stypename<<endl;
                efile<<stockName<<endl;
                efile<<price<<endl;
                efile<<quantity<<endl;
            }
            else
            {
                efile<<tempCode<<endl;
                efile<<ttypename<<endl;
                efile<<tempName<<endl;
                efile<<tempprice<<endl;
                efile<<tempquantity<<endl;
            }
            dfile>>tempCode;
        }
        efile.close();
        dfile.close();
        remove("stock.dat");
        rename("temp.dat","stock.dat");
    }
    void listStock()
    {
        dfile.open("stock.dat",ios::in);
        cout<<endl<<"\t\t\t************************************************************"<<endl<<"\t\t\t";
        cout<<setw(7)<<"Code"<<setw(13)<<"Type"<<setw(20)<<"Name"<<setw(10)<<"Price"<<setw(10)<<"Quantity";
        cout<<endl<<"\t\t\t************************************************************"<<endl;
        dfile>>stockCode;
        while (dfile)
        {
            dfile>>stypename;
            dfile>>stockName;
            dfile>>price;
            dfile>>quantity;
            cout<<"\t\t\t"<<setw(7)<<stockCode<<setw(13)<<stypename<<setw(20)<<stockName<<setw(10)<<price<<setw(10)<<quantity<<endl;
            dfile>>stockCode;
        }
        dfile.close();
    }
    void displayStock()
    {
        cout<<endl<<"Enter Stock Code: ";
        cin>>searchCode;
        searchStock();
        cout<<endl<<"\t\t\t************************************************************"<<endl<<"\t\t\t";
        cout<<setw(7)<<"Code"<<setw(13)<<"Type"<<setw(20)<<"Name"<<setw(10)<<"Price"<<setw(10)<<"Quantity";
        cout<<endl<<"\t\t\t************************************************************"<<endl;
        cout<<"\t\t\t"<<setw(10)<<stockCode<<setw(10)<<stypename<<setw(20)<<stockName<<setw(10)<<price<<setw(10)<<quantity<<endl;
        cout<<endl<<"Press anykey to continue"<<endl;ch=getch();
    }
};

class transaction:public stock,public customer
{
private:
    int input,trnum,bquantity,total;
    fstream tfile;
public:
    void newTransaction()
    {
        system("cls");
        cout<<endl<<"\t\t\t\t\t-----------------------------------"<<endl;
        cout<<"\t\t\t\t"<<setw(8)<<"|"<<setw(5)<<"1"<<setw(5)<<"|"<<setw(20)<<"Registered Customer"<<setw(6)<<"|"<<endl;
        cout<<"\t\t\t\t\t-----------------------------------"<<endl;
        cout<<"\t\t\t\t"<<setw(8)<<"|"<<setw(5)<<"2"<<setw(5)<<"|"<<setw(20)<<"Non-Registered Customer"<<setw(3)<<"|"<<endl;
        cout<<"\t\t\t\t\t-----------------------------------"<<endl;
        cout<<"\t\t\t\t"<<setw(8)<<"|"<<setw(33)<<"Any Other Character to Go Back"<<setw(3)<<"|"<<endl;
        cout<<"\t\t\t\t\t-----------------------------------"<<endl;
        cout<<"\t\t\t\t"<<setw(8)<<"|"<<setw(23)<<"Enter value (1/2): "<<setw(13)<<"|"<<endl;
        cout<<"\t\t\t\t\t-----------------------------------"<<endl;
        HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
        COORD pos = {63, 8};SetConsoleCursorPosition(hConsole, pos);
        cin>>input;
        pos = {0, 10};SetConsoleCursorPosition(hConsole, pos);
        if(input==1)
        {
            registered();
        }
        else if(input==2)
        {
            unregistered();
        }
    }
    void registered()
    {
        cout<<"\t\t\t\t"<<setw(8)<<"|"<<setw(30)<<"Enter Transaction Number: "<<setw(6)<<"|"<<endl;
        cout<<"\t\t\t\t\t-----------------------------------"<<endl;
        HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
        COORD pos = {70, 10};SetConsoleCursorPosition(hConsole, pos);
        cin>>trnum;
        pos = {0, 12};SetConsoleCursorPosition(hConsole, pos);
        while(true)
        {
            cout<<"\t\t\t\t"<<setw(8)<<"|"<<setw(30)<<"Enter Customer Number: "<<setw(6)<<"|"<<endl;
            cout<<"\t\t\t\t\t-----------------------------------"<<endl;
            pos = {70, 12};SetConsoleCursorPosition(hConsole, pos);
            cin>>searchCode;
            pos = {0, 14};SetConsoleCursorPosition(hConsole, pos);
            searchCustomer();
            if (cusnum==searchCode)
            {
                tfile.open("transaction"+std::to_string(trnum)+".dat",ios::out);
                tfile<<cusnum<<endl;
                tfile.close();
                break;
            }
            else
                cout<<"Invalid Customer Number";
        }
        transactions();

    }
    void unregistered()
    {
        cout<<"\t\t\t\t"<<setw(8)<<"|"<<setw(30)<<"Enter Transaction Number: "<<setw(6)<<"|"<<endl;
        cout<<"\t\t\t\t\t-----------------------------------"<<endl;
        cout<<"\t\t\t\t\t-----------------------------------"<<endl;
        cout<<"\t\t\t\t\t-----------------------------------"<<endl;
        HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
        COORD pos = {70, 10};SetConsoleCursorPosition(hConsole, pos);
        cin>>trnum;
        pos = {0, 12};SetConsoleCursorPosition(hConsole, pos);
        cusnum=0;
        tfile.open("transaction"+std::to_string(trnum)+".dat",ios::out);
        tfile<<cusnum<<endl;
        tfile.close();
        transactions();

    }
    void transactions()
    {
        while(true)
        {
            HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
            COORD pos = {0, 14};SetConsoleCursorPosition(hConsole, pos);
            cout<<"\t\t\t\t"<<setw(8)<<"|"<<setw(30)<<"Enter Stock Code: "<<setw(6)<<"|"<<endl;
            cout<<"\t\t\t\t\t-----------------------------------"<<endl;
            pos = {70, 14};SetConsoleCursorPosition(hConsole, pos);
            cin>>searchCode;
            pos = {0, 16};SetConsoleCursorPosition(hConsole, pos);
            searchStock();
            if (stockCode==searchCode)
            {
                if(quantity==0)
                {
                    cout<<"\t\t\t\t"<<setw(8)<<"|"<<setw(30)<<"No Stock Available"<<setw(6)<<"|"<<endl;
                    cout<<"\t\t\t\t\t-----------------------------------"<<endl;
                }
                else
                {
                    cout<<"\t\t\t\t"<<setw(8)<<"|"<<setw(30)<<"Enter Quantity: "<<setw(6)<<"|"<<endl;
                    cout<<"\t\t\t\t\t-----------------------------------"<<endl;
                    pos = {70, 16};SetConsoleCursorPosition(hConsole, pos);
                    cin>>bquantity;
                    if((quantity-bquantity)>=0)
                    {
                        tfile.open("transaction"+std::to_string(trnum)+".dat",ios::app);
                        tfile<<stockCode<<endl;
                        tfile<<bquantity<<endl;
                        tfile<<price<<endl;
                        tfile.close();
                        quantity=quantity-bquantity;
                        replaceStock();
                        cout<<"More items?\n1.Yes\n2.No\t ";
                        cin>>input;
                        if (input==2)
                            break;
                    }
                    else
                    {
                        cout<<"Insufficent Stock"<<endl;
                    }
                }
            }
            else
                cout<<"Invalid Stock Code"<<endl;
        }
        searchTransaction();
    }
    void searchTransaction()
    {
        total=0;
        tfile.open("transaction"+std::to_string(trnum)+".dat",ios::in);
        if (tfile.fail())
        {
            cout<<"Transaction not found";
            Sleep(500);
        }
        else
        {
            tfile>>cusnum;
            tfile>>stockCode;
            while(tfile)
            {
                tfile>>bquantity;
                tfile>>price;
                total=total+(price*bquantity);
                tfile>>stockCode;
            }
            tfile.close();
            if (loyalty>=20)
            {
                total=total-(total*loyalty/100);
                loyalty=0;
                searchCode=cusnum;
                searchCustomer();
                replaceCustomer();
            }
            if ((loyalty+(total*1/10000))<=25)
            {
                loyalty=loyalty+(total*1/10000);

                searchCode=cusnum;
                searchCustomer();
                replaceCustomer();
            }
            displayTransaction();
        }
    }
    void displayTransaction()
    {
        cout<<endl<<"\t\t\t***************************************************************"<<endl<<"\t\t\t";
        cout<<"Transaction Number: "<<trnum<<endl;
        tfile.open("transaction"+std::to_string(trnum)+".dat",ios::in);
        tfile>>cusnum;
        cout<<"\t\t\t"<<"Customer Number: "<<cusnum<<endl;
        cout<<"\t\t\t"<<setw(10)<<"Code"<<setw(20)<<"Name"<<setw(10)<<"Price"<<setw(10)<<"Quantity";
        cout<<endl<<"\t\t\t***************************************************************"<<endl;
        tfile>>searchCode;
        while(tfile)
        {
            searchStock();
            tfile>>bquantity;
            tfile>>price;
            cout<<"\t\t\t"<<setw(10)<<stockCode<<setw(20)<<stockName<<setw(10)<<price<<setw(10)<<bquantity<<setw(10)<<price*bquantity<<endl;
            tfile>>searchCode;
        }
        cout<<"\t\t\t***************************************************************"<<endl;
        cout<<"\t\t\t"<<setw(50)<<"Total"<<setw(10)<<total<<endl;
        cout<<endl<<"Press anykey to continue"<<endl;ch=getch();
        tfile.close();
    }
    void setTNo(int a)
    {
        trnum=a;
    }

};

void mainMenu()
{
    int input;
    cout<<endl<<"\t\t\t\t\t-----------------------------------"<<endl;
    cout<<"\t\t\t\t"<<setw(8)<<"|"<<setw(6)<<"1"<<setw(6)<<"|"<<setw(20)<<"Customer"<<setw(4)<<"|"<<endl;
    cout<<"\t\t\t\t\t-----------------------------------"<<endl;
    cout<<"\t\t\t\t"<<setw(8)<<"|"<<setw(6)<<"2"<<setw(6)<<"|"<<setw(20)<<"Stock"<<setw(4)<<"|"<<endl;
    cout<<"\t\t\t\t\t-----------------------------------"<<endl;
    cout<<"\t\t\t\t"<<setw(8)<<"|"<<setw(6)<<"3"<<setw(6)<<"|"<<setw(20)<<"Transactions"<<setw(4)<<"|"<<endl;
    cout<<"\t\t\t\t\t-----------------------------------"<<endl;
    cout<<"\t\t\t\t"<<setw(8)<<"|"<<setw(6)<<"4"<<setw(6)<<"|"<<setw(20)<<"Exit"<<setw(4)<<"|"<<endl;
    cout<<"\t\t\t\t\t-----------------------------------"<<endl;
    cout<<"\t\t\t\t"<<setw(8)<<"|"<<setw(23)<<"Enter value (1-4): "<<setw(13)<<"|"<<endl;
    cout<<"\t\t\t\t\t-----------------------------------"<<endl;
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD pos = {63, 17};SetConsoleCursorPosition(hConsole, pos);
    cin>>input;
    system("cls");
    customer newcus;
    stock newstock;
    transaction newttrans;
    if (input==1)
    {
        cout<<endl<<"\t\t\t\t\t-----------------------------------"<<endl;
        cout<<"\t\t\t\t"<<setw(8)<<"|"<<setw(6)<<"1"<<setw(6)<<"|"<<setw(16)<<"New Customer"<<setw(8)<<"|"<<endl;
        cout<<"\t\t\t\t\t-----------------------------------"<<endl;
        cout<<"\t\t\t\t"<<setw(8)<<"|"<<setw(6)<<"2"<<setw(6)<<"|"<<setw(16)<<"Search Customer"<<setw(8)<<"|"<<endl;
        cout<<"\t\t\t\t\t-----------------------------------"<<endl;
        cout<<"\t\t\t\t"<<setw(8)<<"|"<<setw(33)<<"Any Other Character to Go Back"<<setw(3)<<"|"<<endl;
        cout<<"\t\t\t\t\t-----------------------------------"<<endl;
        cout<<"\t\t\t\t"<<setw(8)<<"|"<<setw(23)<<"Enter value (1/2): "<<setw(13)<<"|"<<endl;
        cout<<"\t\t\t\t\t-----------------------------------"<<endl;
        newcus.listCustomer();
        HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
        COORD pos = {63,8};SetConsoleCursorPosition(hConsole, pos);
        cin>>input;
        pos = {0, 2};SetConsoleCursorPosition(hConsole, pos);
        if (input==1)
            newcus.newCustomer();
        else if (input==2)
            newcus.displayCustomer();
    }
    else if (input==2)
    {
        cout<<endl<<"\t\t\t\t\t-----------------------------------"<<endl;
        cout<<"\t\t\t\t"<<setw(8)<<"|"<<setw(6)<<"1"<<setw(6)<<"|"<<setw(16)<<"Edit Stock"<<setw(8)<<"|"<<endl;
        cout<<"\t\t\t\t\t-----------------------------------"<<endl;
        cout<<"\t\t\t\t"<<setw(8)<<"|"<<setw(6)<<"2"<<setw(6)<<"|"<<setw(16)<<"Add Stock"<<setw(8)<<"|"<<endl;
        cout<<"\t\t\t\t\t-----------------------------------"<<endl;
        cout<<"\t\t\t\t"<<setw(8)<<"|"<<setw(6)<<"3"<<setw(6)<<"|"<<setw(16)<<"Search Stock"<<setw(8)<<"|"<<endl;
        cout<<"\t\t\t\t\t-----------------------------------"<<endl;
        cout<<"\t\t\t\t"<<setw(8)<<"|"<<setw(33)<<"Any Other Character to Go Back"<<setw(3)<<"|"<<endl;
        cout<<"\t\t\t\t\t-----------------------------------"<<endl;
        cout<<"\t\t\t\t"<<setw(8)<<"|"<<setw(23)<<"Enter value (1-3): "<<setw(13)<<"|"<<endl;
        cout<<"\t\t\t\t\t-----------------------------------"<<endl;
        newstock.listStock();
        HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
        COORD pos = {63,10};SetConsoleCursorPosition(hConsole, pos);
        cin>>input;
        pos = {0, 2};SetConsoleCursorPosition(hConsole, pos);
        if (input==1)
        {
            newstock.editStock();
        }
        else if (input==2)
        {
            newstock.addNewStock();
        }
        else if (input==3)
        {
            system("cls");
            newstock.displayStock();
        }
        input=0;
    }
    else if (input==3)
    {
        cout<<endl<<"\t\t\t\t\t-----------------------------------"<<endl;
        cout<<"\t\t\t\t"<<setw(8)<<"|"<<setw(6)<<"1"<<setw(6)<<"|"<<setw(20)<<"New Transaction"<<setw(4)<<"|"<<endl;
        cout<<"\t\t\t\t\t-----------------------------------"<<endl;
        cout<<"\t\t\t\t"<<setw(8)<<"|"<<setw(6)<<"2"<<setw(6)<<"|"<<setw(20)<<"View Past Transactions"<<setw(2)<<"|"<<endl;
        cout<<"\t\t\t\t\t-----------------------------------"<<endl;
        cout<<"\t\t\t\t"<<setw(8)<<"|"<<setw(23)<<"Enter value (1/2): "<<setw(13)<<"|"<<endl;
        cout<<"\t\t\t\t\t-----------------------------------"<<endl;
        HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
        COORD pos = {63,6};SetConsoleCursorPosition(hConsole, pos);
        cin>>input;
        if (input==1)
        {
            newttrans.newTransaction();
        }
        else if (input==2)
        {
            cout<<"Enter Transaction Number: ";
            cin>>input;
            newttrans.setTNo(input);
            newttrans.searchTransaction();
        }
    }
    else if (input==4)
    {
        cout<<"Have a nice day"<<endl;
        lgch=0;
    }
}


int main()
{
    login login;
    login.lIn();
    Sleep(1000);
    while (login.check()==1)
    {
        system("cls");system("color 0F");
        cout<<endl<<endl<<endl<<endl<<"\t\t\t\t**************************************************"<<endl;
        cout<<setw(55)<<"Hey "<<login.getUser()<<endl;
        cout<<"\t\t\t\t**************************************************"<<endl;
        mainMenu();
        if (lgch==0)
            login.signOut();
    }
    return 0;
}
