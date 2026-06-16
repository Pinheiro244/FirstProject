#include "exercise.h"
#include "InvalidDataException.h"

Exercise::Exercise(int id, const string& name, const string& description) {
    if (!isNameValid(name)) {
        throw InvalidDataException("Exercise: invalid name");
    }

    this->id = id;
    this->name = name;
    this->description = description;
}

bool Exercise::isNameValid(const string& name) const {
    return name.length() >= 3;
}

int Exercise::getId() const {
    return id;
}

string Exercise::getName() const {
    return name;
}

string Exercise::getDescription() const {
    return description;
}

bool Exercise::operator==(int id) const {
    return this->id == id;
}