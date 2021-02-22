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

int main(){
	char c=getchar();;
	int a=space_char(c);;
	int b=non_space_char(c);
	
	printf("Is this char a space?\t %i",a);
	printf("\n");
	printf("Isn't this char a space?\t %i",b);
	printf("\n");
}
