from enum import Enum
from termcolor import colored


class Exceptions(Enum):
    TYPE_ERROR = 'TypeError'
    NAME_ERROR = 'NameError'
    VALUE_ERROR = 'ValueError'
    ATTRIBUTE_ERROR = 'AttributeError'
    COMPILE_ERROR = 'CompileError'


def custom_exception(msg: str, line: int, column: int, error_type: Exceptions) -> None:
    print(colored(error_type.value + ': ' + msg + ' at ' + str(line) + ':' + str(column), 'red'))
    Checker.error_count += 1


class Checker:
    error_count = 0

    def __init__(self, tree):
        self.root = tree

    def check(self):
        self.root.check_vars_scope()
        self.root.check_type_cast()
        self.root.check_var_init_types()
        self.root.check_params_call()
        if Checker.error_count:
            exit(1)
