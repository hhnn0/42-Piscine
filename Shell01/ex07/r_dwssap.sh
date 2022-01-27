#!/bin/bash

cat /etc/passwd | grep -v "#" | awk "NR%2==0" | cut -d ':' -f1 | rev | sort -r | awk -v L1=$FT_LINE1 -v L2=$FT_LINE2 "L1 <= NR && NR<=L2" | tr '\n', ',' |  sed 's/.$/./' | sed 's/,/, /g' | tr -d '\n'
