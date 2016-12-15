#!/bin/bash

for nr in $(seq 22 27);do
	./parallel_train.sh 1
	mv data_mt.net data_mt.net$nr
done
ls -ltr
