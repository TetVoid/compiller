#include <iostream>
#include <vector>
#include "runtime.h"

using namespace std;


int main(){
document doc("doc.xml");
node& rootNode = doc.root();
node lexemeNode("tag");
node lexemeContent("content");
lexemeNode.set_value("lexeme",0);
lexemeContent.set_value("emma",0);
lexemeNode.add(lexemeContent);
node wordNode("tag");
wordNode.set_value("word",0);
node tagNode("tag");
tagNode.set_value("tag",0);
node tagContent("content");
tagContent.set_value("noun",0);
tagNode.add(tagContent);
node descriptionNode("tag");
descriptionNode.set_value("description",0);
node descriptionContent("content");
descriptionContent.set_value("subject",0);
descriptionNode.add(descriptionContent);
wordNode.add(lexemeNode);
wordNode.add(tagNode);
wordNode.add(descriptionNode);
rootNode.add(wordNode);
doc.save();

}