# RIT
"(ROGUELIKE)INDIAN TALES" bare-bones roguelike, fully writen in pure C, only using standard libs and ncurses.
roguelike totalmente em portugues, "Contos Indianos, Roguelike".

compile: 

requirements : build-essential, gcc, clang, ncurses-dev, git

git clone https://github.com/jardimdanificado/RIT.git
cd RIT
gcc main.c -o main -lncurses
./main
