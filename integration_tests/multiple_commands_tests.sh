#!/bin/bash
echo "test multi command"
echo "running ls -al; echo hello && git status"
../rshell << EOF
ls -al; echo hello && git status
exit
EOF
echo -e "\n\n\n"

echo "running ls -al || echo hello && git status"
../rshell << EOF
ls -al || echo hello && git status
exit
EOF
echo -e "\n\n\n"

echo "running ls -al && echod hello && git status"
../rshell << EOF
ls -al && echod hello && git status
exit
EOF

echo "terminal"
