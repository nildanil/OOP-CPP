
 /*ООП шпаргалка */
#include <iostream>//Libraries
#include <vector>

using namespace std;

class Student{ //declaration of our Class
private://private fields
    int _res[100];// static array of grades of students
    int _size;// size of list of grades
    int _age; // age of student
    string _judge; // judgment of student(why not, we can do everything)
    string _cool;// being awesome(How cool is this Student?)
    string _name;// and name of course...
public:// public space
    vector<Student>ListOfBest = {};// vector of the best Students(here contain all of private fields)
    vector<Student>ListOfGood = {};
    vector<Student>ListOfOthers = {};
    Student(){
    }
    friend istream& operator >> (istream& is, Student& s){// overload  of cin>>

        is >> s._name >> s._age >> s._judge >>s._cool>> s._size;
        for(int i = 0; i < s._size; i++){

            is >> s._res[i];
        }
        return is;
    }
    friend ostream& operator <<(ostream& os, Student& s){// overload of cout <<
        os << s._name << " | "<< s._age<<" y.o. | " << s._judge<< " | " << s._cool<< " |  ";
        return os;
    }
    bool isJudged(){//boolean method, that checks the judgement of student
      return _judge == "judged" || "Judged" ? true : false;
    }
    void checkResults(Student& s){ // this method checks grades of students and distribute students to the list of university
        int sum = 0;
        for(int i = 0; i < s._size; i++){
            sum += s._res[i];
        }
       int mid = sum / s._size;
        if(mid > 4){
            cout << "Great Job! " << mid << endl;
            ListOfBest.push_back(s);
        }
        else if(mid > 3 && mid <= 4){
            cout << "Well Done " << mid << endl;
            ListOfGood.push_back(s);
        }
        else {
            cout << "Not bad at all... "<< mid<< endl;
            ListOfOthers.push_back(s);
        }
    }

    void showLists(){// method, that shows all lists
        cout <<"Best: ";
        for(int i = 0; i < ListOfBest.size(); i++)
        {
            cout << ListOfBest[i] << " | ";
        }
        cout << endl<< "Good: ";
        for(int i = 0; i < ListOfGood.size(); i++)
        {
            cout << ListOfGood[i] << " | ";
        }
        cout << endl<< "Others: ";
        for(int i = 0; i < ListOfOthers.size();i++)
        {
            cout << ListOfOthers[i]<<" | ";
        }
    }
    bool isCool(){// method, that checks the "coolness" of the student
        return _cool == "cool" ;
    };



int main() {// main function

    string name;
    cout <<"Enter Students name, age, judgement, coolness and number of grades " <<endl;
    Student student;// we create object student of class Student
    cin >> student; // enter our object(overloaded operator)
    student.checkResults(student);//call method checkResults
    student.showLists();//output of all lists
    return 0;
    }

