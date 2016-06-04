#ifndef _SRC_XMLFILE_H_
#define _SRC_XMLFILE_H_

#include "included.h"

class Node;

class Node
{
private:
	char 			   level;
	std::vector<Node*> children;

public:
	std::string name;
	std::string value;

	Node(std::string name = "", std::string value = "");

	void print(std::ofstream& str);
	void add(Node* child);

	void Setlevel(char lvl) { level = lvl; }
};


class XMLFile
{
private:
	std::ostream OutFile;
	std::ifstream InFile;

public:
	XMLFile();

};

#endif /* _SRC_XMLFILE_H */
