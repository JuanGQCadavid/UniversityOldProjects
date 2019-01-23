#!/usr/bin/ruby

  def hacerCodificacion(texto)
    i = texto.length - 1
    nuevoTexto = ""

    while i >= 0 do
      if texto[i] == texto[i].downcase then
        nuevoTexto += texto[i].upcase
      else
        nuevoTexto += texto[i].downcase
      end
      i-=1
    end
    puts nuevoTexto
  end
