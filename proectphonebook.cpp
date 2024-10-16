
#include <iostream>
#include <vector>
#include <fstream>
using namespace std;


class Contact {
private:
    string PIB;     
    string homePhone;    
    string workPhone;
    string add;

public:
   
    Contact(const string& name, const string& home, const string& work,  const string& info)
        :PIB(name), homePhone(home), workPhone(work),  add(info) {}

   
    inline const string& getName()  {
        return PIB;
    }

    
    void showInfo() const {
        cout << "PIB: " << PIB << endl;
       cout << "Home phone: " << homePhone << endl;
        cout << "Work phonee: " << workPhone << endl;
      
        cout << "Add ifo :  " << add << endl;
    }

   
    void saveToFile(ofstream& file)  {
        file << PIB <<   homePhone << workPhone <<  add << endl;
    }

  
   
};

class PhoneBook {
private:
    vector<Contact*> contacts;

public:
   
    ~PhoneBook() {
        for (Contact* contact : contacts) {
            delete contact;
        }
    }

   
    void add(const string& name, const string& home, const string& work,  const string& info) {
        contacts.push_back(new Contact(name, home, work,  info));
    }

  

    void delete2(const std::string& name) {
        for (auto it = contacts.begin(); it != contacts.end(); ++it) {
            if ((*it)->getName() == name) {
                delete* it;
                contacts.erase(it);
                cout << "DElete." << endl;
                return;
            }
        }
        cout << "Not find" << endl;
    }

  
    void showAll()  {
        if (contacts.empty()) {
            cout << "Contac is nothing" << endl;
            return;
        }
        for (const Contact* contact : contacts) {
            contact->showInfo();
           
        }
    }

    
    

   

    
};

int main() {
    PhoneBook phoneBook;

    phoneBook.add("Ivan", "123-45-67", "765-43-21", "098-765-4321");
    phoneBook.add("Olexandr", "987-65-43", "345-67-89", "067-123-4567");

    
    cout << "All contacts" << endl;
    phoneBook.showAll();

    
    
      

    phoneBook.delete2("Olexandr");

    

}