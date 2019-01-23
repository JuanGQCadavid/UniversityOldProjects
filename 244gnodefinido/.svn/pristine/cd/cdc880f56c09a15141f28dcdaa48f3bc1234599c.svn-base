#include "ast.h"
#include <iostream>
#include "calculator.h"
#include "sstream"
using namespace std;
// for debug information uncomment
// #define debug

AST::AST() {}

AST::~AST() {}

BinaryNode::BinaryNode(AST* left, AST* right):
   AST(),
   leftTree(left),
   rightTree(right)

{}

BinaryNode::~BinaryNode() {
#ifdef debug
   cout << "In BinaryNode destructor" << endl;
#endif

   try {
      delete leftTree;
   } catch (...) {}

   try {
      delete rightTree;
   } catch(...) {}
}
   
AST* BinaryNode::getLeftSubTree() const {
  return leftTree;
}

AST* BinaryNode::getRightSubTree() const {
  return rightTree;
}

UnaryNode:: UnaryNode(AST* sub):
  AST(),
  subTree(sub)
{}

UnaryNode:: ~UnaryNode() {
#ifdef debug
   cout << "In UnaryNode destructor" << endl;
#endif

   try {
      delete subTree;
   } catch (...) {}
}
   
AST* UnaryNode:: getSubTree() const {
   return subTree;
}

AddNode::AddNode(AST* left, AST* right):
   BinaryNode(left, right)
{
  if(calc->getGenerarEwe()) {
    ostringstream out;

    out << "# Add" << endl;
    out << "  operator2 := M[sp+0]" << endl;
    out << "  operator1 := M[sp+1]" << endl;
    out << "  operator1 := operator1 + operator2" << endl;
    out << "  sp := sp + one" << endl;
    out << "  M[sp + 0] := operator1" << endl;

    //Guarda todo el flujo de out en un string
    string result = out.str(); 
    calc->write(result);
  }
}

int AddNode::evaluate() {
  try {

    //cout << getLeftSubTree()->evaluate() <<  "+"  << getRightSubTree()->evaluate() << endl;
    return getLeftSubTree()->evaluate() + getRightSubTree()->evaluate();
  }catch(int e) {
      cout << "Program Aborted due to exception!" << endl;
   }
}

SubNode::SubNode(AST* left, AST* right):
   BinaryNode(left,right)
{
  if(calc->getGenerarEwe()) {
    ostringstream out;

    out << "# Sub" << endl;
    out << "  operator2 := M[sp+0]" << endl;
    out << "  operator1 := M[sp+1]" << endl;
    out << "  operator1 := operator1 - operator2" << endl;
    out << "  sp := sp + one" << endl;
    out << "  M[sp + 0] := operator1" << endl;

    string result = out.str();
    calc->write(result);
  }
}

int SubNode::evaluate() {
    //cout << getLeftSubTree()->evaluate() <<  "-"  << getRightSubTree()->evaluate() << endl;
   return getLeftSubTree()->evaluate() - getRightSubTree()->evaluate();
}

TimesNode::TimesNode(AST* left, AST* right):
  BinaryNode(left,right)
{

  if(calc->getGenerarEwe()) {
    ostringstream out;

    out << "# Times" << endl;
    out << "  operator2 := M[sp+0]" << endl;
    out << "  operator1 := M[sp+1]" << endl;
    out << "  operator1 := operator1 * operator2" << endl;
    out << "  sp := sp + one" << endl;
    out << "  M[sp + 0] := operator1" << endl;

    //out.close();
    string result = out.str();
    calc->write(result);
  }
}

int TimesNode::evaluate(){
  //cout << getLeftSubTree()->evaluate() <<  "*"  << getRightSubTree()->evaluate() << endl;
  return getLeftSubTree()->evaluate() * getRightSubTree()->evaluate();
}

DivNode::DivNode(AST* left, AST* right):
  BinaryNode(left,right)
{
  if(calc->getGenerarEwe()) {
    ostringstream out;

    out << "# Divide" << endl;
    out << "  operator2 := M[sp+0]" << endl;
    out << "  operator1 := M[sp+1]" << endl;
    out << "  operator1 := operator1 / operator2" << endl;
    out << "  sp := sp + one" << endl;
    out << "  M[sp + 0] := operator1" << endl;

    string result = out.str();
    calc->write(result);
  }
}

int DivNode::evaluate(){
  //cout << getLeftSubTree()->evaluate() <<  "/"  << getRightSubTree()->evaluate() << endl;
  return getLeftSubTree()->evaluate() / getRightSubTree()->evaluate();
}

ModNode:: ModNode (AST* left, AST* right):
  BinaryNode(left, right)
{
  if(calc->getGenerarEwe()) {
    ostringstream out;

    out << "# Mod" << endl;
    out << "  operator1 := M[sp + 0]" << endl;
    out << "  operator2 := M[sp + 1]" << endl;
    out << "  operator1 := operator2 % operator1" << endl;
    out << "  sp := sp + one" << endl;
    out << "  M[sp + 0] := operator1" << endl;

    string result = out.str();
    calc->write(result);
  }
}

