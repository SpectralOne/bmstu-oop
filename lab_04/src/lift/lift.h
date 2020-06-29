#pragma once

#include <QObject>
#include <QTextEdit>

#include "../cabin/cabin.h"
#include "../control_panel/controlpanel.h"
#include "constants.h"

class Lift : public QObject {
    Q_OBJECT

   public:
    Lift();
    void click(int floor);

   private:
    ControlPanel control_panel;
    Cabin cabin;
};
