#pragma once

#include <memory>

#include "build_stuff/base_model_builder.hpp"
#include "managers/base_manager.hpp"
#include "objects/model/model.hpp"
#include "load/source_loader.hpp"

class AbstractLoader {
   public:
    virtual ~AbstractLoader() = default;
    virtual std::shared_ptr<Model> loadModel(std::string model_name, std::string source_name) = 0;

   protected:
    std::shared_ptr<SourceLoader> _loader;
};
