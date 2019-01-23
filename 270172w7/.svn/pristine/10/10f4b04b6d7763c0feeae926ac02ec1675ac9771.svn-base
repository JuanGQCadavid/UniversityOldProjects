package co.edu.eafit.dis.st0270.s20172.w7;

import gnu.getopt.Getopt;
import java_cup.runtime.*;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.io.FileReader;
import java.io.FileNotFoundException;
import co.edu.eafit.dis.st0270.s20172.w7.visitor.VisitorEvaluate;
import co.edu.eafit.dis.st0270.s20172.w7.parser.*;
import co.edu.eafit.dis.st0270.s20172.w7.lexer.*;
import co.edu.eafit.dis.st0270.javacalc.abstree.AbsTree;
public class App{
	
    public static void usage(){
	System.err.println("Usage: java App [-s] [-p] [-n] [-f] <fichero>");
	System.exit(1);

    }
    

    public static void main(String [] args) throws IOException{
	Getopt opciones = new Getopt("App", args, "s:p:n:f:");
	int contadorOpciones;
	String linea = null;
	while((contadorOpciones = opciones.getopt()) != -1){
	    switch(contadorOpciones){
	    case 's':
		{
		    linea = opciones.getOptarg();
		    int archivos = opciones.getOptind();
		    if(linea == null && archivos == args.length)usage();		    
		    for(int s = archivos; s < args.length; ++s){
			try{	    
			    W7Lexer lexer2 = new W7Lexer(new FileReader(args[s]));
			    W7Parser parser2 = new W7Parser(lexer2);
			    Symbol symbol2 = parser2.parse();
			    AbsTree tree2 = (AbsTree) symbol2.value; 
			    VisitorEvaluate ve2 = new VisitorEvaluate(true);
			    tree2.accept(ve2);
			    System.out.println(args[s]);
			    File archivo2 = new File("./"  + args[s]);
			    BufferedWriter bw2;
			    if(archivo2.exists()){
				archivo2.delete();
				bw2 = new BufferedWriter(new FileWriter(archivo2));
				bw2.write(lexer2.getCadena());
			    }else{
				bw2 = new BufferedWriter(new FileWriter(archivo2));
				bw2.write(lexer2.getCadena());
			    }
			    bw2.close();
			}catch(FileNotFoundException fnfe){
			    System.err.println("Fichero " + args[s] + "No existe");
			    System.exit(1);
			}catch(Exception e){
			    System.exit(1);
			}   
		    }
		}
		break;
	    case 'p':
		{
		    linea = opciones.getOptarg();
		    int archivos = opciones.getOptind();
		    if(linea == null && archivos == args.length)usage();
		    
		    for(int s = archivos; s < args.length; ++s){
			try{	    
			    W7Lexer lexer2 = new W7Lexer(new FileReader(args[s]));
			    W7Parser parser2 = new W7Parser(lexer2);
			    Symbol symbol2 = parser2.parse();
			    AbsTree tree2 = (AbsTree) symbol2.value; 
			    VisitorEvaluate ve2 = new VisitorEvaluate(false);
			    tree2.accept(ve2);
			    System.out.println("File: " + args[s] + "  Parser: True");
			}catch(FileNotFoundException fnfe){
			    System.err.println("Fichero " + args[s] + "No existe");
			    System.exit(1);
			}catch(Exception e){
			    System.err.println("File: " + args[s] + " Parser: False" );
			    System.exit(1);
			}
		    }
		}
		break;
	    case 'n':
		{
		    linea = opciones.getOptarg();
		    int archivos = opciones.getOptind();
		    if(linea == null && archivos == args.length)usage();
		    for(int s = archivos; s < args.length; ++s){
			try{
			    W7Lexer lexer2 = new W7Lexer(new FileReader(args[s]));
			    W7Parser parser2 = new W7Parser(lexer2);
			    try{
				Symbol symbol2 = parser2.parse();
				AbsTree tree2 = (AbsTree) symbol2.value; 
			    }catch(Exception e){
				System.out.println("Fichero " + args[s] + "Esta malo");
			    }
			}catch(FileNotFoundException fnfe){
			    System.err.println("Fichero " + args[s] + "No existe");
			    
			}catch(Exception e){
			    
			}
		    }
		}
		break;
	    case 'f':
		{
		    linea = opciones.getOptarg();
		    int archivos = opciones.getOptind();
		    if(linea == null && archivos == args.length)usage();		   
		    if(linea.equals("-s") || linea.equals("-n")||linea.equals("-p")){
			for(int s = archivos; s < args.length;s++){
			    if(!(args[s].equals("-s")) && !(args[s].equals("-p")) && !(args[s].equals("-n"))){
				linea = args[s];
				archivos =s;
				break;
			    }
			}
		    }
		    try{	    
			W7Lexer lexer = new W7Lexer(new FileReader(linea));
			W7Parser parser = new W7Parser(lexer);
			Symbol symbol = parser.parse();
			AbsTree tree = (AbsTree) symbol.value; 
			VisitorEvaluate ve = new VisitorEvaluate(true);
			tree.accept(ve);
			String extension  = linea.substring(linea.length()-3,linea.length());
			
			String extension2   = linea.substring(linea.length()-2,linea.length());
			System.out.println(linea);
			File archivo = new File("");
			System.out.println(extension + "  " +extension2);
			if(extension.equals("txt") || extension.equals("exp")){
			    archivo = new File("./"  + linea.substring(0,linea.length()-3) + "out");
			}else if(extension2.equals(".in")){
			    archivo = new File("./"  + linea.substring(0,linea.length()-2) + "out");
			}
			BufferedWriter bw;
			if(archivo.exists()){
			    archivo.delete();
			    bw = new BufferedWriter(new FileWriter(archivo));
			    bw.write(ve.getData_F());
			}else{
			    bw = new BufferedWriter(new FileWriter(archivo));
			    bw.write(ve.getData_F());
			}
			bw.close();
		    }catch(FileNotFoundException fnfe){
			System.err.println("Fichero " + linea + " No existe");
			System.exit(1);
		    }catch(Exception e){
			System.exit(1);
		    }
		    System.out.println("va en : "+ args[archivos] + " archivo");
		    for(int s = archivos; s < args.length; ++s){
			try{
			    System.out.println("as 9+ " + args[s]);
			    W7Lexer lexer2 = new W7Lexer(new FileReader(args[s]));
			    W7Parser parser2 = new W7Parser(lexer2);
			    Symbol symbol2 = parser2.parse();
			    AbsTree tree2 = (AbsTree) symbol2.value; 
			    VisitorEvaluate ve2 = new VisitorEvaluate(true);
			    tree2.accept(ve2);
			    String extension2  = args[s].substring(args[s].length()-3,args[s].length());
			
			    String extension21   = args[s].substring(args[s].length()-2,args[s].length());
			    File archivo2 = new File("");
			    System.out.println(linea);
			    if(extension2.equals("txt") || extension2.equals("exp")){
				archivo2 = new File("./"  + args[s].substring(0,linea.length()-3) + "out");
			    }else if(extension21.equals(".in")){
				archivo2 = new File("./"  + args[s].substring(0,linea.length()-2) + "out");
			    }
			    BufferedWriter bw2;
			    if(archivo2.exists()){
				archivo2.delete();
				bw2 = new BufferedWriter(new FileWriter(archivo2));
				bw2.write(ve2.getData_F());
			    }else{
				bw2 = new BufferedWriter(new FileWriter(archivo2));
				bw2.write(ve2.getData_F());
			    }
			    bw2.close();
			}catch(FileNotFoundException fnfe){
			    System.err.println("Fichero " + args[s] + " No existe");
			    System.exit(1);
			}catch(Exception e){
			    System.exit(1);
			}  
			
		    }
		    
		}
		break;
	    }
	    System.exit(0);
	}
    }
}
