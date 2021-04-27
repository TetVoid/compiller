#pragma once
#include <string>
#include <vector>
#include "pugixml-1.11/src/pugixml.hpp"

class attribute {
public:
    attribute(std::string name);
    std::string getName();
    void Delete();
    std::string getValue();
    void set_value(std::string);
private:
    std::string name;
    std::string value;
    std::string valueType;
};

class node {
public:
    node();
    node(std::string type, std::string value);
    node(std::string type);
    std::vector<node> findNode(std::string content);
    std::vector<attribute> attributes();
    void Delete();
    void insert(int pos, node some_node);
    void add(node some_node);
    void add(attribute some_atr);
    void add(std::string);
    int size();
    std::vector<node> get_children();
    std::string get_type();
    std::string get_value();
    void set_value(std::string,int);
private:
    std::string type;
    std::string value="";
    std::string valueType;
    std::vector<node> children;
    std::vector<attribute> _attributes;
};



class document{
public:
    document(std::string path);
    node& root();
    void save();
    std::vector<node> findNode(std::string content);
    void Delete();
    int size();
    void set_path(std::string path);
    void set_root(node);
    
private:
    void walk(pugi::xml_object_range<pugi::xml_node_iterator> children, node *some_node);
    void regres_walk(node some_node, pugi::xml_node* creation_node);

    std::string path;
    node root_node;
};


void print(document doc);
void print(node node);
void print(attribute attr);
void del(document& doc);
void del(node& node);
void del(attribute& attr);
document typeCast(node& n);
node typeCast(document& doc);