#!/bin/bash
echo "running exit"
../rshell <<< 'exit'
result=$?
echo "return value: $result"
