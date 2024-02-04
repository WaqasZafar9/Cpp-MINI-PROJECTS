#include<iostream>
#include<regex>
#include<iomanip>
#include<conio.h>
#include<windows.h>
#include<fstream>
#include<chrono>
#include<string>
using namespace std;
class dnode
{
public:
    string number;
    string gmail;
    string name;
    dnode* prev, * next;
    dnode(string n,string r,string g)
    {
        name = n;
        number = r;
        gmail = g;
        next = NULL;
        prev = NULL;
    }
    friend class dlist;
};



class dlist
{
    dnode* head;

public:
    dnode* prevn;
    dlist()
    {
        head = NULL;

    }

    void accept()
    {
        
        system("color 0e");
        system("cls");
        string number;
        string gmail;
        string name;
        char ans;
        do
        {
            cout << "\n\t\t--------------<  WELCOME  >--------------\n";
            cout << "\n\t\t-----< PLEASE ENTER CONTACT DETAILS >-----\n";
            cout << "\n\t\tENTER NAME      :";
            cin.ignore();
            getline(cin, name);
            cout << "\n\t\tENTER NUMBER    :";
            cin >> number;
            ///Number lenght Check

            while (number.length() != 10)
            {
                cout << "\n\t\tENTER VALID NUMBER  :";
                cin >> number;
            }
            while (true) {

            cout << "\n\t\tENTER G-MAIL    :";
            cin >> gmail;
            regex pattern("(\\w+)(\\.|_)?(\\w*)@gmail\\.com");

            if (regex_match(gmail, pattern)) {
              //   "The email is a valid Gmail address." ;
                    
                break;
            }
            else {
                cout << "The email is not a valid Gmail address." << endl;
            }
            }
           
            auto start = chrono::high_resolution_clock::now();
            dnode* temp = new dnode(name, number, gmail);
            /////For First Node
            if (head == NULL)
            {
                head = temp;
            }
            else
            {
                
                head->prev = temp;
                temp->next = head;
                temp->prev = NULL;
                head = temp;
                auto end = chrono::high_resolution_clock::now();
                chrono::duration<double> elapsed_seconds = end - start;
                cout << "\n\nExecution time: " << elapsed_seconds.count() << "s\n";
            }
            cout << "\n\t\tDo You want To add More data? (Y/N)  : ";
            cin >> ans;

            if (ans == 'n' || ans == 'N') {

                cout << "\n\t\tGoing Back To Main Menu " << endl;
                Sleep(1000);
                menu();
            }
            system("cls");
        } while (ans == 'y');

    }


    
    //////////////// 



    dnode* merge_number(dnode* left, dnode* right) {
        if (left == NULL) {
            return right;
        }
        if (right == NULL) {
            return left;
        }
        dnode* ans = new dnode("","","");
        dnode* temp = ans;

        while (left != NULL && right != NULL) {
            if (left->number < right->number) {
                temp->next = left;
                left->prev = temp;
                temp = left;
                left = left->next;
            }
            else {
                temp->next = right;
                right->prev = temp;
                temp = right;
                right = right->next;
            }
        }
        while (left != NULL) {
            temp->next = left;
            left->prev = temp;
            temp = left;
            left = left->next;
        }
        while (right != NULL) {
            temp->next = right;
            right->prev = temp;
            temp = right;
            right = right->next;
        }
        ans = ans->next;
        ans->prev = NULL;
        return ans;
    }

    dnode* merge_name(dnode* left, dnode* right) {
        if (left == NULL) {
            return right;
        }
        if (right == NULL) {
            return left;
        }
        dnode* ans = new dnode("","","");
        dnode* temp = ans;

        while (left != NULL && right != NULL) {
            if (left->name < right->name) {
                temp->next = left;
                left->prev = temp;
                temp = left;
                left = left->next;
            }
            else {
                temp->next = right;
                right->prev = temp;
                temp = right;
                right = right->next;
            }
        }
        while (left != NULL) {
            temp->next = left;
            left->prev = temp;
            temp = left;
            left = left->next;
        }
        while (right != NULL) {
            temp->next = right;
            right->prev = temp;
            temp = right;
            right = right->next;
        }
        ans = ans->next;
        ans->prev = NULL;
        return ans;
    }

