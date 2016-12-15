#!/bin/bash
for file in $(ls circle/*);do ./create_learn_nonl.pl $file data.learn 0 10000;done
for file in $(ls square/*);do ./create_learn_nonl.pl $file data.learn 1 10000;done
