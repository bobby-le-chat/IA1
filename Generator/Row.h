#ifndef ROW_H
#define ROW_H
#include <vector>
#include "Node.h"

class Row
{
  std::vector<Node>	_nodes;
  int			_y;
  
public:
Row();
Row(const Row& other);
virtual		~Row();
virtual Row& 	operator=(const Row& other);
virtual bool 	operator==(const Row& other) const;

const std::vector<Node>& 	getNodes() const;
void		addNode(const Node& node);
void		addNode(const Node& node, int x);

void		deleteNode(const Node& node);
void		deleteNode(int x);

int		getLineNumber() const;

};

#endif // ROW_H
