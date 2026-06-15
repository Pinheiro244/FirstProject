#ifndef MATRICULACONTAINER_H
#define MATRICULACONTAINER_H

#include <list>

#include "Matricula.h"
#include "student.h"
#include "TrainingPlan.h"

using namespace std;

class MatriculaContainer {
private:
    list<Matricula*> matriculas;

    Matricula* search(int id) const;
    Matricula* search(Student *student, TrainingPlan *trainingPlan) const;

public:
    ~MatriculaContainer();

    void add(
        int id,
        Student *student,
        TrainingPlan *trainingPlan,
        int day,
        int month,
        int year
    );

    Matricula* get(int id) const;
    Matricula* get(Student *student, TrainingPlan *trainingPlan) const;

    list<Matricula*> getAll() const;

    list<Matricula*> getByStudent(Student *student) const;
    list<Matricula*> getByTrainingPlan(TrainingPlan *trainingPlan) const;

    Matricula* remove(Student *student, TrainingPlan *trainingPlan);
};

#endif