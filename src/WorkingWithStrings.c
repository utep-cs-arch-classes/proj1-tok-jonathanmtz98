#include <stdio.h>	
int space_char(char c){
	if(c==' '|| c=='\t' || c=='\n'){//If the first char is a space, a tab, or a jump of line...
		return 1;//Return 1=true in boolean
	}
	else{//If not...
	return 0;//Return 0=false in boolean
	}
}
	int non_space_char(char c){
	if(c== ' '|| c== '\t' || c=='\n'){//If the first char is a space, a tab, or a jump of line...
		return 0;//Return 0=false in boolean
	}
	else{//If not...
	return 1;//Return 1=true in boolean
	}
}
char *word_start(char *str){
	char *p=str;//This will return the pointer
	while(*p!='\0'){//Read the entire string until it is null
if(non_space_char(*p)==1){//If there is a nonspace char...
	return p;//Return pointer
}
else{//If not...
	p++;//Keep reading
}
}
	return 0;//When there is no more to read, return 0
}
char *word_end(char *str){
	char *p=str;//This will return the pointer
	while(*p!='\0'){//Read the entire string until it is null
if(space_char(*p)==1){//If there is a space char...
	return p;//Return pointer value
}
else{//If not...
	p++;//Keep reading
}
}
	return 0;//When there is no more to read, return 0
}
int count_words(char *str){//We need to use word start and word end
	int i=0;// This value will be updated to the number of words in the string, so it has to be initialized to 0
	char *p=str;//Update the string
	char *wordstart;// This will be used to invoke word_start method
	char *wordend;//This will be used to invoke word_end method
	while(*p!='\0'){//Read the entire string until it is null. \0= null in ASCII table
		wordstart=word_start(p);//Here we declare the word_start method. Why here? Because it is being declared while the loop is reading the string
		if(wordstart == 0){//If the string is empty...
		return i;//Return 0;
}
wordend=word_end(wordstart);//Here we declare the word_end method. It has wordstart as a variable since we need a *char as a variable to check when the loop finishes reading the string
if(*wordend=='\0'){//When the loop has arrived until the point is null...
	i++;//Count " ", "\t", and "\n" appearances. That's why the wordend method is useful.
	return i;//After finishing counting, return the number of appearances of space characters.
}
i++;//Keep going through the string
p=wordend;//Last step is to declare char *p as wordend
	}
}
//int main(){
//	char c=getchar();
//	int a=space_char(c);
//	int b=non_space_char(c);
//	printf("Is this char a space?\t");//This is additional in order to print TRUE or FALSE instead of 1 or 0
//	if(a==1){
//		printf("True");
//	}
//	else{
//		printf("False");
//}
//printf("\n Is this char a non space?\t");
//	if(b==1){
//		printf("True");
//	}
//	else{
//		printf("False");
//}
//	char msg[]="ARCH IS LIFE\0";
//	char msg2[]="Hello my name is \0";
//	printf("\nWord Start Pointer: %p", word_start(msg));//Print the pointer of word_start
//	printf("\nWord End Pointer: %p", word_end(msg));//Print the pointer of word_end
 //	printf("\nNumber of words: ");
 //	printf("%i",count_words(msg2));//Print the number of words	
//}
