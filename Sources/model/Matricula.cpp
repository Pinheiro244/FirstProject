#include "Matricula.h"

#include "InvalidDataException.h"

using namespace std;

Matricula::Matricula(
    int id,
    Student *student,
    TrainingPlan *trainingPlan,
    int day,
    int month,
    int year
) : id(id) {

    if (student == nullptr) {
        throw InvalidDataException("Matricula: invalid student.");
    }

    if (trainingPlan == nullptr) {
        throw InvalidDataException("Matricula: invalid training plan.");
    }

    if (!isDateValid(day, month, year)) {
        throw InvalidDataException(
            "Matricula: invalid date " +
            to_string(day) + "/" +
            to_string(month) + "/" +
            to_string(year)
        );
    }

    this->student = student;
    this->trainingPlan = trainingPlan;
    this->day = day;
    this->month = month;
    this->year = year;
}

Matricula::Matricula(const Matricula& other)
    : id(other.id),
      day(other.day),
      month(other.month),
      year(other.year),
      student(other.student),
      trainingPlan(other.trainingPlan) {
}

bool Matricula::isDateValid(int day, int month, int year) const {
    if (year < 1900) {
        return false;
    }

    if (month < 1 || month > 12) {
        return false;
    }

    int daysInMonth[] = {
        31, 28, 31, 30, 31, 30,
        31, 31, 30, 31, 30, 31
    };

    bool leapYear =
        (year % 400 == 0) ||
        (year % 4 == 0 && year % 100 != 0);

    if (leapYear && month == 2) {
        daysInMonth[1] = 29;
    }

    return day >= 1 && day <= daysInMonth[month - 1];
}


int Matricula::getId() const {
    return id;
}

int Matricula::getDay() const {
    return day;
}

int Matricula::getMonth() const {
    return month;
}

int Matricula::getYear() const {
    return year;
}

Student* Matricula::getStudent() const {
    return student;
}

TrainingPlan* Matricula::getTrainingPlan() const {
    return trainingPlan;
}

bool Matricula::operator==(const Matricula& other) const {
    return this->id == other.id;
}

bool Matricula::operator==(int id) const {
    return this->id == id;
}

bool Matricula::hasStudent(Student *student) const {
    return this->student == student;
}

bool Matricula::hasTrainingPlan(TrainingPlan *trainingPlan) const {
    return this->trainingPlan == trainingPlan;
}

bool Matricula::hasStudentAndTrainingPlan(Student *student, TrainingPlan *trainingPlan) const {
    return hasStudent(student) && hasTrainingPlan(trainingPlan);
}