from generated import EasyXMLParser, EasyXMLLexer
from visitor.myVisitor import MyVisitor
from checker.checker import Checker
from RunTime.compiler import xml_compile
from antlr4 import *
import sys
import os


def main(xml_program: str) -> None:
    # input_stream = FileStream(xml_program)
    input_stream = FileStream("xml_program.el")
    lexer = EasyXMLLexer.EasyXMLLexer(input_stream)
    stream = CommonTokenStream(lexer)
    parser = EasyXMLParser.EasyXMLParser(stream)
    tree = parser.xml()
    if parser.getNumberOfSyntaxErrors():
        exit(1)
    visitor = MyVisitor()
    visitor.visit(tree)
    # visitor.root.print()
    checker = Checker(visitor.root)
    checker.check()
    xml_compile(visitor.root, xml_program)


if __name__ == '__main__':
    # if len(sys.argv) > 1:
    #     main(sys.argv[1])
    main('')
