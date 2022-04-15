#!/bin/bash
for i in $(seq 0 119); do
  cat ../../instancias/${i}_grafo.dl  | python3 conexo.py > saida$i.txt;
  diff -s  saida$i.txt ../../solucoes/${i}_solucao.txt;
done