    dnode* merge_gmail(dnode* left, dnode* right) {
        if (left == NULL) {
            return right;
        }
        if (right == NULL) {
            return left;
        }
        dnode* ans = new dnode("", "", "");
        dnode* temp = ans;

        while (left != NULL && right != NULL) {
            if (left->gmail < right->gmail) {
                temp->next = left;
                left->prev = temp;
                temp = left;
                left = left->next;
            }
            else {
                temp->next = right;
                right->prev = temp;
                temp = right;
                right = right->next;
            }
        }
        while (left != NULL) {
            temp->next = left;
            left->prev = temp;
            temp = left;
            left = left->next;
        }
        while (right != NULL) {
            temp->next = right;
            right->prev = temp;
            temp = right;
            right = right->next;
        }
        ans = ans->next;
        ans->prev = NULL;
        return ans;
    }


    dnode* find_middle(dnode* head) {
        dnode* slow = head;
        dnode* fast = head->next;
        while (fast != NULL && fast->next != NULL) {
            fast = fast->next->next;
            slow = slow->next;
        }
        return slow;
    }


    dnode* merge_sort(dnode* head,int choice) {
        if (head == NULL || head->next == NULL) {
            return head;
        }
        dnode* mid = find_middle(head);
        dnode* left = head;
        dnode* right = mid->next;
        mid->next = NULL;
        right->prev = NULL;
        left = merge_sort(left,choice);
        right = merge_sort(right,choice);
        dnode* result=NULL;
        if (choice==1) {
            result = merge_number(left, right);
        }
        else if (choice == 2) {
            result = merge_name(left, right);
        }
        else if (choice == 3) {
            result = merge_gmail(left, right);
        }
        return result;
    }






    ////////////////


    void pause() {
        cout << "\n\nPress any key to Continue " << endl;
        char c;
        cin >> c;
    }
    void searchbyname()
    {
        // code to measure
        cout << "\n\n\n\t\t\t-----------< WELCOME TO SEARCH MENU >----------\n";

        if (head == NULL) {
            cout << "YOUR CONTACT BOOK IS EMPTY\n\n";
            pause();
            return;
        }
        string na;
        cout << "Enter your Name : ";
        cin >> na;
        auto start = chrono::high_resolution_clock::now();
        dnode* ptr = head;
        while (ptr != NULL)
        {
            if (na== ptr->name) 
            {
                cout << "NAME FOUND" << endl;
                cout << "CONTACT DETAILS ARE BELOW:\n" << endl;
                cout << "\n\nNAME  ::\t" << ptr->name;
                cout << "\nNUMBER::\t+92-" << ptr->number;
                cout << "\nG-MAIL::\t" << ptr->gmail;
        auto end = chrono::high_resolution_clock::now();
        chrono::duration<double> elapsed_seconds = end - start;
        cout << "\n\nExecution time: " << elapsed_seconds.count() << "s\n";
                pause();
                return;
            }
            ptr = ptr->next;
        }
        auto end = chrono::high_resolution_clock::now();
        chrono::duration<double> elapsed_seconds = end - start;
        cout << "\n\nExecution time: " << elapsed_seconds.count() << "s\n";

         cout << "NAME NOT FOUND" << endl;
         pause();
    }
    void searchbynumber()

