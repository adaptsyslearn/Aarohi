#!/bin/bash

##### Algo. 1: Takes FCList.txt and generates RuleList for Algo.2 #####
##### Run: bash algo1.sh FCList #######################################

#Step 1 Enumeration
file=$1
awk -F" " '{print $1}' $file | sort | uniq  > TestID.txt 
perl -e "s/^[[:space:]]*//" -pi "TestID.txt" 
[ -e TestIDfile1.txt ] && rm TestIDfile1.txt

[ -e RuleList.txt ] && rm RuleList.txt

ID=100 # Starting ID
N=1 # Filecount
while read phrase; do
	#echo "Phrase is $phrase"
        echo "$ID	P$ID" >> TestIDfile1.txt
        ID=$(expr "$ID" + 1)
done < TestID.txt
echo -e "ID count is $ID \n" >> RuleList.txt
N=$(expr "$N" + 1)

paste TestID.txt TestIDfile1.txt > FCToken.txt
#perl -e "s/^[[:space:]]*//" -pi "FCToken.txt" 

#Step 2 Tokenization 
[ -e FCTokenList.txt ] && rm FCTokenList.txt
#while read phrase; do
        #echo "Phrase is $phrase"
#        echo "P$phrase" >> FCTokenList.txt
#done < TestIDfile1.txt

#Step Formulate Chain Rules from FCs 

R=0
RF=0
while IFS= read -r line; do
	#echo "$line"
	if [ -z "$line" ] ; then
                #echo "Empty Line, Skip \n" >> RuleList$RF.txt
                R=$(expr "$R" + 1)
                echo -e "\n Rule $R \n" >> RuleList.txt
                RF=$(expr "$RF" + 1)
                continue
	else
		TokenID=$(grep "$line" FCToken.txt | awk -F" " '{print $3}')
        	#echo -n "$TokenID " >> RuleList$RF.txt 
        	echo -n "$TokenID error " >> RuleList.txt 
        fi
done < FCList.txt
echo -e "\n" >> RuleList.txt
echo "No. of rules are $R" >> RuleList.txt

rm TestIDfile1.txt  TestID.txt FCToken.txt
