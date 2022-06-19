#include <iostream>
#include "Student.h"
#include "LinkedList.h"
#include <fstream>
#include <stdexcept>

using namespace std;

int main() {
    LinkedList<Student> List;

    ofstream studenci;
    studenci.open("STUDENCI.txt", ios::trunc);

    string to_open[2] = {"GRA.txt", "SID.txt" };
    for (auto & i : to_open) {
        ifstream opened_text(i);
        if ( !opened_text ) {
            throw runtime_error("No such file");
        }

        while ( !opened_text.eof() ) {
            string surname_str;
            string names_str;
            string index_str;
            string grade_str;
            string whole_line;

            getline(opened_text, whole_line);

            cout << whole_line << endl;

            int j = 0;
            for ( ; whole_line[j] != ' '; ++j ) {
                surname_str += whole_line[j];
            }
            cout << surname_str << endl;

            int k = j + 1;
            for ( ; !isdigit(whole_line[k]); ++k) {
                names_str += whole_line[k];
            }
            cout << names_str << endl;

            int l = k;
            for ( ; isdigit(whole_line[l]); ++l) {
                index_str += whole_line[l];
            }
            cout << index_str << endl;

            for ( int m = l + 1; m < l + 4; ++m ) {
                grade_str += whole_line[m];
            }
            cout << grade_str << endl;

            Student current_student;
            try {
                current_student.setStudentSurname(surname_str);
                current_student.setStudentName(names_str);
                current_student.setStudentIndex(index_str);
                current_student.setStudentGrade(stof(grade_str));
            }
            catch (exception &exc) {
                cout << exc.what() << endl;
            }
            List.push(current_student);
            cout << "before " << List.counter << endl;
        }
        opened_text.close();
    }

    while ( List.counter != 0 ) {
        Student to_save = List.pop();
        cout << "after " << List.counter << endl;
        studenci
        << to_save.getStudentIndex()<< ";"
        << to_save.getStudentGrade() << ";"
        << to_save.getStudentSurname() << ";"
        << to_save.getInitials() << endl;
    }

    return 0;
}
