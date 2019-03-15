#!/bin/bash
echo "test command test"
echo "test -e /etc && echo “path exists”"
echo "test -e test && echo "path exists""
../rshell << EOF
test -e /etc && echo "path exists"
test -e test && echo "path exists"
exit
EOF
echot