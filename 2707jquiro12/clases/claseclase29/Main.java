import java_cup.runtime.*;
import java.io.FileReader;
import java.io.FileNotFoundException;

public class Main{

    public static void main(String args [ ]){
	if(args.length != 1 ){
	    System.err.println("Uso: Main <fichero>");
	    System.exit(1);
	}
	try{
	    DyckScanner scanner = new DyckScanner(new FileReader(args[0]));
	    DyckParser parser = new DyckParser(scanner);

	    parser.parse();

	}catch(FileNotFoundException fnfe){
	    System.err.println("Fichero: " + args[0] + " No Existe");
	    System.exit(1);
	}catch(Exception e){
	    System.err.println(e);
	    System.exit(1);
	}
	    
	System.exit(0);
    }
    

    
}
