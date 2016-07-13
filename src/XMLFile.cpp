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

	child->SetLevel(level+1);
}

bool Node::isEmpty()
{
	return children.empty() && value == "";
}

void Node::SetLevel(char lvl)
{
	level = lvl;

	for (size_t i = 0; i < children.size(); i++)
		children[i]->SetLevel(lvl+1);
}

void Node::write(std::ofstream& str)
{
	if (name != "")
	{
		str << std::string(level, '\t') << "<" << name << ">";
		if (children.size())
		{
			str << '\n';
			for (size_t i = 0; i < children.size(); i++)
				if (!children[i]->isEmpty()) children[i]->write(str);

			str << std::string(level, '\t');
		}
		else str << value;
		str << "</" << name << ">\n";
	}
}

Node Node::read(std::string const& file, size_t& pos)
{
	Node current;

	// Read opening name
	size_t start = file.find('<', pos);
	if (start == std::string::npos) throw "The file " + file + " is corrupted.";

	size_t end 	 = file.find('>', start+1);
	if (end == std::string::npos) throw "The file " + file + " is corrupted.";

	current.name = file.substr(start+1, end);

	// Read value
	start = file.find('<', pos);
	if (start == std::string::npos) throw "The file " + file + " is corrupted.";

	current.value = file.substr(end+1, start);
	pos = start;

	// Read closing name
	start = file.find('<', start);
	if (start == std::string::npos) throw "The file " + file + " is corrupted.";

	end 	 = file.find('>', start+1);
	if (end == std::string::npos) throw "The file " + file + " is corrupted.";

	if (file.substr(start+1, end) != current.name) current.value = "PARENT";
	else pos = start+1;

	return current;
}

// ============================ XMLFile =================================
void XMLFile::read(std::string filename)
{
	InFile.open(filename.c_str());


	if (InFile.good())
	{
		// get length of file:
		InFile.seekg(0, InFile.end);
		int length = InFile.tellg();
		InFile.seekg(0, InFile.beg);

		char * buffer = new char [length];

		// read data as a block:
		InFile.read(buffer,length);

		if (!InFile.good())
			throw "Impossible to read the whole file: " + filename;

		file = std::string(buffer);
		delete[] buffer;
	}
	else throw "Impossible to open file: " + filename;

	// Analyse the file
	size_t pos = 0;
	std::string name;
	std::string value;
	while (!NodeStack.empty()) NodeStack.pop();
	std::string parent = "";
	Node N;

	while (pos < file.size())
	{
		N = Node::read(file, pos);
		name = N.name;
		value  = N.value;

		if (name.empty()) throw "Invalid node name at position " + pos;
		else if (name[0] != '/' && value.empty()) NodeStack.push(name);
		else if (NodeStack.top() == name.substr(1)) NodeStack.pop();
		else throw "Inconsistent nodes structure.";

		bool endNode = (name[0] == '/') ? true : false;
		if (endNode) name = name.substr(1);

		// change parent
		/*switch (name)
		{
		case "inputs":
		case "initial_solution":
		case "topography":
			if (parent) parent = "";
			else 		parent = name;
			break;
		default: break;
		}

		// Read node
		switch(parent)
		{
		case "inputs":
			switch(name)
			{
			case "size": break;
			case "resolution": break;
			case "sim_time": c	break;
			case "max_water_height"; break;
			case "min_water_height": break;
			case "cell_threshold": break;
			}
			break;
		case "initial_solution":
			switch(name)
			{
			case "distribution": break;
			case "centerX": break;
			case "centerY": break;
			case "widthX": break;
			case "widthY"; break;
			case "height": break;
			}
			break;
		case "topography":
			switch(name)
			{
			case "topo_type": break;
			case "boundaries": break;
			}
			break;
		}*/
	}
	if (!NodeStack.empty()) throw "The file " + filename + " is inconsistent.";
}
