find . -name "*.sh" -type f -exec basename {} \; | sed "s/\.sh$//g"