    {
        cout << "\n\n\n\t\t\t-----------< WELCOME TO SEARCH MENU >----------\n";

        if (head == NULL) {
            cout << "YOUR CONTACT BOOK IS EMPTY\n\n";
            pause();
            return;
        }
        string num;
        cout << "Enter your Number : ";
        cin >> num;
        auto start = chrono::high_resolution_clock::now();
        dnode* ptr = head;
        while (ptr != NULL)
        {
            if (num == ptr->number)
            {
                cout << "NUMBER FOUND\n" << endl;
                cout << "CONTACT DETAILS ARE BELOW:\n" << endl;
                cout << "\n\nNAME  ::\t" << ptr->name;
                cout << "\nNUMBER::\t+92-" << ptr->number;
                cout << "\nG-MAIL::\t" << ptr->gmail;
        auto end = chrono::high_resolution_clock::now();
        chrono::duration<double> elapsed_seconds = end - start;
        cout << "\n\nExecution time: " << elapsed_seconds.count() << "s\n";

                pause();
                return;

            }
            ptr = ptr->next;
        }

        cout << "NUMBER NOT FOUND\n" << endl;


        auto end = chrono::high_resolution_clock::now();
        chrono::duration<double> elapsed_seconds = end - start;
        cout << "\n\nExecution time: " << elapsed_seconds.count() << "s\n";


        pause();
    }
    void searchbygmail()
    {
        cout << "\n\n\n\t\t\t-----------< WELCOME TO SEARCH MENU >----------\n";


        if (head == NULL) {
            cout << "YOUR CONTACT BOOK IS EMPTY\n\n";
            pause();
            return;
        }
        string gm;
        cout << "Enter your Gmail : ";
        cin >> gm;
        auto start = chrono::high_resolution_clock::now();
        dnode* ptr = head;
        while (ptr != NULL)
        {
            if (gm == ptr->gmail)
            {
                cout << "G-MAIL FOUND\n" << endl;
                cout << "CONTACT DETAILS ARE BELOW:\n" << endl;
                cout << "\n\nNAME  ::\t" << ptr->name;
                cout << "\nNUMBER::\t+92-" << ptr->number;
                cout << "\nG-MAIL::\t" << ptr->gmail;
        auto end = chrono::high_resolution_clock::now();
        chrono::duration<double> elapsed_seconds = end - start;
        cout << "\n\nExecution time: " << elapsed_seconds.count() << "s\n";
                pause();
                return;
            }
            ptr = ptr->next;
        }
        cout << "G-MAIL NOT FOUND\n" << endl;

        auto end = chrono::high_resolution_clock::now();
        chrono::duration<double> elapsed_seconds = end - start;
        cout << "\n\nExecution time: " << elapsed_seconds.count() << "s\n";

        pause();
    }

   
    void display()
    {
        system("color 5e");
        cout << "\n\n\n\t\t\t-----------< WELCOME TO DISPLAY MENU >----------\n";
        if (head == NULL) {
            cout << "\n\n\t\t\tYOUR CONTACT BOOK IS EMPTY\n\n";
            pause();
            return;
        }
        int choice = 0;
        cout << "\n\t\t\tIN WHICH WAY YOU WANT TO DISLAY:?\n\t\t\t1.SORT BY PHONE NUMBER\n\t\t\t2.SORT BY NAME\n\t\t\t3.SORT BY G-MAIL\n";
        cout << " \t\t\t ENTER THE CHOICE: ";
        cin >> choice;
        if (choice != 1 && choice != 2 && choice != 3) {
            cout << "Invalid Input " << endl;
            display();
        }
        auto start = chrono::high_resolution_clock::now();
        head = merge_sort(head, choice);
        //   head = merge_sort(head);
        dnode* ptr = head;//start the node
        while (ptr != NULL)//traverse till last
        {

            cout << "\n\n\tNAME  ::\t" << ptr->name;
            cout << "\n\tNUMBER::\t+92-" << ptr->number;
            cout << "\n\tG-MAIL::\t" << ptr->gmail;
            ptr = ptr->next;
        }
        // code to measure
        auto end = chrono::high_resolution_clock::now();
        chrono::duration<double> elapsed_seconds = end - start;
        cout << "\n\nExecution time: " << elapsed_seconds.count() << "s\n";
        pause();
    }


    void update()
    {


        system("color f0");
        cout << "\n\n\n\t\t\t-----------< WELCOME TO UPDATE MENU >----------\n";

        if (head == NULL) {
            cout << "\n\n\n\t\t\tYOUR CONTACT BOOK IS EMPTY\n\n";
            pause();
            return;
        }
        auto start = chrono::high_resolution_clock::now();
        string gm;
        cout << "Enter Name You want to Update : ";
        cin >> gm;
        char ans;
        int c;
        dnode* ptr = head;
        while (ptr != NULL)
        {
            if (gm==ptr->name) 
            {

                do
                {
                    cout << "\nWHAT DO YOU WANT TO UPDATE?\n1.NAME\n2.PHONE NUMBER\n3.G-MAIL\n";
                    cin >> c;
                    switch (c)
                    {
                    case 1:
                        cout << "ENTER NEW-NAME=";
                        cin >> ptr->name;
                        break;
                    case 2:
                        cout << "ENTER NEW PHONE-NUMBER?";
                        cin >> ptr->number;
                        while (ptr->number.size() != 10)
                        {
                            cout << "ENTER VALID NUMBER  :";
                            cin >> ptr->number;
                        }
                        break;
                    case 3:
                        cout << "ENTER NEW G-MAIL";
                        cin >> ptr->gmail;
                        break;
                    }
                    cout << "DO YOU WANT TO CONTINUE UPDATING?";
                    cin >> ans;
                    if (ans == 'n' || ans == 'N') {
                        cout << "\n\t\tGoing Back To Main Menu " << endl;
                         auto end = chrono::high_resolution_clock::now();
                         chrono::duration<double> elapsed_seconds = end - start;
                         cout << "\n\nExecution time: " << elapsed_seconds.count() << "s\n";
                        Sleep(1000);
                        menu();
                    }
                } while (ans == 'y');
            }
            ptr = ptr->next;
        }
        cout << "YOUR NAME IS NOT in the LIST"<<endl;
        pause();
    }




