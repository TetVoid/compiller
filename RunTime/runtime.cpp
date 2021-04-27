#include "runtime.h"
#include <sstream>
#include <iostream>
#include <fstream>



document::document(std::string path) 
{
    this->path = path;

	

	std::ifstream file;
	file.open(path);
	if (file)
	{
		file.close();
		pugi::xml_document doc;
		const char* c = path.c_str();
		pugi::xml_parse_result result = doc.load_file(c);
		pugi::xml_node child = doc.child("root");
		node someNode("tag", child.name());
		root_node = someNode;
		walk(child.children(), &root_node);
	}
	else
	{
		node start_node("tag", "root");
		root_node = start_node;
	}

}

void document::set_path(std::string path)
{
	this->path = path;
}

void document::set_root(node some_node)
{
	this->root_node = some_node;
}
node& document::root()
{ 
    return root_node; 
}
void  document::save()
{
	pugi::xml_document doc;
	pugi::xml_node new_node = doc.append_child("root");
	for (int i = 0; i < root_node.get_children().size(); i++)
	{
		pugi::xml_node _node = new_node.append_child(root_node.get_children()[i].get_value().c_str());

		for (int j = 0; j < root_node.get_children()[i].attributes().size(); i++)
			new_node.append_attribute(root_node.get_children()[i].attributes()[i].getName().c_str());
		regres_walk(root_node.get_children()[i], &_node);
	}

	std::ostringstream ss;
	doc.save(ss);
	std::string s = ss.str();


	std::ofstream out(path);
	if (out.is_open())
	{
		out << s<< std::endl;
	}
	out.close();
}

void document::regres_walk(node some_node, pugi::xml_node *creation_node)
{
	
		std::vector<node> children = some_node.get_children();
		for (int i = 0; i < children.size(); i++)
		{
			if (children[i].get_type() != "content")
			{
				pugi::xml_node new_node = creation_node->append_child(children[i].get_value().c_str());

				for (int j = 0; j < children[i].attributes().size(); i++)
					new_node.append_attribute(children[i].attributes()[i].getName().c_str()) = children[i].attributes()[i].getValue().c_str();
				regres_walk(children[i], &new_node);
			}
			else
			{
				creation_node->text().set(children[i].get_value().c_str());
			}
		}
}
std::vector<node>  document::findNode(std::string content)
{
    
    return  root_node.findNode(content);
}
void  document::Delete()
{
	path = "";
	delete(&root_node);
}
int  document::size() 
{ 
    return this->root_node.size(); 
}


void document::walk(pugi::xml_object_range<pugi::xml_node_iterator> children, node *some_node)
{
	for (pugi::xml_node child : children)
	{
		node new_node("tag", child.name());

		for (pugi::xml_attribute_iterator ait = child.attributes_begin(); ait != child.attributes_end(); ++ait)
		{
			attribute atr(ait->name());
			atr.set_value(ait->value());
			new_node.add(atr);
		}

		if (child.child_value() == "")
		{
			walk(child.children(), &new_node);
		}
		else
		{
			node content_node("content", child.child_value());
			new_node.add(content_node);
			
		}
		some_node->add(new_node);
	}
}




node::node()
{
}

node::node(std::string type)
{
	this->type = type;
}
node::node(std::string type, std::string value) 
{
    this->type = type;
    this->value.append(value);
}


std::vector<node> node::findNode(std::string content)
{
    std::vector<node> answer;
	for (int i = 0; i < children.size(); i++)
			if (children[i].value == content)
				answer.push_back(children[i]);
    return answer;
}


std::vector<attribute> node::attributes()
{
    return _attributes;
}
void node::Delete()
{
	delete(this);
}
void node::insert( int pos, node some_node)
{
        children.emplace(children.cbegin() + pos, some_node);
}

void node::add(node some_node)
{
    children.push_back(some_node);
}

void node::add(attribute some_atr)
{
    _attributes.push_back(some_atr);
}

int node::size() 
{
        return this->children.size();
}

std::vector<node> node::get_children()
{
	return children;
}
std::string node::get_type()
{
	return type;
}
std::string node::get_value()
{
	std::string answer = "";
	for (int i = 0; i < value.size(); i++)
		answer += value[i];
	return answer;
}

void node::set_value(std::string value,int pos)
{
	if (value.size() !=0)
		this->value.insert(0, value);
	else
		this->value.append(value);
}

void node::add(std::string value)
{
	this->value.append(value);
}


attribute::attribute(std::string name)
{
    this->name = name;
	this->value = value;
}
std::string attribute::getName()
{
    return this->name;
}

void attribute::Delete()
{
	delete(this);
}

std::string attribute::getValue()
{
	return this->value;
}

void attribute::set_value(std::string value)
{
	this->value = value;
}

void print(document doc)
{
	print(doc.root());
}

void print(node node)
{
	for (size_t i = 0; i < node.get_value().size(); i++)
	{
		std::cout << node.get_value()[i]<<"\n";
	}
	for (int i = 0; i < node.attributes().size(); i++)
	{
		print(node.attributes()[i]);
	}
	for (int i = 0; i < node.get_children().size(); i++)
	{
		print(node.get_children()[i]);
	}
}

void print(attribute attr)
{
	std::cout <<attr.getName()<< attr.getValue()<<"\n";
}

void del(document& doc)
{
	doc.Delete();
}

void del(node& node)
{
	node.Delete();
}

void del(attribute& attr)
{
	attr.Delete();
}

document typeCast(node& nd){
    document new_doc("");
	new_doc.set_root(nd);
	return new_doc;
}

node typeCast(document& doc){
    return doc.root();
}