#pragma once

#include "base_command.hpp"
#include "controller/controller.hpp"
#include "draw/abstract_factory.hpp"
#include "draw/qt_drawer.hpp"
#include "load/file_loader.hpp"

class AddCameraCommand : public BaseCommand {
   public:
    explicit AddCameraCommand(std::string name);
    void Execute(std::shared_ptr<Controller> controller) override;

   private:
    std::string _name;
};

class AddModelCommand : public BaseCommand {
   public:
    explicit AddModelCommand(std::string model_name, std::string file_name);

    void Execute(std::shared_ptr<Controller> controller) override;

   private:
    std::string model_name;
    std::string file_name;
};

class RemoveCameraCommand : public BaseCommand {
   public:
    RemoveCameraCommand(std::string object_name);
    void Execute(std::shared_ptr<Controller> controller) override;

   private:
    std::string _object_name;
};

class RemoveModelCommand : public BaseCommand {
   public:
    RemoveModelCommand(std::string object_name);
    void Execute(std::shared_ptr<Controller> controller) override;

   private:
    std::string _object_name;
};

class TransformCameraCommand : public BaseCommand {
   public:
    TransformCameraCommand(std::string _object_name, Point3D<double>& move, Point3D<double>& rotate);
    void Execute(std::shared_ptr<Controller> controller) override;

   private:
    std::string _object_name;
    Point3D<double> _move;
    Point3D<double> _rotate;
};

class TransformModelCommand : public BaseCommand {
   public:
    TransformModelCommand(std::string object_name, Point3D<double>& move, Point3D<double>& scale, Point3D<double>& rotate);
    void Execute(std::shared_ptr<Controller> controller) override;

   private:
    std::string _object_name;
    Point3D<double> _move;
    Point3D<double> _scale;
    Point3D<double> _rotate;
};

class DrawCommand : public BaseCommand {
   public:
    explicit DrawCommand(std::shared_ptr<BaseDrawer> drawer);
    void Execute(std::shared_ptr<Controller> controller) override;

   private:
    std::shared_ptr<BaseDrawer> _drawer;
    std::shared_ptr<AbstractFactory> _factory;
};

class SetCameraCommand : public BaseCommand {
   public:
    explicit SetCameraCommand(std::string name);
    void Execute(std::shared_ptr<Controller> Controller) override;

   private:
    std::string _name;
};
