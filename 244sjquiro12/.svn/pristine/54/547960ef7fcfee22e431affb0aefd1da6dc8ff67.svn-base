require 'ast'
require 'scanner'
require 'token'
require 'calcex'

class Parser
  def initialize(istream)
    @scan = Scanner.new(istream)
  end
   
  def parse()
    return Prog()
  end
  
  private
  def Prog()
    result = Expr()
    t = @scan.getToken()
    
    if t.type != :eof then
      print "Expected EOF. Found ", t.type, ".\n"
      raise ParseError.new
    end
    
    return result
  end
  
  def Expr() 
    return RestExpr(Term())
  end
   
  def RestExpr(e) 
    t = @scan.getToken()
    
    if t.type == :add then
         return RestExpr(AddNode.new(e,Term()))
    end
    
    if t.type == :sub then
      return RestExpr(SubNode.new(e,Term()))
    end
      
    @scan.putBackToken()
    
    return e
  end
  
  def Term()
    # Write your Term() code here. This code is just temporary
    # so you can try the calculator out before finishing it.
    
    t = @scan.getToken()
    
    if t.type == :number then
      val = t.lex.to_i
      return NumNode.new(val)
    end
    
    puts "Term not implemented\n"
    
    raise ParseError.new
  end
   
  def RestTerm(e)
    
    puts "RestTerm not implemented"
    raise ParseError.new # "Parse Error"
  end
   
  def Storable()
   
    puts "Storable not implemented"
    raise ParseError.new # "Parse Error"
  end
   
  def Factor() 
    
    puts "Factor not implemented"
    raise ParserError.new # "Parse Error"
  end         
end
