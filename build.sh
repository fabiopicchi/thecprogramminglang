if [[ ! -d build ]]; then
    mkdir build
fi
ls *.c | xargs basename -s .c | xargs -I name clang -Werror --pedantic-errors name.c -o build/name
