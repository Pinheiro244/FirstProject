#include "TrainingPlanMapper.h"
#include "exercise.h"

void TrainingPlanMapper::model2DTO(TrainingPlan* trainingPlan, TrainingPlanOUTDTO& obj) {
    obj.id = trainingPlan->getId();
    obj.name = trainingPlan->getName();
    obj.objective = trainingPlan->getObjective();
    obj.durationWeeks = trainingPlan->getDurationWeeks();

    obj.exercises.clear();

    list<Exercise*> exercises = trainingPlan->getExercises();

    for (Exercise* exercise : exercises) {
        obj.exercises.push_back(exercise->getName());
    }
}
void TrainingPlanMapper::listModel2listDTO(
    list<TrainingPlan*> trainingPlans,
    list<TrainingPlanOUTDTO>& dtos
) {

    for (TrainingPlan* trainingPlan : trainingPlans) {

        TrainingPlanOUTDTO dto;

        model2DTO(trainingPlan, dto);

        dtos.push_back(dto);
    }
}