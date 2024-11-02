#include <iostream>

#include "core/node.h"


void emit_objects(AbstractNode *const node)
{
	std::vector<std::pair<std::string, bool> > converted_nodes;

	std::vector<AbstractNode *> nodes;
	nodes.push_back(node);
	while(nodes.empty() == false) {
		auto current = nodes.front();
		nodes.erase(nodes.begin());

		for(auto & c: current->getChildren())
			nodes.push_back(&*c);

		converted_nodes.push_back(current->povray());
	}

	printf("object {\n");

	// object
	for(auto & node: converted_nodes) {
		if (node.second == true)
			printf("%s", node.first.c_str());
	}

	// modifiers
	for(auto & node: converted_nodes) {
		if (node.second == false)
			printf("%s", node.first.c_str());
	}

	printf("}\n");
}

void emit_tree_to_pov(AbstractNode *const node)
{
	std::vector<double> locations { -100, 0, 100 };
	constexpr double brightness = 0.2;
	for(auto cur_lx: locations) {
		for(auto cur_ly: locations) {
			for(auto cur_lz: locations)
				std::cout << "light_source { <" << cur_lx << ", " << cur_ly << ", " << cur_lz << "> color rgb <" << brightness << ", " << brightness << ", " << brightness << "> }\n";
		}
	}

	for(auto & c: node->getChildren())
		emit_objects(&*c);

	printf("camera { location<100, 100, 100> look_at<0, 0, 0> }\n");
}
