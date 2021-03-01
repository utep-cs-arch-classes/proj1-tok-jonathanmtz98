char *copy_str(char *inStr, short len){
char *p=(char*)malloc(len+1);
short x=0;
while(*inStr!=len){
	*(p+x)=*(inStr+x);
	x++;
}
return p;
}
void print_tokens(char** str){
while(*str!="\0"){
printf("%s\n",*str);
str++;
}
}
