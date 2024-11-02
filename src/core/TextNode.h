#pragma once

#include <memory>
#include <string>
#include <vector>

#include "core/node.h"
#include "core/FreetypeRenderer.h"

class TextModule;

class TextNode : public AbstractPolyNode
{
public:
  VISITABLE();
  TextNode(const ModuleInstantiation *mi) : AbstractPolyNode(mi) {}

  std::string toString() const override;
  std::string name() const override { return "text"; }
  std::pair<std::string, AbstractNode::povray_type_t> povray() const override;

  virtual std::vector<std::shared_ptr<const Geometry>> createGeometryList() const;

  virtual FreetypeRenderer::Params get_params() const;

  FreetypeRenderer::Params params;
};
