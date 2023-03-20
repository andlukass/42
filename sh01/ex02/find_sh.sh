find . -name "*.sh" | sed 's_.*/::' | sed 's/\.[^.]*$//'
