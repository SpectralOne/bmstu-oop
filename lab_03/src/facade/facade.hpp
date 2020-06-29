#pragma once

#include "commands/base_command.hpp"
#include "commands/commands.hpp"
#include "controller/controller.hpp"
#include "exceptions/base_exception.hpp"

class Facade {
   public:
    Facade();
    ~Facade();

    void ExecuteCommand(std::shared_ptr<BaseCommand> command);

   private:
    std::shared_ptr<Controller> _controller;
};
