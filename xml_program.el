//add <word>
//		<lexeme>emma</lexeme>
//		<tag>noun</tag>
//		<description>subject</description>
//	</word>
document doc = new document('doc.xml');
node rootNode = doc.root();

node lexemeNode = new node('tag');
node lexemeContent = new node('content');
lexemeNode = 'lexeme';
lexemeContent = 'emma';
lexemeNode.add(lexemeContent);

node wordNode = new node('tag');
wordNode = 'word';
node tagNode = new node('tag');
tagNode = 'tag';
node tagContent = new node('content');
tagContent = 'noun';
tagNode.add(tagContent);

node descriptionNode = new node('tag');
descriptionNode = 'description';
node descriptionContent = new node('content');
descriptionContent = 'subject';
descriptionNode.add(descriptionContent);

wordNode.add(lexemeNode);
wordNode.add(tagNode);
wordNode.add(descriptionNode);

rootNode.add(wordNode);

doc.save();