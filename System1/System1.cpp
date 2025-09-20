#include <iostream>
#include <string>
using namespace std;
class Person {
protected:
    int id;
    string name;
    string password;
public:
    //============ Constructor ============
    Person(int id, const string& name,
        const string& password)
        : id(id), name(name), password(password) {
    }

    //============ Virtual destructor ============
    virtual ~Person() {}

    // ============ Setters ============
    virtual void setId(int newId) { id = newId; }
    virtual void setName(const string& newName) { name = newName; }
    virtual void setPassword(const string& pwd) { password = pwd; }

    // ============ Getters ============
    int getId() const { return id; }
    string getName() const { return name; }
    string getPassword() const { return password; }

    // ============ Virtual Display ============
    virtual void display() const {
        cout << "ID: " << id
            << " | Name: " << name;
    }
};
class Client  : public Person{
private:
    double balance;
public:
    //============ Constructor ============
    Client(int id , string name , string password, double balance) :
        Person (id , name , password) , balance(balance){ }
    // ============ Setters ============
    void setName(string name) {
        while (true) {
            if (name.size() < 3 || name.size() > 20) {
                cout << "Invlaid name! \n";
            }
            else {
                bool valid = true;
                for (int i = 0; i < name.size();i++) {
                    if (!isalpha(name[i])) {
                        cout << "Name must contain alphabetic chars! \n";
                        valid = false;
                        break;
                    }
                }
                if (valid) {
                    this -> name = name;
                    cout << "Valid name  \n";
                    break; 
                }
            }
            cout << "Please Enter again your name !";
            cin >> name;
        }
    }
    void setPassword(string password) {
        while (true) {
            if (password.size() < 8 || password.size() > 20) {
                cout << "Invalid password \n";
            }
            else {
                this->password = password;
                cout << "Valid Password.\n";
                break;
            }
            cout << " Enter password again : ";
            cin >> password;
        }
    }
    void setBalance(double balance) {
        while (true) {
            if (balance < 1500) {
                cout << "Your Balance Shoud Be over 1500 " << endl;
                cout << "Please try again " << endl;
                cin >> balance;
            }
            else {
                this->balance = balance;
                cout << "Valid Balance " << endl;
                break;
            }
        }
    }
    // ============ Getter ============
    double getBalance()  {
        return balance;
    }
    // ============ Methods ============
    void deposit(double amount) {
        balance += amount;
        cout << "Your balance now is :" << balance << endl;
    }
    void withdrow(double amount) {
        balance -= amount;
        cout << "Your balance now is :" << balance << endl;
    }
    void transferTo(double amount , Client & recipient) {
        balance -= amount;
        recipient.balance += amount;
        cout << "Transfer Done Succes" << endl;
    }
    void CheckBalance() {
        cout << balance << endl;
    }
    // ============ Display ============
    void display()  {
        cout << "=============================\n";
        cout << " Client Info \n";
        Person::display();
        cout << " Balance  : " << balance << endl;
        cout << "=============================\n";
    }
};

int main()
{
   
}
