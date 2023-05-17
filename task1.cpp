#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>
using namespace std;

class DB {
public:
    string* fio = new string;
    string* date = new string;
    string* pos = new string;
    string* gr = new string;

    DB(string fio, string date, string pos, string gr) {
        *this->fio = fio;
        *this->date = date;
        *this->pos = pos;
        *this->gr = gr;
    }

    void getIngener()
    {
        if (*this->pos == "инженер")
        {
            cout << "Name: " << *this->fio << " Age: " << *this->date << " Position: ";
            cout << *this->pos << " Group: " << *this->gr << endl;
        }
    }

    void getPred()
    {
        if (*this->pos != "председатель")
        {
            cout << "Name: " << *this->fio << " Age: " << *this->date << " Position: ";
            cout << *this->pos << " Group: " << *this->gr << endl;
        }
    }

    virtual ~DB() {
        delete fio, date, pos, gr;
    }
};
//предикат
bool cmp(DB* a, DB* b)
{
    if (*a->date < *b->date)
    {
        return true;
    }
    else
        return false;
}

void main()
{
    setlocale(LC_ALL, "rus");
    string line = "", fio = "", date = "", pos = "", gr = "";
    int count = 0, length = 0, a = 0;
    vector<DB*> box;
    ifstream in("C:/Users/Tasya/Desktop/text.txt"); 
    if (in.is_open())
    {
        while (getline(in, line))
        {
            for (int i = 0; i < line.length(); i++)
            {
                if (line[i] == ' ')//разделить данные
                    //записывать данные в объект, добавл€€ в вектор
                {
                    count++;//число разделителей 
                    switch (count)
                    {
                    case 2:
                        length = i;
                        fio = line.substr(0, length);
                        a = length + 1;
                        break;
                    case 3:
                        length = i;
                        date = line.substr(a, ((length - 1) - a));
                        a = length + 1;
                        break;
                    case 4:
                        length = i;
                        pos = line.substr(a, ((length - 1) - a));
                        a = length + 1;
                        break;
                    case 5:
                        length = i;
                        gr = line.substr(a, ((length + 3) - a));
                        a = length + 1;
                        break;
                    default:
                        break;
                    }
                }
            }
            count = 0;
            DB* obj = new DB(fio, date, pos, gr);
            box.push_back(obj);
        }
    }

    for (int i = 0; i < box.size(); i++)
    {
        box[i]->getIngener();
    }
    sort(box.begin(), box.end(), cmp);

    for (int i = 0; i < box.size(); i++)
    {
        box[i]->getPred();
    }
    for (int i = 0; i < box.size(); i++)
    {
        delete box[i];
    }
}