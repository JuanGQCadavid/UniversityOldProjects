#!/bin/bash

if [ "$#" = "0" ]
then
    mvn exec:java -Dexec.mainClass="co.edu.eafit.dis.st0270.s20172.w7.App" -Dexec.args=" -f examples/prueba1.txt examples/prueba1.txt"
else
    mvn clean
    mvn compile
    mvn exec:java -Dexec.mainClass="co.edu.eafit.dis.st0270.s20172.w7.App" -Dexec.args=" -f -s examples/prueba3.txt examples/prueba1.txt"
fi
