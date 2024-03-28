#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <locale>
#include <algorithm>

using namespace std;

struct Student {
    string surname;
    int course;
    string specialty;
    double physics_grade;
    double math_grade;
    double programming_grade;
};

bool compareBySurname(const Student& a, const Student& b) {
    return a.surname < b.surname;
}

bool compareByCourseSpecialtySurname(const Student& a, const Student& b) {
    if (a.course != b.course)
        return a.course < b.course;
    if (a.specialty != b.specialty)
        return a.specialty < b.specialty;
    return a.surname > b.surname; // Сортування прізвища в зворотньому порядку
}

void inputStudentData(Student& student, int number) {
    cout << "Prizvyshche studenta " << number << ": ";
    cin >> student.surname;

    cout << "Kurs: ";
    cin >> student.course;

    cout << "Specialnist: ";
    cin.ignore();
    getline(cin, student.specialty);

    cout << "Otsinka z fizyky: ";
    cin >> student.physics_grade;
    cout << "Otsinka z matematyky: ";
    cin >> student.math_grade;
    cout << "Otsinka z prohramuvannya: ";
    cin >> student.programming_grade;
}

void inputStudentsData(vector<Student>& students, int number_of_students) {
    for (int i = 0; i < number_of_students; ++i) {
        Student new_student;
        inputStudentData(new_student, i + 1);
        students.push_back(new_student);
    }
}

void printStudentsTable(const vector<Student>& students) {
    cout << setw(5) << "№" << setw(15) << "Prizvyshche" << setw(7) << "Kurs" << setw(15) << "Spetsialnist"
        << setw(10) << "  Fizyka" << setw(10) << "    Matematyka" << setw(15) << "     Prohramuvannya" << endl;
    for (size_t i = 0; i < students.size(); ++i) {
        cout << setw(5) << i + 1 << setw(15) << students[i].surname << setw(7) << students[i].course
            << setw(15) << students[i].specialty << setw(10) << students[i].physics_grade
            << setw(10) << students[i].math_grade << setw(15) << students[i].programming_grade << endl;
    }
}

void sortStudents(vector<Student>& students) {
    sort(students.begin(), students.end(), compareByCourseSpecialtySurname);
}

void buildIndexArray(const vector<Student>& students, vector<int>& indexArray) {
    indexArray.resize(students.size());
    for (int i = 0; i < students.size(); ++i) {
        indexArray[i] = i;
    }

    sort(indexArray.begin(), indexArray.end(), [&](int a, int b) {
        return compareByCourseSpecialtySurname(students[a], students[b]);
        });
}

bool binarySearch(const vector<Student>& students, const string& surname, int course, const string& specialty) {
    int left = 0;
    int right = students.size() - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (students[mid].surname == surname && students[mid].course == course && students[mid].specialty == specialty) {
            return true;
        }
        else if (students[mid].surname < surname) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }

    return false;
}

int main() {
    setlocale(LC_ALL, "ukr");
    vector<Student> students;
    int number_of_students;

    cout << "Kilkist studentiv: ";
    cin >> number_of_students;

    inputStudentsData(students, number_of_students);

    sortStudents(students);

    cout << "\nTablytsya studentiv:\n";
    printStudentsTable(students);

    string search_surname;
    int search_course;
    string search_specialty;

    cout << "\nVvedit prizvyshche studenta dlya poshuku: ";
    cin >> search_surname;

    cout << "Kurs studenta: ";
    cin >> search_course;

    cout << "Specialnist studenta: ";
    cin.ignore();
    getline(cin, search_specialty);

    if (binarySearch(students, search_surname, search_course, search_specialty)) {
        cout << "Student navchayetsya na zadanomu kursi ta spetsialnosti." << endl;
    }
    else {
        cout << "Student NE navchayetsya na zadanomu kursi ta spetsialnosti." << endl;
    }

    return 0;
}
