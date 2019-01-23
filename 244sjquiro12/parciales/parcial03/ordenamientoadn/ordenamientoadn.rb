#!/usr/bin/ruby
require './secuenciador.rb'

secuenciador= Secuenciador.new

$stdin.each do |l|
  case l.chomp
  when /[aA]/
    secuenciador.eventoAdenina
  when /[cC]/
    secuenciador.eventoCitocina
  end
end

puts "#{secuenciador.secCorrectas} #{secuenciador.secIncorrectas}"
