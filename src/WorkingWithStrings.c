	int space_char(char c){
	if(c==' '|| c=='\t' || c=='\n'){
		return 1;//1=true
	}
	else{
	return 0;//0=false
	}
}
	int non_space_char(char c){
	if(c== ' '|| c== '\t' || c=='\n'){
		return 0;//0=false
	}
	else{
	return 1;//1=true
	}
}
char *word_start(char *str){
	char c;
	char *p=str;//This will return the pointer
	while(*str!='\0'){//Read the entire string
		c=*p;
		if(c== ' '|| c== '\t' || c=='\n'){//If there is not a space, return pointer
		return p;
	}
	else{//If there is a space, keep going
	p++;
	}
	}
	return 0;//When there is no more to read, return 0
}
char *word_end(char *str){
	char c;
	char *p=str;//This will return the pointer
	while(*str!='\0'){//Read the entire string
		c=*p;
		if(c== ' '|| c== '\t' || c=='\n'){//If there is a space, return pointer
		p++;
	}
	else{//If there is not a space, keep going
	return p;
	}
	}
	return 0;//When there is no more to read, return 0
}
int count_words(char *str){
	char *p=str;
	int count=0;
	int i=0;
	while(*p!='\0'){
		if(*p==' ' || *p== '\t' || *p=='\n'){	
		count++;
		i++;
		}
		else{
		return 0;
		}
	}
	return count;
}
//int main(){
//	char c=getchar();
//	int a=space_char(c);
//	int b=non_space_char(c);	
//	printf("Is this char a space?\t %i",a);
//	printf("\n");
//	printf("Isn't this char a space?\t %i",b);
//	printf("\n");


//	char msg[4]="ARCH";
//	printf("%p\n", *word_end(msg));
// 	printf("%p\n", *word_start(msg));

//	char msg[4]="ARCH IS MY FAV CLASS";
//	printf("%i\n", count_words(msg));
//}
