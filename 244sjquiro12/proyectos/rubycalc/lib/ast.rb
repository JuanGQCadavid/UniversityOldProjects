require 'set'

class BinaryNode
  attr_reader :left, :right
  
  def initialize(left,right)
    @left = left
    @right = right
  end
end
   
class UnaryNode
  attr_reader :subTree
   
  def initialize(subTree)
    @subTree = subTree
  end
end

class AddNode < BinaryNode
  def initialize(left, right)
    super(left,right)
  end
   
  def evaluate() 
    return @left.evaluate() + @right.evaluate()
  end
end

class SubNode < BinaryNode
  def initialize(left, right)
    super(left,right)
  end
   
  def evaluate() 
    return @left.evaluate() - @right.evaluate()
  end
end
      
class NumNode 
  def initialize(num)
    @num = num
  end
   
  def evaluate() 
    return @num
  end
end
