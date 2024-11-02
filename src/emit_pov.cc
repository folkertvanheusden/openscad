#include <iostream>

#include "core/node.h"


void emit_tree_to_pov_children(AbstractNode *const node)
{
	std::vector<AbstractNode *> nodes;
	nodes.push_back(node);

	while(nodes.empty() == false) {
		auto current = nodes.front();
		nodes.erase(nodes.begin());

		for(auto & c: current->getChildren())
			nodes.push_back(&*c);

		printf("// %s\n", current->verbose_name().c_str());
		printf("%s\n", current->povray().c_str());
	}
}

void emit_tree_to_pov(AbstractNode *const node)
{
	for(auto & c: node->getChildren()) {
		printf("object {\n");
		printf("// %s\n", c->verbose_name().c_str());
		printf("%s\n", c->povray().c_str());
		for(auto & c_child: c->getChildren())
			emit_tree_to_pov_children(&*c_child);
		printf("}\n");
	}
}
