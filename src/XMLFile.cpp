/*
 * XMLFile.cpp
 *
 *  Created on: 31 mai 2016
 *      Author: gbrunner
 */
#include "XMLFile.h"

Node::Node(std::string NAME, std::string VALUE)
: name(NAME), value(VALUE), level(0)
{}

void Node::add(Node* child)
{
	children.push_back(child);
	child->Setlevel(level+1);
}

void Node::print(std::ofstream& str)
{
	if (name != "")
	{
		str << std::string(level, '\t') << "<" << name << ">";
		if (children.size())
		{
			str << '\n';
			for (size_t i = 0; i < children.size(); i++) children[i]->print(str);
			str << std::string(level, '\t');
		}
		else str << value;
		str << "</" << name << ">\n";
	}
}