    void deletecontactbynumber()
    {


        cout << "\n\n\n\t\t\t-----------< WELCOME TO DELETE MENU >----------\n";
        if (head == NULL) {

            cout << "\n\n\n\t\t\tYOUR CONTACT BOOK IS EMPTY\n\n";
            pause();
            return;
        }
        string s;
        cout << "\n\n\t\t\tEnter Number to Delete : ";
        cin >> s;
        auto start = chrono::high_resolution_clock::now();
        int c = 0;
        dnode* ptr = head;
        while (ptr != NULL)
        {
            if (s == ptr->number)
            {
                c = 1;
                break;
            }
            else
            {
                c = 2;
            }
            ptr = ptr->next;
        }
        /////Found and only one contact is saved
        if (c == 1 && head->next == NULL) {
            cout << "\n\t\tYOUR CONTACT IS SUCCESSFULLY DELETED\n\n";
            head = NULL;
        auto end = chrono::high_resolution_clock::now();
        chrono::duration<double> elapsed_seconds = end - start;
        cout << "\n\nExecution time: " << elapsed_seconds.count() << "s\n";
            pause();
            return;
        }

        /////Found and present in middle of list
        if (c == 1 && ptr != head && ptr->next != NULL)
        {
            ptr->prev->next = ptr->next;
            ptr->next->prev = ptr->prev;
            delete(ptr);
            cout << "\n\t\tYOUR CONTACT IS SUCCESSFULLY DELETED\n\n";
            auto end = chrono::high_resolution_clock::now();
            chrono::duration<double> elapsed_seconds = end - start;
            cout << "\n\nExecution time: " << elapsed_seconds.count() << "s\n";
            pause();
            return;
        }

        /////Found and present at number first of list
        if (c == 1 && ptr == head && ptr->next != NULL)
        {
            head = head->next;
            head->prev = NULL;
            delete(ptr);
            cout << "\n\t\tYOUR CONTACT IS SUCCESSFULLY DELETED\n\n";
            auto end = chrono::high_resolution_clock::now();
            chrono::duration<double> elapsed_seconds = end - start;
            cout << "\n\nExecution time: " << elapsed_seconds.count() << "s\n";
            pause();
            return;
        }
        /////Found and present at end of list
        if (c == 1 && ptr->next == NULL)
        {
            ptr->prev->next = NULL;
            ptr->prev = NULL;
            delete(ptr);
            cout << "\n\t\tYOUR CONTACT IS SUCCESSFULLY DElETED\n\n";
            auto end = chrono::high_resolution_clock::now();
            chrono::duration<double> elapsed_seconds = end - start;
            cout << "\n\nExecution time: " << elapsed_seconds.count() << "s\n";
            pause();
            return;
        }
        /////Not Found
        if (c == 2)
        {
            cout << "\n\t\tYOUR ENTERED NAME IS NOT IN THE LIST...";
            auto end = chrono::high_resolution_clock::now();
            chrono::duration<double> elapsed_seconds = end - start;
            cout << "\n\nExecution time: " << elapsed_seconds.count() << "s\n";
            pause();
        }
    }




