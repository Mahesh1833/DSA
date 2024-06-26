#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

class Student {
private:
    struct Record {
        int roll;
        char name[10];
        char div;
        char add[10];
    };

    Record rec;

public:
    void create();
    void display();
    int search();
    void Delete();
};

void Student::create() {
    char ans;
    ofstream fout;
    fout.open("student.txt", ios::out | ios::binary);

    do {
        cout << "\n\tEnter Roll No of Student    : ";
        cin >> rec.roll;
        cout << "\n\tEnter a Name of Student     : ";
        cin >> rec.name;
        cout << "\n\tEnter a Division of Student : ";
        cin >> rec.div;
        cout << "\n\tEnter a Address of Student  : ";
        cin >> rec.add;

        fout.write((char *)&rec, sizeof(Record)) << flush;

        cout << "\n\tDo You Want to Add More Records: ";
        cin >> ans;
    } while (ans == 'y' || ans == 'Y');

    fout.close();
}

void Student::display() {
    ifstream fin;
    fin.open("student.txt", ios::in | ios::binary);

    cout << "\n\tThe Content of File are:\n";
    cout << "\n\tRoll\tName\tDiv\tAddress";

    while (fin.read((char *)&rec, sizeof(Record))) {
        if (rec.roll != -1)
            cout << "\n\t" << rec.roll << "\t" << rec.name << "\t" << rec.div << "\t" << rec.add;
    }

    fin.close();
}

int Student::search() {
    int r, i = 0;
    ifstream fin;
    fin.open("student.txt", ios::in | ios::binary);

    cout << "\n\tEnter a Roll No: ";
    cin >> r;

    while (fin.read((char *)&rec, sizeof(Record))) {
        if (rec.roll == r) {
            cout << "\n\tRecord Found...\n";
            cout << "\n\tRoll\tName\tDiv\tAddress";
            cout << "\n\t" << rec.roll << "\t" << rec.name << "\t" << rec.div << "\t" << rec.add;
            return i;
        }
        i++;
    }

    fin.close();
    return 0;
}

void Student::Delete() {
    int pos;
    pos = search();

    fstream f;
    f.open("student.txt", ios::in | ios::out | ios::binary);

    f.seekg(0, ios::beg);

    if (pos == 0) {
        cout << "\n\tRecord Not Found";
        return;
    }

    int offset = pos * sizeof(Record);
    f.seekp(offset);

    rec.roll = -1;
    strcpy(rec.name, "NULL");
    rec.div = 'N';
    strcpy(rec.add, "NULL");

    f.write((char *)&rec, sizeof(Record));
    f.seekg(0);
    f.close();

    cout << "\n\tRecord Deleted";
}

int main() {
    Student obj;
    int ch, key;
    char ans;

    do {
        cout << "\n\t***** Student Information *****";
        cout << "\n\t1. Create\n\t2. Display\n\t3. Delete\n\t4. Search\n\t5. Exit";
        cout << "\n\t..... Enter Your Choice: ";
        cin >> ch;

        switch (ch) {
            case 1:
                obj.create();
                break;
            case 2:
                obj.display();
                break;
            case 3:
                obj.Delete();
                break;
            case 4:
                key = obj.search();
                if (key == 0)
                    cout << "\n\tRecord Not Found...\n";
                break;
            case 5:
                break;
        }

        cout << "\n\t..... Do You Want to Continue in Main Menu: ";
        cin >> ans;
    } while (ans == 'y' || ans == 'Y');

    return 0;
}
