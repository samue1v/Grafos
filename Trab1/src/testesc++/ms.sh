#!/bin/bash
for i in $(seq 0 119); do
  cat ../../instancias/${i}_grafo.dl  | .././main2 > saida$i.txt
done
