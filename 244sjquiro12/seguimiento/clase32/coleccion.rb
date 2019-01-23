
#Arreglo
arr = [1,2,3]

#POtra forma

arr2 = Array.new 3  #Tres espacios al principo.
arr2<<1
arr2<<2
arr2<<3


#Iterar cada uno de llos

#arr.each {|e| puts e if e.odd?; puts "#{e * 10}" if.even?}

arr2.each do |e|
  puts e if e.even?
  puts "#{e * 30}" if e.odd?
end

10.times{|e| puts n}



