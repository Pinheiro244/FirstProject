 #include "TrainingPlanView.h"

#include <iostream>
#include "Utils.h"

using namespace std;

TrainingPlanINDTO TrainingPlanView::getTrainingPlan() {

    string name = Utils::getString("Enter the Training Plan Name");
    string objective = Utils::getString("Enter the Training Plan Objective");
    int durationWeeks = Utils::getNumber("Enter the Duration in Weeks");
    list<string> exercises;

    TrainingPlanINDTO trainingPlan(
        name,
        objective,
        durationWeeks

    );

    return trainingPlan;
}

void TrainingPlanView::printTrainingPlan(TrainingPlanOUTDTO *trainingPlan) {

    cout << endl;
    cout << "Training Plan Id: " << trainingPlan->id << endl;
    cout << "Name: " << trainingPlan->name << endl;
    cout << "Objective: " << trainingPlan->objective << endl;
    cout << "Duration Weeks: " << trainingPlan->durationWeeks << endl;
    cout << "Exercises: ";

    if (trainingPlan->exercises.empty()) {
        cout << "No exercises associated";
    } else {
        for (const string& exercise : trainingPlan->exercises) {
            cout << exercise << " ";
        }
    }

    cout << endl;
}

void TrainingPlanView::printTrainingPlans(list<TrainingPlanOUTDTO> trainingPlans) {

    for (TrainingPlanOUTDTO trainingPlan : trainingPlans) {
        printTrainingPlan(&trainingPlan);
        cout << "------------------------" << endl;
    }
}
void TrainingPlanView::getExerciseAssociation(int& trainingPlanId, int& exerciseId) {

    cout << endl;
    cout << "Available Boxing Exercises:" << endl;
    cout << "1 - Jab" << endl;
    cout << "2 - Cross" << endl;
    cout << "3 - Hook" << endl;
    cout << "4 - Uppercut" << endl;
    cout << "5 - Footwork" << endl;
    cout << "6 - Heavy Bag" << endl;

    trainingPlanId = Utils::getNumber("Enter the Training Plan Id");
    exerciseId = Utils::getNumber("Enter the Exercise Id");
}