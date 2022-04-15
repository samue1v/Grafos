#!/bin/bash
for i in $(seq 0 119); do
  diff -s  saida$i.txt ../../solucoes/${i}_solucao.txt
done
