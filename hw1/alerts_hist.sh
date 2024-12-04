#!/bin/bash
cat $1 > tmp1 
date=$2
sed -i 's#},{#\n#g' tmp1
grep $date tmp1 > tmp2
awk -F: '{print $2}' tmp2 | awk -F, '{print $1}' > tmp1
sed -i 's#"##g' tmp1
sort tmp1 | uniq -c | sort -nr > tmp2
sed -i 'G' tmp2
cat tmp2