    void deletecontact()
    {
        cout << "\n\n\n\t\t\t-----------< WELCOME TO DELETE MENU >----------\n";

        if (head==NULL) {
            cout << "\n\n\t\t\tYOUR CONTACT BOOK IS EMPTY\n\n";
            pause();
            return;
        }
        string s;
        cout << "Enter Name to Delete : ";
        cin >> s;
        auto start = chrono::high_resolution_clock::now();
        int c = 0;
        dnode* ptr = head;
        while (ptr != NULL)
        {
            if (s== ptr->name)
            {
                c = 1;
                break;
            }
            else
            {
                c = 2;
            }
            ptr = ptr->next;
        }
        /////Found and only one contact is saved
        if (c == 1 && head->next==NULL) {
            cout << "YOUR CONTACT IS SUCCESSFULLY DELETEd\n\n";
            head = NULL;
            auto end = chrono::high_resolution_clock::now();
            chrono::duration<double> elapsed_seconds = end - start;
            cout << "\n\nExecution time: " << elapsed_seconds.count() << "s\n";
            pause();
            return;
        }

        /////Found and present in middle of list
        if (c == 1 && ptr != head && ptr->next != NULL)
        {
            ptr->prev->next = ptr->next;
            ptr->next->prev = ptr->prev;
            delete(ptr);
            cout << "YOUR CONTACT IS SUCCESSFULLY DELETeD\n\n";
            auto end = chrono::high_resolution_clock::now();
            chrono::duration<double> elapsed_seconds = end - start;
            cout << "\n\nExecution time: " << elapsed_seconds.count() << "s\n";
            pause();
            return;
        }

        /////Found and present at number first of list
        if (c == 1 && ptr == head&&ptr->next!=NULL)
        {
            head = head->next;
            head->prev = NULL;
            delete(ptr);
            cout << "YOUR CONTACT IS SUCCESSFULLY DELEtED\n\n";
            auto end = chrono::high_resolution_clock::now();
            chrono::duration<double> elapsed_seconds = end - start;
            cout << "\n\nExecution time: " << elapsed_seconds.count() << "s\n";
            pause();
            return;
        }
        /////Found and present at end of list
        if (c == 1 &&ptr->next == NULL)
        {
            ptr->prev->next = NULL;
            ptr->prev = NULL;
            delete(ptr);
            cout << "YOUR CONTACT IS SUCCESSFULLY DElETED\n\n";
            auto end = chrono::high_resolution_clock::now();
            chrono::duration<double> elapsed_seconds = end - start;
            cout << "\n\nExecution time: " << elapsed_seconds.count() << "s\n";
            pause();
            return;
        }
        /////Not Found
        if (c == 2)
        {
            cout << "YOUR ENTERED NAME IS NOT IN THE LIST...";
            auto end = chrono::high_resolution_clock::now();
            chrono::duration<double> elapsed_seconds = end - start;
            cout << "\n\nExecution time: " << elapsed_seconds.count() << "s\n";
            pause();
        }
    }

    void OflineSave()
    {
        dnode* temp = head;
        ofstream myfile("contactbook.txt");
        if (myfile.is_open())
        {
            while (temp != NULL)
            {
                myfile << endl<<temp->name << endl;
                myfile << temp->number << endl;
                myfile << temp->gmail;
                temp = temp->next;
            }
            myfile.close();
        }
        
    }

    void insert_save_data() {
        dnode* temp = head;
        ifstream read;
        read.open("contactbook.txt",ios::in);
       
        if (read.is_open()) {
            string n, no, m;
            string l;
            getline(read, l);
            while (!read.eof()) {
                getline(read, n);
                getline(read, no);
                getline(read, m);
                if (head == NULL)
                {
                    dnode* newer = new dnode(n, no, m);

                    newer->next = NULL;
                    newer->prev == NULL;
                    head = newer;
                    temp = head;
                }
                else {
                    dnode* newer = new dnode(n,no,m);
                    temp->next = newer;
                    newer->prev = temp;
                    temp = temp->next;
                }
            }

        }
        read.close();
    }

    void see_contacts() {

        cout << "\n\n\n\t\t\t-----------< WELCOME TO CHECK MENU >----------\n";
        if (head == NULL) {
            cout << "YOUR CONTACT BOOK IS EMPTY\n\n";
            pause();
            return;
        }
        auto start = chrono::high_resolution_clock::now();
        dnode* ptr = head;
        ptr = find_middle(head);
        while (true) {
            char choice = 'l';
            cout << "\n\nEnter 'L' to move forward , 'R' to move Backward , 'E' for exit ";
            cin >> choice;
            if (choice == 'r') {
                if (ptr->next!=NULL) {
                    ptr = ptr->next;
                    cout << "Enter 'D' For Details of " << ptr->name<<endl;
                    cin >> choice;
                    if (choice=='d') {
            cout << "\n\n******Contact Details****** ";
                        cout << "\n\nNAME  ::\t" << ptr->name;
                        cout << "\nNUMBER::\t+92-" << ptr->number;
                        cout << "\nG-MAIL::\t" << ptr->gmail;
                    }
                }
                else {
                    cout << "END OF CONTACT BOOK"<<endl;

                }
            }
            else if (choice == 'l') {
                if (ptr->prev != NULL) {
                    ptr = ptr->prev;
                    cout << "\n\nEnter 'D' For Details of " << ptr->name << endl;
                    cin >> choice;
                    if (choice == 'd') {
                        cout << "\n\n******Contact Details****** ";
                        cout << "\n\nNAME  ::\t" << ptr->name;
                        cout << "\nNUMBER::\t+92-" << ptr->number;
                        cout << "\nG-MAIL::\t" << ptr->gmail;
                    }
                }
            else {
                cout << "BEGIN OF  CONTACT BOOK" << endl;
            }
            }
            else if (choice=='e') {
                auto end = chrono::high_resolution_clock::now();
                chrono::duration<double> elapsed_seconds = end - start;
                cout << "\n\nExecution time: " << elapsed_seconds.count() << "s\n";
                pause();
                break;
            }
            else  {
                cout << "INVALID CHOICE";
            }
        }


    }

