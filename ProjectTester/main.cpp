#include <iostream>
#include <cassert>

#include "studentcontainer.h"
#include "trainingplancontainer.h"
#include "MatriculaContainer.h"

using namespace std;

void testStudentContainer() {

    StudentContainer students;

    students.add(1, "Joao Silva", "912345678", "joao@email.com");

    Student *student = students.get(1);

    assert(student->getId() == 1);
    assert(student->getName() == "Joao Silva");
    assert(student->getPhoneNumber() == "912345678");
    assert(student->getEmail() == "joao@email.com");

    cout << "testStudentContainer passed" << endl;
}

void testTrainingPlanContainer() {

    TrainingPlanContainer trainingPlans;

    trainingPlans.add(1, "Boxe Inicial", "Tecnica base", 4);

    TrainingPlan *trainingPlan = trainingPlans.get(1);

    assert(trainingPlan->getId() == 1);
    assert(trainingPlan->getName() == "Boxe Inicial");
    assert(trainingPlan->getObjective() == "Tecnica base");
    assert(trainingPlan->getDurationWeeks() == 4);

    cout << "testTrainingPlanContainer passed" << endl;
}

void testMatriculaContainer() {

    StudentContainer students;
    TrainingPlanContainer trainingPlans;
    MatriculaContainer matriculas;

    students.add(1, "Joao Silva", "912345678", "joao@email.com");
    trainingPlans.add(1, "Boxe Inicial", "Tecnica base", 4);

    Student *student = students.get(1);
    TrainingPlan *trainingPlan = trainingPlans.get(1);

    matriculas.add(
        1,
        student,
        trainingPlan,
        15,
        6,
        2026
    );

    Matricula *matricula = matriculas.get(student, trainingPlan);

    assert(matricula->getId() == 1);
    assert(matricula->getStudent() == student);
    assert(matricula->getTrainingPlan() == trainingPlan);
    assert(matricula->getDay() == 15);
    assert(matricula->getMonth() == 6);
    assert(matricula->getYear() == 2026);

    cout << "testMatriculaContainer passed" << endl;
}

void testRemoveMatricula() {

    StudentContainer students;
    TrainingPlanContainer trainingPlans;
    MatriculaContainer matriculas;

    students.add(1, "Joao Silva", "912345678", "joao@email.com");
    trainingPlans.add(1, "Boxe Inicial", "Tecnica base", 4);

    Student *student = students.get(1);
    TrainingPlan *trainingPlan = trainingPlans.get(1);

    matriculas.add(
        1,
        student,
        trainingPlan,
        15,
        6,
        2026
    );

    Matricula *removed = matriculas.remove(student, trainingPlan);

    assert(removed->getId() == 1);
    assert(removed->getStudent() == student);
    assert(removed->getTrainingPlan() == trainingPlan);

    delete removed;

    assert(matriculas.getAll().empty());

    cout << "testRemoveMatricula passed" << endl;
}

void test() {

    testStudentContainer();
    testTrainingPlanContainer();
    testMatriculaContainer();
    testRemoveMatricula();

    cout << endl;
    cout << "All tests passed!" << endl;
}

int main() {

    test();

    return 0;
}