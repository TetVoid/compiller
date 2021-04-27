from ast_tree.nodes import *
import os


xml_program_includes = '''#include <iostream>
#include <vector>
#include "runtime.h"

using namespace std;

'''
xml_program_main = '''
int main(){
'''


def xml_compile(root: Node, xml_program_path: str) -> None:
    pack_program(root, xml_program_path)
    # os.system('g++ ' + 'RunTime/xml_program.cpp RunTime/runtime.cpp RunTime/pugixml-1.11/src/pugixml.cpp -o ' + xml_program_path.split('.')[0] + '.exe')
    os.system('g++ RunTime/xml_program.cpp RunTime/runtime.cpp RunTime/pugixml-1.11/src/pugixml.cpp -o xml_program.exe')


def pack_program(root: Node, xml_program: str) -> None:
    global xml_program_includes
    with open("RunTime/xml_program.cpp", 'w') as xml_program_file:
        xml_program_file.write(xml_program_includes)
        xml_program_file.write(root.generate()[1])
        xml_program_file.write(xml_program_main)
        # xml_program_file.write('int a;\n')
        xml_program_file.write(root.generate()[0])
        xml_program_file.write('\n}')
