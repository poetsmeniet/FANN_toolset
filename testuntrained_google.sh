#!/bin/bash
if [ ! $1 ];then
	echo "Usage: testuntrained.sh data.net"
	exit 1
fi
totalCnt=0
totalErrs=0
errs=0;for file in $(ls google_square/*);do ((totalCnt+=1));if [ $(./exec_test_1answer.o $file $1|grep -c square) == 1 ];then echo "Correct, is a square";else echo "Wrong ($file is not a $(./exec_test_1answer.o $file $1))";let errs=errs+1;fi ;done;echo "We have ${errs} errs"
let totalErrs=totalErrs+errs;
errs=0;for file in $(ls google_circle/*);do ((totalCnt+=1)); if [ $(./exec_test_1answer.o $file $1|grep -c circle) == 1 ];then echo "Correct, is a circle";else echo "Wrong ($file) is not a $(./exec_test_1answer.o $file $1)";let errs=errs+1;fi ;done;echo "We have ${errs} errs"
let totalErrs=totalErrs+errs;
errs=0;for file in $(ls google_triangle/*);do ((totalCnt+=1)); if [ $(./exec_test_1answer.o $file $1|grep -c triangle) == 1 ];then echo "Correct, is a triangle";else echo "Wrong ($file is not a $(./exec_test_1answer.o $file $1))";let errs=errs+1;fi ;done;echo "We have ${errs} errs"
let totalErrs=totalErrs+errs;
printf "Tested ${totalCnt} files, with ${totalErrs} errors. Accuracy is aproximately $(echo "100-((${totalErrs}/${totalCnt})*100)"|bc -l)\n"
exit 0
