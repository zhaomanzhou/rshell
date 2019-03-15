#!/bin/bash
echo "test single command"
echo "running ls -al"
../rshell << EOF
ls -al
exit
EOF
echo 
