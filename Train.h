#ifndef TRAIN_H
#define TRAIN_H
#include <string>
#include <vector>
#include <chrono>
#include "Ticket.h" 

enum class TrainStatus {
    SCHEDULED,
    DEPARTED,
    ARRIVED
};
