#include <iostream>

#include "headers/repo/SchoolMemoryRepository.h"

#include "headers/model/school.h"
#include "headers/model/exercisecontainer.h"

#include "headers/service/StudentService.h"
#include "headers/service/TrainingPlanService.h"
#include "headers/service/MatriculaService.h"

#include "headers/controller/controller.h"

#include "mock/MockData.h"

using namespace std;

int main() {

    SchoolMemoryRepository repo;

    MockData::load(repo.getModel());

    StudentService studentService(&repo);
    TrainingPlanService trainingPlanService(&repo);
    MatriculaService matriculaService(&repo);

    School* model = repo.getModel();
    ExerciseContainer& exerciseContainer = model->getExerciseContainer();

    exerciseContainer.add(1, "Jab", "Straight punch with the lead hand");
    exerciseContainer.add(2, "Cross", "Straight punch with the rear hand");
    exerciseContainer.add(3, "Hook", "Circular punch");
    exerciseContainer.add(4, "Uppercut", "Upward punch");
    exerciseContainer.add(5, "Footwork", "Movement and positioning exercise");
    exerciseContainer.add(6, "Heavy Bag", "Punching bag training");



    Controller controller(&studentService, &trainingPlanService, &matriculaService);
    controller.run();

    return 0;
}

