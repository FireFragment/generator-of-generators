#pragma once
#include <QVector>
#include <QRandomGenerator>

template<typename T>
T RandomFromVec(const QVector<T> vec, QRandomGenerator* randGenerator = QRandomGenerator::global()) {
    return vec[std::floor(randGenerator->bounded(vec.size()))];
};
