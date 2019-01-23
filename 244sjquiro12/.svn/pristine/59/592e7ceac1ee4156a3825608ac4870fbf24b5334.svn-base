#!/usr/bin/ruby

class Secuenciador
  
  attr_accessor :secCorrectas
  attr_accessor :secIncorrectas
  attr_accessor :adenina
  attr_accessor :citocina
  
  def initialize
    @secCorrectas = 0
    @secIncorrectas = 0
    @adenina = 0
    @citocina = 0
  end

  def eventoAdenina
    @adenina += 1
  end

  def eventoCitocina
    if @adenina.odd? then
      @secIncorrectas += 1
    else
      @secCorrectas += 1
    end
    @adenina = 0

  end
end
