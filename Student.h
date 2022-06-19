#ifndef STUDENTS_EXAM_STUDENT_H
#define STUDENTS_EXAM_STUDENT_H
#include <iostream>
#include <string>

using namespace std;

bool isDigits(string &str);
struct Student {

private:
    string student_name;
    string student_surname;
    string student_index;
    float student_grade;

public:

    Student() = default;
    ~Student() = default;

    bool checkIndex(string index);
    bool checkGrade(float grade);
    string getInitials();

    const string &getStudentName() const;
    void setStudentName(const string &studentName);

    const string &getStudentSurname() const;
    void setStudentSurname(const string &studentSurname);

    const string &getStudentIndex() const;
    void setStudentIndex(const string &studentIndex);

    float getStudentGrade() const;
    void setStudentGrade(float studentGrade);

    bool operator<(const Student &rhs) const;
    bool operator>=(const Student &rhs) const;


};

bool Student::checkIndex(string index) {
    return isDigits(index) && index.length() == 6;
}

bool Student::checkGrade(float grade) {
    return grade >= 2 && grade <= 5;
}

string Student::getInitials() {
    string initials;

    for ( int i = 0; i < student_name.length() - 1; ++i ) {
        if ( i == 0 ) {
            initials += student_name[i];
            initials += '.';
        }
        if ( student_name[i] == ' ') {
            initials += student_name[i + 1];
            initials += '.';
        }
    }

    return initials;
}

const string &Student::getStudentName() const {
    return student_name;
}

void Student::setStudentName(const string &studentName) {
    student_name = studentName;
}

const string &Student::getStudentSurname() const {
    return student_surname;
}

void Student::setStudentSurname(const string &studentSurname) {
    student_surname = studentSurname;
}

const string &Student::getStudentIndex() const {
    return student_index;
}

void Student::setStudentIndex(const string &studentIndex) {
    student_index = studentIndex;
}

float Student::getStudentGrade() const {
    return student_grade;
}

void Student::setStudentGrade(float studentGrade) {
    student_grade = studentGrade;
}

bool isDigits(string &str) {
    return all_of(str.begin(), str.end(), ::isdigit);
}

bool Student::operator<(const Student &rhs) const {
    return stoi(student_index) < stoi(rhs.student_index);
}

bool Student::operator>=(const Student &rhs) const {
    return stoi(student_index) >= stoi(rhs.student_index);
}

#endif
