#!/bin/bash
echo "test comment command"
echo "running ls -al# echo hello"
../rshell << EOF
ls -al# echo hello
exit
EOF
echo 
