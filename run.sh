### Compile data.c as well because it's a header file,
### we need it compiled beforehand

gcc main.c src/data/data.c -o release/bds 