#!/bin/bash
for i in $(seq 0 24); do
  cat instancias_de_teste/${i}.in | python3 498844_trab2.py > saidas/saida${i}.txt;
  diff -s  saidas/saida${i}.txt instancias_de_teste/${i}.out;
done
