#!/bin/bash
for i in $(seq 0 15); do
  cat ../instancias/${i}.in | 498844.exe  > ../saidas/saida${i}.txt;
  diff -s  ../saidas/saida${i}.txt ../instancias/${i}.out;
done
