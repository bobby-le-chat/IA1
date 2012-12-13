#ifndef NODE_H
#define NODE_H
#include <string>
#include <vector>

class Node
{

  std::string 			_value;
  float 				_poid;
  std::pair<int, int>  	_abs;  

  
  
public:
  Node(const std::string& value, float _poid, int x, int y);
  Node();
  Node(const Node& other);
  ~Node();
  Node& 			operator=(const Node& other);
  bool 				operator==(const Node& other) const;
  
  void				setParams(const std::string& value, float poid,
					  const std::pair<int, int>& abs);
  void				setWeight(float weight);
  
  void				setAbs(int x, int y);
  const std::pair<int, int>& 	getAbs() const;
  const std::string&		getValue() const;
  float 			getWeight() const;
};

#endif // NODE_H
