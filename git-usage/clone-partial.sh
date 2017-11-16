#!/bin/bash

$whole-project="https://github.com/johnbaik1118/workspace.git"
$sub-project="c-prog"

mkdir $sub-project
cd $sub-project
git init
git remote add origin '$whole-project' 
git config core.sparseCheckout true
echo "$sub-project/*" >> .git/info/sparse-checkout
git pull origin master