int ModNode:: evaluate() {
  //cout << getLeftSubTree()->evaluate() <<  " mod "  << getRightSubTree()->evaluate() << endl;
  return getLeftSubTree()->evaluate() % getRightSubTree()->evaluate();
}

StoreNode::StoreNode(AST* sub) :
  UnaryNode(sub)
{
  if(calc->getGenerarEwe()) {
    ostringstream out;

    out << "# Store" << endl;
    out << "  memory := M[sp+0]" << endl;

    string result = out.str();
    calc->write(result);
  }
}

int StoreNode::evaluate(){

  int result = getSubTree()->evaluate();
  calc->store(result);
  //cout << result << endl;
  return result;
}

PlusNode::PlusNode (AST* sub) :
  UnaryNode(sub)
{
  if(calc->getGenerarEwe()) {
    ostringstream out;

    out << "# Memory Minus" << endl;
    out << "  operator2 := M[sp+0]" << endl;
    out << "  memory := memory + operator2" << endl;
    out << "  M[sp+0] := memory" <<endl;

    //out.close();
    string result = out.str();
    calc->write(result);
  }
}

int PlusNode:: evaluate() {
  int result = getSubTree()->evaluate();
  calc->plus(result);
  //cout << result << endl;
  return calc->recall();
}

MinusNode:: MinusNode (AST* sub) : 
  UnaryNode(sub)
{
  if(calc->getGenerarEwe()) {
    ostringstream out;

    out << "# Memory Minus" << endl;
    out << "  operator2 := M[sp+0]" << endl;
    out << "  memory := memory - operator2" << endl;
    out << "  M[sp+0] := memory" <<endl;

    //out.close();
    string result = out.str();
    calc->write(result);
  }
}

int MinusNode:: evaluate() {
  int result = getSubTree()->evaluate();
  calc->minus(result); 
  //cout << result << endl;
  return calc->recall();
}

NegationNode:: NegationNode (AST* sub) : 
  UnaryNode(sub)
  {
    if(calc->getGenerarEwe()) {
      ostringstream out;

      out << "# Negation" << endl;
      out << "  operator1 := M[sp + 0]" << endl;
      out << "  operator1 := negative * operator1" << endl;
      out << "  M[sp + 0] := operator1" << endl;

      //out.close();
      string result = out.str();
      calc->write(result);
    }
  }

int NegationNode:: evaluate() {
  int result = getSubTree()->evaluate();
  //cout << result * (-1) << endl;
  return result * (-1);
}

RecallNode:: RecallNode() :
  AST()
{
  if(calc->getGenerarEwe()) {
    ostringstream out;

    out << "# Recall" << endl;
    out << "  sp := sp - one" << endl;
    out << "  M[sp + 0] := memory" << endl;

    //out.close();
    string result = out.str();
    calc->write(result);
  }
}

int RecallNode:: evaluate() {
  //cout << calc->recall() << endl;
  return calc->recall();
}

ClearNode:: ClearNode () : 
  AST()
{

  if(calc->getGenerarEwe()) {
    ostringstream out;

    out << "# Clear" << endl;
    out << "  memory := zero" << endl;
    out << "  sp := sp - one" << endl;
    out << "  M[sp + 0] := memory" <<endl;
    ///out.close();
    string result = out.str();
    calc->write(result);
  }
}

int ClearNode:: evaluate() {
  calc->clear(0);
  //cout << "entro a clear" << endl;
  return 0;
}

IdentifierNodo:: IdentifierNodo(string id) :
  AST(),
  val(id)
{

  if(calc->getGenerarEwe()) {
    ostringstream out;

    out << "# Push - Identifier ( " << id << " )" << endl;
    out << "  operator1 := " << id << endl;
    out << "  sp := sp - one" << endl;
    out << "  M[sp + 0] := operator1" << endl;

    //out.close
    string result = out.str();
    calc->write(result);
  }
}

int IdentifierNodo:: evaluate() {
  return calc->getBack(val);
}

assignationNode:: assignationNode(AST* sub, string lex):
  UnaryNode(sub)
  
{
  this->lex = lex;
  if(calc->getGenerarEwe()) {  
    ostringstream out;

    out << "# Assign" << endl;
    out << lex << " := M[sp + 0]" << endl;

    string result = out.str();
    calc->write(result);
  }
}

int assignationNode:: evaluate()  {
  int result = getSubTree()->evaluate();
  //cout<<"Añadiendo: "<<lex<<" valor "<<result<<endl;
  calc->add(lex, result);
  return result;
}

NumNode:: NumNode(int n) :
   AST(),
   val(n)
{
  if(calc->getGenerarEwe()) {
    ostringstream out;

    out << "# Push ( " << n << " )" << endl;
    out << "  sp := sp - one" << endl;
    out << "  operator1 := " << n << endl;
    out << "  M[sp + 0] := operator1" << endl;


    string result = out.str();
    calc->write(result);
  }
}

int NumNode:: evaluate() {
   return val;
}