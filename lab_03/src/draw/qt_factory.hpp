#pragma once

#include "abstract_factory.hpp"

class QtFactory : public AbstractFactory {
   public:
    std::shared_ptr<BaseDrawer> createGraphics() const override;
};
