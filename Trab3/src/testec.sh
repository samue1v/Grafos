#!/bin/bash
for i in $(seq 0 24); do
  cat ../instancias/${i}.in | ./498844  > ../saidas/saida${i}.txt;
  diff -s  ../saidas/saida${i}.txt ../instancias/${i}.out;
done
