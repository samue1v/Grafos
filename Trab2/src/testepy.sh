#!/bin/bash
for i in $(seq 0 1); do
  cat instancias/${i}_grafo.dl  | python3 ideianova.py > saidas/saida$i.txt;
  #diff -s  saida$i.txt ../../solucoes/${i}_solucao.txt;
done
