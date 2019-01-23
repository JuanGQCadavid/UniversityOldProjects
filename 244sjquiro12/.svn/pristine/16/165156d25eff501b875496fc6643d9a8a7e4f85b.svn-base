require 'parser'
require 'ast'

class Calculator
  attr_reader :memory
  attr_writer :memory
  
  def initialize()
    @memory = 0
  end
  
  def eval(expr)
    parser = Parser.new(StringIO.new(expr))
    ast = parser.parse()
    return ast.evaluate()
  end
end