    int check() {
        int choice;
        while (!(cin >> choice) )
        {
            cin.clear();
            while (cin.get() != '\n') continue;
            cout << " Wrong input !\n";
        }
        return choice;
    }
    void menu() {
        system("color 4f");
        int choice;

       
        while (true) {
            system("cls");
            /////Welcome Screen Of USER
            cout << "\n\n\t\t\t=====================================================" << endl;
            cout << "\t\t\t==========<  Welcome to Your Phone Book   >==========" << endl;
            cout << "\t\t\t=====================================================" << endl;
            cout << "\n\t\t\t\t| 1.Enter to Insert                 |" << endl;
            cout << "\n\t\t\t\t| 2.Enter to Display ALL Contacts   |" << endl;
            cout << "\n\t\t\t\t| 3.Enter to Search By Name         |" << endl;
            cout << "\n\t\t\t\t| 4.Enter to Search By Number       |" << endl;
            cout << "\n\t\t\t\t| 5.Enter to Search By Gmail        |" << endl;
            cout << "\n\t\t\t\t| 6.Enter to Update Contact         |" << endl;
            cout << "\n\t\t\t\t| 7.Enter to Delete By Name         |" << endl;
            cout << "\n\t\t\t\t| 8.Enter to Delete By Number       |" << endl;
            cout << "\n\t\t\t\t| 9.Enter to See Contact            |" << endl;
            cout << "\n\t\t\t\t| 10.To Exit                        |" << endl;
            cout << "\n\t\t\t=====================================================" << endl;
            cout << "\t\t\t=====================================================" << endl;




            cout << endl << endl << "Enter your choice : ";
            
            choice=check();

            switch (choice) {
            case 1:
                system("cls");
                accept();
                break;
            case 2:
                system("cls");
                display();
                break;
            case 3:
                system("cls");
                searchbyname();
                break;
            case 4:
                system("cls");
                searchbynumber();
                break;
            case 5:
                system("cls");
                searchbygmail();
                break;
            case 6:
                system("cls");
                update();
                break;
            case 7:
                system("cls");
                deletecontact();
                break;
            case 8:
                system("cls");
                deletecontactbynumber();
                break;
            case 9:
                system("cls");
                see_contacts();
                break;
            case 10:
                system("cls");
                OflineSave();
                exit(0);
            default:
                cout << "Invalid ";
                break;
            }
        }
    }
    void Welcome() {
        system("color 0e");

        system("cls");      /////clearing screen    

        cout << "\t\t\t\t---------------------------------------------" << endl;
        cout << "\t\t\t\t-------<  Welcome to Your Phone Book >-------" << endl;
        cout << "\t\t\t\t---------------------------------------------" << endl;
        string s= "\n\n\t\t\t\t\tFuzail   39091";
        string s1= "\n\n\t\t\t\t\tWAQAS   38605";
        for (int i = 0; i < s.size();i++) {
            cout << s[i];
            Sleep(20);
        }
        for (int i = 0; i < s1.size(); i++) {
            cout << s1[i];
            Sleep(20);
        }

        cout << "\n\n\n\n\n";
        cout << "\t\t\t Loading";

        char bar1 = 177;

        for (int i = 0; i < 40; i++)
            cout << bar1;

        cout << "\r";
        cout << "\t\t\t\t ";

        char y = 219;
        for (int a = 0; a < 40; a++) {
            cout << y;
            Sleep(40);

        }

        system("cls");
        menu();     /////Calling Menu function
    }

};


void main() {

    dlist s1;
    s1.insert_save_data();
    s1.Welcome();
   // s1.menu();
}
