#pragma once

#include <iostream>
#include <string>
using std::string;


/**
* Represents a vertex of a graph.
* The tag of the vertex is stored as its _id and must be unique.
**/
class Vertex {
  public:

  Vertex(string id) {
    _id = id;
  }

  friend std::ostream & operator<<(std::ostream & out, const Vertex & v) {
    out << "Vertex(" << v.getID() << ")";
    return out;
  }

  string getID() const {
    return _id;
  }

  bool operator==(const Vertex & other) const {
    return _id == other.getID();
  }

  bool operator<(const Vertex& other) const { 
    return (_id < other.getID()); 
  } 

  private:
  string _id;

};

namespace std {
  template<> 
  struct hash<Vertex> {
    std::size_t operator()(const Vertex & v) const noexcept {
      std::hash<string> hf;
      return hf(v.getID());
    }
  };

  template<> 
  struct hash<const Vertex> {
    std::size_t operator()(const Vertex & v) const noexcept {
      std::hash<string> hf;
      return hf(v.getID());
    }
  };
}
