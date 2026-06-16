#include "TrainingPlanService.h"
#include "TrainingPlanMapper.h"
#include "DataConsistencyException.h"
#include "MatriculaContainer.h"

using namespace std;

TrainingPlanService::TrainingPlanService(ISchoolRepository* repo) {
    this->repo = repo;
}

int generateTrainingPlanId(TrainingPlanContainer& container) {
    int maxId = 0;

    list<TrainingPlan*> trainingPlans = container.getAll();

    for (TrainingPlan* trainingPlan : trainingPlans) {
        if (trainingPlan->getId() > maxId) {
            maxId = trainingPlan->getId();
        }
    }

    return maxId + 1;
}

void TrainingPlanService::add(const TrainingPlanINDTO& obj) {

    School* model = this->repo->getModel();

    TrainingPlanContainer& container = model->getTrainingPlanContainer();

    int id = generateTrainingPlanId(container);

    container.add(
        id,
        obj.name,
        obj.objective,
        obj.durationWeeks
    );
}

void TrainingPlanService::getAll(list<TrainingPlanOUTDTO>& dtos) {

    School* model = this->repo->getModel();

    TrainingPlanContainer& container = model->getTrainingPlanContainer();

    list<TrainingPlan*> trainingPlans = container.getAll();

    TrainingPlanMapper::listModel2listDTO(trainingPlans, dtos);
}

void TrainingPlanService::get(int id, TrainingPlanOUTDTO& dto) {

    School* model = this->repo->getModel();

    TrainingPlanContainer& container = model->getTrainingPlanContainer();

    TrainingPlan* trainingPlan = container.get(id);

    TrainingPlanMapper::model2DTO(trainingPlan, dto);
}

void TrainingPlanService::remove(int id, TrainingPlanOUTDTO& dto) {

    School* model = this->repo->getModel();

    TrainingPlanContainer& trainingPlanContainer = model->getTrainingPlanContainer();
    MatriculaContainer& matriculaContainer = model->getMatriculaContainer();

    TrainingPlan* trainingPlan = trainingPlanContainer.get(id);

    list<Matricula*> matriculas = matriculaContainer.getByTrainingPlan(trainingPlan);

    if (matriculas.empty()) {

        trainingPlan = trainingPlanContainer.remove(id);

        TrainingPlanMapper::model2DTO(trainingPlan, dto);

        delete trainingPlan;

    } else {

        string msg = "Training Plan: " + to_string(id);

        throw DataConsistencyException(msg);
    }
}

void TrainingPlanService::update(int id, const TrainingPlanINDTO& obj) {

    School* model = this->repo->getModel();

    TrainingPlanContainer& container = model->getTrainingPlanContainer();

    TrainingPlan* trainingPlan = container.get(id);

    trainingPlan->setName(obj.name);
    trainingPlan->setObjective(obj.objective);
    trainingPlan->setDurationWeeks(obj.durationWeeks);
}

void TrainingPlanService::addExerciseToTrainingPlan(int trainingPlanId, int exerciseId) {
    School* model = this->repo->getModel();

    TrainingPlanContainer& trainingPlanContainer = model->getTrainingPlanContainer();
    ExerciseContainer& exerciseContainer = model->getExerciseContainer();

    TrainingPlan* trainingPlan = trainingPlanContainer.get(trainingPlanId);
    Exercise* exercise = exerciseContainer.get(exerciseId);

    trainingPlan->addExercise(exercise);
}