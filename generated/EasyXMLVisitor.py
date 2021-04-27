# Generated from EasyXML.g4 by ANTLR 4.9.1
from antlr4 import *
if __name__ is not None and "." in __name__:
    from .EasyXMLParser import EasyXMLParser
else:
    from EasyXMLParser import EasyXMLParser

# This class defines a complete generic visitor for a parse tree produced by EasyXMLParser.

class EasyXMLVisitor(ParseTreeVisitor):

    # Visit a parse tree produced by EasyXMLParser#var_init.
    def visitVar_init(self, ctx:EasyXMLParser.Var_initContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by EasyXMLParser#assignment.
    def visitAssignment(self, ctx:EasyXMLParser.AssignmentContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by EasyXMLParser#sum_assignment.
    def visitSum_assignment(self, ctx:EasyXMLParser.Sum_assignmentContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by EasyXMLParser#get.
    def visitGet(self, ctx:EasyXMLParser.GetContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by EasyXMLParser#get_array_element.
    def visitGet_array_element(self, ctx:EasyXMLParser.Get_array_elementContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by EasyXMLParser#func_call.
    def visitFunc_call(self, ctx:EasyXMLParser.Func_callContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by EasyXMLParser#if_statement.
    def visitIf_statement(self, ctx:EasyXMLParser.If_statementContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by EasyXMLParser#if_block.
    def visitIf_block(self, ctx:EasyXMLParser.If_blockContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by EasyXMLParser#else_if_block.
    def visitElse_if_block(self, ctx:EasyXMLParser.Else_if_blockContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by EasyXMLParser#else_block.
    def visitElse_block(self, ctx:EasyXMLParser.Else_blockContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by EasyXMLParser#for_statement.
    def visitFor_statement(self, ctx:EasyXMLParser.For_statementContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by EasyXMLParser#while_statement.
    def visitWhile_statement(self, ctx:EasyXMLParser.While_statementContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by EasyXMLParser#func_init.
    def visitFunc_init(self, ctx:EasyXMLParser.Func_initContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by EasyXMLParser#type_cast.
    def visitType_cast(self, ctx:EasyXMLParser.Type_castContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by EasyXMLParser#range_statement.
    def visitRange_statement(self, ctx:EasyXMLParser.Range_statementContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by EasyXMLParser#condition.
    def visitCondition(self, ctx:EasyXMLParser.ConditionContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by EasyXMLParser#params.
    def visitParams(self, ctx:EasyXMLParser.ParamsContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by EasyXMLParser#param.
    def visitParam(self, ctx:EasyXMLParser.ParamContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by EasyXMLParser#expression.
    def visitExpression(self, ctx:EasyXMLParser.ExpressionContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by EasyXMLParser#get_operation.
    def visitGet_operation(self, ctx:EasyXMLParser.Get_operationContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by EasyXMLParser#operation.
    def visitOperation(self, ctx:EasyXMLParser.OperationContext):
        return self.visitChildren(ctx)


    # Visit a parse tree produced by EasyXMLParser#xml.
    def visitXml(self, ctx:EasyXMLParser.XmlContext):
        return self.visitChildren(ctx)



del EasyXMLParser