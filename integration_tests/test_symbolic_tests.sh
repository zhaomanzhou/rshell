#!/bin/bash
echo "test symbolic test"
echo "[ -d /etc ] && echo "path exists""
echo "[ -e test ] && echo "path exists""
echo "running............."
../rshell << EOF
[ -d /etc ] && echo "path exists"
[ -e test ] && echo "path exists"
exit
EOF
echo