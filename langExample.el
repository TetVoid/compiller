document doc = new document('doc.xml');
node someNode = new node('tag');
attribute someAtr = new attribute('atrName');
someNode = 'content';

node someFunc(node someNode){
   node test =  new node('tag');
   print(someNode);
   return test;
}

someFunc(doc.root());
someAtr = 'value';

doc = 'newDoc.xml'; // this is a comment and this line override path to xml doc
doc.save();
node rootNode = doc.root();
node root = doc.root();
node[] foundedNode = doc.findNode('content');


node[] tempNode = someNode.findNode('content');


attribute[] nodeAttrs = someNode.attributes;
someNode += someAtr;
someNode += '+ new content';
node firstNode = someNode[0];

someNode(2) = 'new content'; //override content of text node from 2 pos (string starts with 0 pos)

someNode(2) += '+ new content'; //add content to text node from 2 pos

someNode.insert(0, someNode); //insert node to 0 pos

someNode.add(someNode); //insert node to the end of nodes

print(someNode);
del(someNode);
del(someAtr);
doc.delete();

if (someNode == 'content') {
   node test =  new node('tag');
   someNode = 'newContent';
   print(someNode);

} else { 
   print(someNode);
}

for(node i in root){
  node test =  new node('tag');
  print(i);
} 

node current = doc.root();

while (current.size()){
   print(current);
   node test =  new node('tag');
   current = current[0];
   someFunc(test);
}

someFunc(root);

doc = (document) root;

(node) doc;
