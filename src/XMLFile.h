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

	void write(std::ofstream& str);
	static Node read(std::string const& file, size_t& pos);

	void add(Node* child);
	bool isEmpty();

private:
	void SetLevel(char lvl);
};


class XMLFile
{
private:
	std::ostream OutFile;
	std::ifstream InFile;

	std::string file;
	std::stack<std::string> NodeStack;
public:
	XMLFile();

	void read(std::string file);
};

#endif /* _SRC_XMLFILE_H */
