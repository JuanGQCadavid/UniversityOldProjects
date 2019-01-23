package co.edu.eafit.dis.st0270.s20172.w7.visitor;

import co.edu.eafit.dis.st0270.javacalc.visitor.Visitor;

import co.edu.eafit.dis.st0270.javacalc.abstree.BinaryNode;
import co.edu.eafit.dis.st0270.javacalc.abstree.AddNode;
import co.edu.eafit.dis.st0270.javacalc.abstree.AssignNode;
import co.edu.eafit.dis.st0270.javacalc.abstree.ClearNode;
import co.edu.eafit.dis.st0270.javacalc.abstree.EpsilonNode;
import co.edu.eafit.dis.st0270.javacalc.abstree.FunctionNode;
import co.edu.eafit.dis.st0270.javacalc.abstree.MinusNode;
import co.edu.eafit.dis.st0270.javacalc.abstree.NumberNode;
import co.edu.eafit.dis.st0270.javacalc.abstree.PlusNode;
import co.edu.eafit.dis.st0270.javacalc.abstree.ProgNode;
import co.edu.eafit.dis.st0270.javacalc.abstree.RecallNode;
import co.edu.eafit.dis.st0270.javacalc.abstree.TimesNode;
import co.edu.eafit.dis.st0270.javacalc.abstree.ShiftLeftNode;
import co.edu.eafit.dis.st0270.javacalc.abstree.ShiftRightNode;
import co.edu.eafit.dis.st0270.javacalc.abstree.StoreNode;
import co.edu.eafit.dis.st0270.javacalc.abstree.SubNode;
import co.edu.eafit.dis.st0270.javacalc.abstree.DivideNode;
import co.edu.eafit.dis.st0270.javacalc.abstree.IdentifierNode;
import co.edu.eafit.dis.st0270.javacalc.abstree.StmsNode;
import java.util.Hashtable;
import java.io.*;
public class VisitorEvaluate implements Visitor {
    private int result = 0;
    private int memory = 0;
    private Hashtable<String,Integer> identifiers;

    private String out_F = "";
    
    private boolean f = false;
  
    public VisitorEvaluate(boolean f){
	//Set
	this.f = f;//Fichero
	identifiers = new Hashtable<String,Integer>();

    }
    public int getValue(){
	return this.result;
    }

    //Sin AST
    public void visit(ClearNode element){
	this.memory = 0;
    }

    public void visit(RecallNode element){
	this.result = memory;
    }
    public void visit(EpsilonNode element){
	printData(String.valueOf(getValue()));
	this.result = 0;
    }

    public void visit(IdentifierNode element){
	String key = element.getValue();
	int value = 0;

	if(identifiers.containsKey(key))
	    value = identifiers.get(element.getValue());
	
	this.result = value;
    }

    //Unary
    public void visit(ProgNode element){
	element.getSub().accept(this);
	EpsilonNode a = new EpsilonNode();
	a.accept(this);
	//	element.getSub().accept(this);
    }

    public void visit(NumberNode element){
	this.result = element.getValue();

    }

    public void visit(AssignNode element){
	String id = element.getId();
	this.result = 0;
	(element.getSub()).accept(this);
	identifiers.put(id,getValue());
	
    }
    
    public void visit(FunctionNode element){
	String key = element.getId();

	if(key.equals("swap")){
	    element.getSub().accept(this);
	    int result_temp = getValue();
	    this.memory = result_temp;
	    this.result = result_temp;
	    
	}else if(key.equals("min")){
	    element.getSub().accept(this);
	    int result_temp = getValue();

	    if(memory < result_temp){
		this.result = memory;
	    }else{
		this.result = result_temp;
	    }
	}else if(key.equals("max")){
	    element.getSub().accept(this);
	    int result_temp = getValue();

	    if(memory > result_temp){
		this.result = memory;
	    }else{
		this.result = result_temp;
	    }

	}
	
    }

    public void visit(PlusNode element){
	element.getSub().accept(this);
	this.memory = (memory + getValue());
    }
    
    public void visit(MinusNode element){
	element.getSub().accept(this);
	this.memory = (memory - getValue());
    }
    
    
    public void visit(StoreNode element){
	element.getSub().accept(this);
	this.memory = getValue();
    }

    //Binary

    //FALTA
    public void visit(StmsNode element){
	this.result = 0;
	
	int left = 0, rigth = 0;
	
	if( !((element.getLeft()).getClass().equals(EpsilonNode.class))){
	    element.getLeft().accept(this);
	    EpsilonNode a = new EpsilonNode();
	    a.accept(this);
	    //left = getValue();
	    //printData(String.valueOf(left));
	    
	}

	this.result = 0;
	    
	if( !((element.getRight()).getClass().equals(EpsilonNode.class))){
	    element.getRight().accept(this);

	    EpsilonNode a = new EpsilonNode();
	    a.accept(this);
	    //rigth = getValue();
	    //printData(String.valueOf(rigth));
	}

       

    }

    public void visit(AddNode element){
	binaryOperations('+', element);
    } 

    public void visit(SubNode element){
	binaryOperations('-', element); 
    }

    
    public void visit(TimesNode element){
	binaryOperations('*', element);
    }


    public void visit(DivideNode element){
	binaryOperations('/', element);
    }

    public void visit(ShiftLeftNode element){
	binaryOperations('<', element);
    }

    
    public void visit(ShiftRightNode element){
	binaryOperations('>', element);
    }

    public void binaryOperations(char operation, BinaryNode element){
	int tempResult = this.result;
	int rigth = 0,
	    left = 0;
	
	element.getLeft().accept(this);
	left = getValue();

	element.getRight().accept(this);
	rigth = getValue();

	switch(operation){
	case '+': //ADD    
	    this.result = (left + rigth) + tempResult;
	    break;

	case '-': //Sub
	    this.result = (left - rigth) + tempResult;
	    break;
	    
	case '*': //Times
	    this.result = (left * rigth) + tempResult;
	    break;

	case '/'://Divide
	    this.result = (left / rigth) + tempResult;
	    break;

	case '<'://Shift Left
	    this.result = (left << rigth) + tempResult;
	    break;

	case '>'://Shift Rigth
	    this.result = (left >> rigth) + tempResult;
	    break;

	default :
	    System.err.println("Invalid Character");
	    break;

	}
	
	

    }
    public void printData(String data_F){

	if(f){
	    out_F += "= "  + data_F + "\n"  ;
	}
	else{
	    System.out.println(" = " + data_F);
	}
	    
    }	
    public String getData_F(){
	return out_F;
    }
	
}
