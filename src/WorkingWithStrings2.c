char *copy_str(char *inStr, short len){
char *p=(char*)malloc(len+1);//Use malloc(Memory allocation)
short x=0;//Use a counter. I will define it as x.
while(*inStr!=len){//Read until the length we want to read.
	*(p+x)=*(inStr+x);
	x++;
}
return p;
}
void print_tokens(char** str){
while(*str!="\0"){//Read the string
printf("%s\n",*str);//Print the tokens. Cannot use return.
str++;//Keep printing
}
}
void free_tokens(char **str){
char**x=str;
while(*x!="\0"){//Read until the end of the row
free(*x);
x++;
}
printf("%c\n", x);//Print the function. Cannot use return.
}
