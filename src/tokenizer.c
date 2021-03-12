#include <stdio.h>
#include <stdlib.h>
#include <tokenizer.h>

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
char *copy_str(char *inStr, short len){
char *p=(char*)malloc(len+1);//To do this method, I need to use malloc(Memory allocation)
short x=0;//This is a counter that will help me to print a specific number of chars(iterator). I will define it as x.
while(x!=len){//Read until x is equal to the length I want to read.
	*(p+x)=*(inStr+x);//Update the string to the one I want to.
	x++;//Variable x has to keep going until it reaches the length we want.
}
*(p+len)='\0';//Recently added to avoid random chars to be printed. 
//First, when I asked to print a specific number of chars, they were printed, but after it, random emojis and chars were printed. This help to stop that since we are declaring it as null.
return p;//Return the chars we asked for.
}

char **tokenize(char *str){
int words=count_words(str);//To tokenize, I need to have the number of words the string has as reference in order to make the work easier
int i=0;//We need an iterator.
char *p=str;//This will take the place of str.
char *wordstart, *wordend;//As done in milestone 2, I need word_start and word_end functions. They are important since it will give me the length of the string
char **mem=(char**)malloc(sizeof(char*)*(words+1));//Malloc. It includes the count_words because I need the number of words the string has.
while(i!=words){//Read until I reach the number of words
	wordstart=word_start(p);//Here, like in milestone 2, I need to have word_start as reference.
	wordend=word_end(wordstart);//The same with wordend. I will use those functions to know the length(no. of tokens) I will have.
	*(mem+i)=copy_str(wordstart,wordend-wordstart);//Here I used copy_str because we need to print the tokens. It helps to separate them.
	p=wordend;//Here pointer p is declared as wordend.
	i++;
}
*(mem+words)='\0';//As done in the copy_str, I need to include this in order to avoid random chars to appear. It is known as terminating null character.
return mem;//Finally, return the tokens, but we need print_tokens function to print them.
}

void free_tokens(char **tokens){
  int i = 0; //Keep track of the tokens
  while (tokens[i]) { //Read the tokens
    free(tokens[i]); // Deallocate memory
    i++; // Keep reading tokens
  }
  free(tokens); // free the tokens
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
//char msg3[]="ARCH IS FUN";
	//char *ptr;
	//ptr=msg3;
	//char *p=copy_str(ptr,2);
	//while(*p!=0){
	//	printf("%c\n",*p);
	//	p++;
	//}
//}
