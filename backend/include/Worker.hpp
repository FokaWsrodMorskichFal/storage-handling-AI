#pragma once

#include "NeuralNetwork.hpp"
#include "WorkerInput.hpp"
#include "WorkerOutput.hpp"
#include "Box.hpp"

#include <memory>

class Worker {
    double x;
    double y;
    double smell;
    std::shared_ptr<Box> heldBox;
    NeuralNetwork neuralNetwork;
    double traveledDistance;
public:
    Worker();
    Worker(NeuralNetwork, double=.0, double=.0);
    WorkerOutput decideAction(WorkerInput&) const;
    bool doesHoldBox() const { return heldBox != nullptr; };
    Box& getHeldBox() const { return *heldBox.get(); };
    void holdBox(Box&);
    bool dropBox();
    double getX() const { return x; };
    double getY() const { return y; };
    double getSmell() const { return smell; };
    void setSmell(double smell) { this->smell = smell; };
    void moveBy(double, double);
    double getTraveledDistance() const { return traveledDistance; };
    double distance(const Worker&) const;
};