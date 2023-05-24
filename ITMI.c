//idiots turing machine
#include <stdio.h> 
#include <conio.h>

int main(int argc, char** argv){
	FILE * file;
	file = fopen (argv[1], "r");
	char code[261];
	int tape[1024];
	int aa;
	int ac;
	int pointer = 1;
	int index = 0;
	int cicle = 0;
	fgets(code, 261, stdin);
	//if (file == NULL){
	//	return 1;
	//}
	while (1){
		switch (code[index]){
			case '>':
				if (pointer < 255 ){
					pointer++;
				} else{
					pointer = 0;
				}
				pointer++;
				break;
			case '<':
				if (pointer > 0 ){
					pointer--;
				} else {
					pointer = 255;
				};
				break;
			case '+':
				if (tape[pointer] > 255){
					tape[pointer] = 0;
				} else {
					tape[pointer] += 1;
				};
				break;
			case '*':
				if (tape[pointer] > 127){
					tape[pointer] = 0;
				} else {
					tape[pointer] *= 2;
				};
				break;
			case '-':
				if (tape[pointer] > 0){
					tape[pointer]--;
				} else {
					tape[pointer] = 255;
				};
				break;
			case '.':
				printf("%c", tape[pointer]);
				break;
			case ':':
				printf("%d \n", tape[pointer]);
				break;
			case ',':
				tape[pointer] = (int)getchar();
				break;
			case 'x':
				return 0;
			case '£':
				if (tape[pointer]  != 0){
					return 0;
				};
				break;
			case '$':
				if (tape[pointer]  == 0){
					return 0;
				};
				break;
			case '!':
				if (index < 260){
					index = index + 2;
				};
				break;
			case '@':
				if (index < 260){
					if (tape[pointer]  == 0){
						index += 1;
					} 
				};
				break;
			case '#':
				if (index < 260){
					if (tape[pointer]  != 0){
						index += 1;
					} 
				};
				break;
			case '¢':
				if (tape[pointer] < 261){
					index = tape[pointer];
				};
				break;
			case '0':
				index = 0;
				break;
		};
		// END SWITCH
		if (index > 260){
			index = 0;
		} else {
			index++;
		}
	};
	return 0;
}
