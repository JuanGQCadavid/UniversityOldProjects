#!/usr/bin/ruby

require './hacercodificacion.rb'

$stdin.each do |l|
  l = l.chomp
  puts "#{hacerCodificacion l}"
end
