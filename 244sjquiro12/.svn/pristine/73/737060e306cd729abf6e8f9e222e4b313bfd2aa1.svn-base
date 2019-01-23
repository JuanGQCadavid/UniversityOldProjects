#!/usr/bin/env ruby

class Echo
  #attr_reader :saludo #Este me hace los getter
  ###attr_writer :saludo #Este me hace los setters

  attr_accessor :saludo #este me hace los getters an setters
  
  #def initialize()
   # @saludo = "Hola mis juates" #Este es un atributo
  #end

  def initialize(saludo)
    @saludo = saludo;
  end

  def doEcho
    s = gets
    puts"#{saludo + ' ' + s}" #este es para volver a llamar al evaluador de ruby de instrucciones desde ruby
  end
  
end

miecho = Echo.new
