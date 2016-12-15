#!/bin/bash
for file in $(ls square/*|head -10);do ./create_learn_nonl.pl $file data.learn 0 10000;done
for file in $(ls circle/*|head -10);do ./create_learn_nonl.pl $file data.learn 1 10000;done
for file in $(ls triangle/*|head -10);do ./create_learn_nonl.pl $file data.learn 2 10000;done
