#!/bin/bash
echo "test precedence"
echo "(echo A && echo B) || (echo C && echo D)"
echo "[ -e test ] && echo "path exists""
echo "running............."
../rshell << EOF
(echo A && echo B) || (echo C && echo D)
exit
EOF
echo