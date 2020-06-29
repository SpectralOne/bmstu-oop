#pragma once

#include <QTextEdit>
#include <QTimer>

enum direction {
    DOWN = -1,
    STAY,
    UP
};

#define CROSSING_FLOOR 1500
#define DOORS_TIME 2000
#define WAITING_TIME 2000

#define NUM_FLOORS 10
