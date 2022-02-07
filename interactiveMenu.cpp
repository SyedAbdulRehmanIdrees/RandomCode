#include <iostream>
#include <conio.h>
using namespace std;

int getArrowKey();
int getUpDown();
int showInteractiveMenu();

int main(){
    cout << showInteractiveMenu() << endl;
}

int showInteractiveMenu(){
    string option[] = {"Admin", "User", "Customer", "Exit"};
    int len = sizeof(option)/sizeof(option[0]);
    int current = 0;
    int x = 0;

    while(true){
        system("cls");
        for(int i = 0; i < len; i++){
            cout << i + 1 << ". " << option[i];

            if(i == current){
                cout << " <----";
            }

            cout << endl;
        }

        x = getUpDown();

        if(x == 0){
            break;
        }
        else {
            current = (current + x) % len;
        }
    }

    return current;
}

int getUpDown(){
    int i = getArrowKey();

    while(i != 72 && i != 80 && i != 13 && i != 3){
        i = getArrowKey();
    }

    if(i == 80){ // UP
        return 1;
    }
    else if(i == 72){ // DOWN
        return -1;
    }
    else if(i == 13 || i == 3){ // ENTER AND CTRL + C
        return 0;
    }
}

int getArrowKey(){
    char c = _getch();
    if(!c){
        return _getch();
    }

    return c;
}
