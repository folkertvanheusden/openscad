#pragma once

#include <string>

#include "core/node.h"
#include "geometry/linalg.h"

class ColorNode : public AbstractNode
{
public:
  VISITABLE();
  ColorNode(const ModuleInstantiation *mi) : AbstractNode(mi), color(-1.0f, -1.0f, -1.0f, 1.0f) { }
  std::string toString() const override;
  std::string name() const override;
  std::pair<std::string, AbstractNode::povray_type_t> povray() const override;

  Color4f color;
};
