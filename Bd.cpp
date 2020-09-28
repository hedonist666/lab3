#include "Bd.h"

BD::BD() {

}

BD::BD(BD& other) {
    data = other.data;
}

BD BD::operator=(BD& other) {
    data = other.data; 
    return *this;
}

BD::BD(BD&& other) {
    data = std::move(other.data);
}

BD BD::operator=(BD&& other) {
    data = std::move(other.data);
    return *this;
}

Data& BD::operator[](std::string idx) {
    return data[idx];
}

std::ostream& operator<<(std::ostream& os, BD& bd) {
    for (auto [key, rec] : bd.data) {
        os << key << '\n';
        os << "Возраст: " << rec.age << '\n';
        if (rec.sex == Sex::MALE) {
            os << "Пол: мужской\n";
        }
        else {
            os << "Пол: женский\n";
        }
        os << "Должность: " << rec.post << '\n';
        os << "Зарплата: " << rec.income << '\n';
    }
    return os;
}

Data::Data(int age, Sex sex, std::string post, int income) : age {age}, sex {sex}, post {post}, income {income} {}
Data::Data() : age{0} {}
