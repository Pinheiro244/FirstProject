#include "MockData.h"

void MockData::load(School *school) {

    StudentContainer& studentContainer = school->getStudentContainer();
    TrainingPlanContainer& trainingPlanContainer = school->getTrainingPlanContainer();
    MatriculaContainer& matriculaContainer = school->getMatriculaContainer();

    studentContainer.add(
        1,
        "Joao Silva",
        "912345678",
        "joao.silva@email.com"
    );

    studentContainer.add(
        2,
        "Miguel Santos",
        "923456789",
        "miguel.santos@email.com"
    );

    studentContainer.add(
        3,
        "Rafael Costa",
        "934567890",
        "rafael.costa@email.com"
    );

    trainingPlanContainer.add(
        1,
        "Boxe Inicial",
        "Aprendizagem da tecnica base",
        4
    );

    trainingPlanContainer.add(
        2,
        "Condicao Fisica",
        "Melhorar resistencia e forca",
        6
    );

    trainingPlanContainer.add(
        3,
        "Competicao",
        "Preparacao para combate",
        8
    );

    Student *student1 = studentContainer.get(1);
    Student *student2 = studentContainer.get(2);
    Student *student3 = studentContainer.get(3);

    TrainingPlan *trainingPlan1 = trainingPlanContainer.get(1);
    TrainingPlan *trainingPlan2 = trainingPlanContainer.get(2);
    TrainingPlan *trainingPlan3 = trainingPlanContainer.get(3);

    matriculaContainer.add(
        1,
        student1,
        trainingPlan1,
        18,
        6,
        2026
    );

    matriculaContainer.add(
        2,
        student1,
        trainingPlan2,
        18,
        6,
        2026
    );

    matriculaContainer.add(
        3,
        student2,
        trainingPlan2,
        18,
        6,
        2026
    );

    matriculaContainer.add(
        4,
        student3,
        trainingPlan3,
        18,
        6,
        2026
    );
}