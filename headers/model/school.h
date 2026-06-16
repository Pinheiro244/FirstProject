#ifndef SCHOOL_H
#define SCHOOL_H

#include "studentcontainer.h"
#include "trainingplancontainer.h"
#include "MatriculaContainer.h"
#include "exercisecontainer.h"

class School {

private:
    StudentContainer studentContainer;
    TrainingPlanContainer trainingPlanContainer;
    MatriculaContainer matriculaContainer;
    ExerciseContainer exerciseContainer;

public:
    School() = default;

    ~School() = default;

    StudentContainer& getStudentContainer();

    TrainingPlanContainer& getTrainingPlanContainer();

    MatriculaContainer& getMatriculaContainer();

    ExerciseContainer& getExerciseContainer();
};

#endif