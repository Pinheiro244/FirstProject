

#include "exercisecontainer.h"
#include "DuplicatedDataException.h"
#include "NotFoundException.h"

ExerciseContainer::~ExerciseContainer() {
    for (Exercise* exercise : exercises) {
        delete exercise;
    }
}

Exercise* ExerciseContainer::search(int id) {
    for (Exercise* exercise : exercises) {
        if (*exercise == id) {
            return exercise;
        }
    }

    return nullptr;
}

void ExerciseContainer::add(int id, const string& name, const string& description) {
    Exercise* exercise = search(id);

    if (exercise == nullptr) {
        exercise = new Exercise(id, name, description);
        exercises.push_back(exercise);
    } else {
        throw DuplicatedDataException("Exercise: " + to_string(id));
    }
}

Exercise* ExerciseContainer::get(int id) {
    Exercise* exercise = search(id);

    if (exercise == nullptr) {
        throw NotFoundException("Exercise: " + to_string(id));
    }

    return exercise;
}

list<Exercise*> ExerciseContainer::getAll() const {
    return exercises;
}