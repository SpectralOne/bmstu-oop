#pragma once

#include "controller/controller.hpp"

class BaseCommand {
public:
    BaseCommand() = default;
    ~BaseCommand() = default;

    virtual void Execute(std::shared_ptr<Controller> controller) = 0;
};
